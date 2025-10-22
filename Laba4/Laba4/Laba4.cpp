#include <iostream>
#include <array>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    std::cout << '1' << std::endl;
    int arr[10];
    for (int i = 0; i < std::size(arr); ++i) {
        std::cin >> arr[i];
    }
    if (arr[0] > arr[9]) {
        for (int i = 0; i < 9; ++i) {
            for (int j = i + 1; j < 10; ++j) {
                if (arr[j] > arr[i]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }
    for (int i = 0; i < std::size(arr); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '2' << std::endl;
    int matrix[3][4], maxsum = 0, n, j, sum_0 = 0, sum_1 = 0, sum_2 = 0, sum_3 = 0;
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            std::cout << "Введите элемент " << i + 1 << " строки и " << j + 1 << " столбца: ";
            std::cin >> matrix[i][j];
            std::cout << '\n';
            switch (j) {
            case 0: sum_0 += matrix[i][j]; break;
            case 1: sum_1 += matrix[i][j]; break;
            case 2: sum_2 += matrix[i][j]; break;
            case 3: sum_3 += matrix[i][j]; break;
            }
        }
    }
    maxsum = max(max(sum_0, sum_1), max(sum_2, sum_3));
    if (sum_0 == maxsum) {
        n = 0;
    }
    else if (sum_1 == maxsum) {
        n = 1;
    }
    else if (sum_2 == maxsum) {
        n = 2;
    }
    else if (sum_3 == maxsum) {
        n = 3;
    }
    for (int i = 0; i < 3; ++i) {
        matrix[i][n] = 0;
    }
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}