#include <iostream>
#include <array>
#include <windows.h>
#include <limits>

int main()
{
    SetConsoleOutputCP(1251);
    std::cout << "Пункт 1" << std::endl;
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }
    if (arr[0] > arr[9]) {
        for (int i = 0; i < 9; ++i) {
            for (int j = i + 1; j < 10; ++j) {
                if (arr[j] < arr[i]) {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << ' ';
    }
    
    std::cout << "\n Пункт 2" << std::endl;
    int matrix[3][4], n, j, sum[4] = {0,0,0,0}, maxsum = std::numeric_limits<int>::lowest();
    for (int i = 0; i < 3; ++i) {
        for (j = 0; j < 4; ++j) {
            std::cout << "Введите элемент " << i + 1 << " строки и " << j + 1 << " столбца: ";
            std::cin >> matrix[i][j];
            std::cout << '\n';
            sum[j] += matrix[i][j];
        }
    }
    for (j = 0; j < 4; ++j) {
        if (sum[j] > maxsum) {
            maxsum = sum[j];
            n = j;
        }
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