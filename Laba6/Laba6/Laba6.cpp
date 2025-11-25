#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	int** matrix = (int**)malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; ++i)
		matrix[i] = (int*)malloc(2 * sizeof(int));
	std::cout << "@";
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j)
			std::cin >> matrix[i][j];
	}
	std::cout << "@";
	matrix = (int**)realloc(matrix, (2 + matrix[0][0]) * sizeof(int*));
	matrix[0] = (int*)realloc(matrix,(1 + matrix[0][1]) * sizeof(int));
	for (int i = 2; i < 2 + matrix[0][0]; ++i)
		matrix[i] = (int*)malloc((2 + matrix[0][1]) * sizeof(int));
	
	std::cout << "@";
	for (int i = 0; i < 2 + matrix[0][0]; ++i) {
		for (int j = 0; j < 2 + matrix[0][1]; ++j)
			std::cin >> matrix[i][j];
	}
	std::cout << "@";
	for (int i = 0; i < 2 + matrix[0][0]; ++i) {
		for (int j = 0; j < 2 + matrix[0][1]; ++j)
			std::cout << matrix[i][j] << ' ';
		std::cout << '\n';
	}
	for (int i = 0; i < 2; ++i)
		free(matrix[i]);
	free(matrix);
	/*
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j)
			std::cin >> matrix[i][j];
	}
	for (int i = 2; i < 2 + matrix[0][0]; ++i) {
		for (int j = 2; j < 2 + matrix[0][1]; ++j) {
			if (i < 2 && j < 2) {
				**pmatrix2[i][j] == matrix[i][j];
			}
			matrix[i][j] == (matrix[1][0] - (i - sizeof(pmatrix2)/ sizeof(pmatrix2[0])) +
		}
	}
	for (int i = 0; i < 2 + matrix[0][0]; ++i) {
		for (int j = 0; j < 2 + matrix[0][1]; ++j)
			std::cout << **pmatrix2[i][j] << ' ';
		std::cout << '\n';
	}
	*/
}
