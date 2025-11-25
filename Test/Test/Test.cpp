#include <iostream>
#include <cstdlib>   // malloc, calloc, realloc, free, exit
#include <cstring>   // (необязательно, но оставлено)
#include <iomanip>   // setw
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

// Выделяет rows x cols и инициализирует нулями.
int** allocate_matrix(int rows, int cols) {
    int** mat = (int**)malloc(rows * sizeof(int*));
    if (!mat) {
        cerr << "Allocation failed for row pointers\n";
        exit(EXIT_FAILURE);
    }
    for (int r = 0; r < rows; ++r) {
        mat[r] = (int*)calloc(cols, sizeof(int)); // calloc инициализирует нулями
        if (!mat[r]) {
            cerr << "Allocation failed for row " << r << "\n";
            for (int i = 0; i < r; ++i) free(mat[i]);
            free(mat);
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

// Освобождает матрицу
void free_matrix(int** mat, int rows) {
    if (!mat) return;
    for (int r = 0; r < rows; ++r) {
        free(mat[r]);
    }
    free(mat);
}

// Находит индексы столбцов, содержащих хотя бы один 0.
// Возвращает динамический массив индексов; количество через out_count.
int* find_zero_columns(int** mat, int rows, int cols, int* out_count) {
    if (cols <= 0 || rows <= 0) {
        *out_count = 0;
        return NULL;
    }

    char* mark = (char*)calloc(cols, sizeof(char)); // пометки столбцов
    if (!mark) {
        cerr << "Allocation failed for mark\n";
        exit(EXIT_FAILURE);
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (mat[r][c] == 0) mark[c] = 1;
        }
    }

    int count = 0;
    for (int c = 0; c < cols; ++c) if (mark[c]) ++count;

    if (count == 0) {
        free(mark);
        *out_count = 0;
        return NULL;
    }

    int* indices = (int*)malloc(count * sizeof(int));
    if (!indices) {
        cerr << "Allocation failed for indices\n";
        free(mark);
        exit(EXIT_FAILURE);
    }

    int idx = 0;
    for (int c = 0; c < cols; ++c) {
        if (mark[c]) indices[idx++] = c;
    }

    // Для демонстрации realloc (необязательное уменьшение):
    if (idx != count) {
        int* tmp = (int*)realloc(indices, idx * sizeof(int));
        if (tmp) indices = tmp;
    }

    free(mark);
    *out_count = count;
    return indices;
}

// Удаляет столбцы с индексами из cols_to_remove[0..remove_count-1]
// Обновляет значение *cols_ptr.
void remove_columns(int** mat, int rows, int* cols_ptr, int* cols_to_remove, int remove_count) {
    if (remove_count <= 0) return;

    int cols = *cols_ptr;
    char* del = (char*)calloc(cols, sizeof(char));
    if (!del) {
        cerr << "Allocation failed for del\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < remove_count; ++i) {
        int c = cols_to_remove[i];
        if (c >= 0 && c < cols) del[c] = 1;
    }

    int new_cols = 0;
    for (int c = 0; c < cols; ++c) if (!del[c]) ++new_cols;

    for (int r = 0; r < rows; ++r) {
        if (new_cols == 0) {
            free(mat[r]);
            mat[r] = NULL;
            continue;
        }
        int* new_row = (int*)malloc(new_cols * sizeof(int));
        if (!new_row) {
            cerr << "Allocation failed for new_row\n";
            free(del);
            exit(EXIT_FAILURE);
        }
        int pos = 0;
        for (int c = 0; c < cols; ++c) {
            if (!del[c]) {
                new_row[pos++] = mat[r][c];
            }
        }
        free(mat[r]);
        mat[r] = new_row;
    }

    free(del);
    *cols_ptr = new_cols;
}

// Вывод матрицы
void print_matrix(int** mat, int rows, int cols) {
    cout << "Matrix (" << rows << " x " << cols << "):\n";
    for (int r = 0; r < rows; ++r) {
        if (cols == 0) {
            cout << "(empty row)\n";
            continue;
        }
        for (int c = 0; c < cols; ++c) {
            cout << setw(6) << mat[r][c];
        }
        cout << "\n";
    }
    cout << endl;
}

int main() {
    // Устанавливаем кодовую страницу консоли для корректного вывода кириллицы в Windows
    SetConsoleOutputCP(1251);

    // Вводим 2x2 матрицу — в ней находятся параметры A, B, C, D
    // (строка 0: A B, строка 1: C D)
    cout << "Введите 4 целых числа для исходной матрицы 2x2 (A B в первой строке, C D во второй):\n";
    int a00, a01, a10, a11;
    if (!(cin >> a00 >> a01 >> a10 >> a11)) {
        cerr << "Ошибка ввода\n";
        return 1;
    }

    // Интерпретируем введённые значения как параметры:
    int A = a00; // сколько строк добавить
    int B = a01; // сколько столбцов добавить
    int C = a10; // коэффициент C
    int D = a11; // коэффициент D

    if (A < 0) A = 0;
    if (B < 0) B = 0;

    int rows = 2 + A;
    int cols = 2 + B;

    // Выделяем матрицу rows x cols, все элементы нулевые
    int** mat = allocate_matrix(rows, cols);

    // Первые 2x2 — это сами A,B,C,D (как указано в задании)
    mat[0][0] = A;
    mat[0][1] = B;
    mat[1][0] = C;
    mat[1][1] = D;

    // Заполняем остальные элементы по формуле:
    // value = (r - 1) * C + (c - 1) * D
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r < 2 && c < 2) continue; // первые 2x2 оставляем как введено
            mat[r][c] = (r - 1) * C + (c - 1) * D;
        }
    }

    cout << "\nСформированная матрица до удаления столбцов:\n";
    print_matrix(mat, rows, cols);

    int remove_count = 0;
    int* remove_cols = find_zero_columns(mat, rows, cols, &remove_count);

    if (remove_count == 0) {
        cout << "Нет столбцов, содержащих 0. Ничего не удалено.\n";
    }
    else {
        cout << "Найдены столбцы с нулевыми элементами (индексы столбцов): ";
        for (int i = 0; i < remove_count; ++i) {
            cout << remove_cols[i] << (i + 1 == remove_count ? "\n" : ", ");
        }

        remove_columns(mat, rows, &cols, remove_cols, remove_count);
        free(remove_cols);

        cout << "\nМатрица после удаления столбцов:\n";
        print_matrix(mat, rows, cols);
    }

    free_matrix(mat, rows);
    return 0;
}
