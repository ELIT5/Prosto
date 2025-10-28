#include <iostream>
#include <windows.h>

void Sredn(float a, float b) {
	std::cout << "Среднее значение двух чисел: " << (a + b) / 2;
}
void Sredn(float a, float b, float c) {
	std::cout << "Среднее значение трёх чисел: " << (a + b + c) / 3;
}
void SearchSredn(float a, float b, float c) {
	if (a != 0) {
		if (b != 0) {
			if (c != 0)
				Sredn(a, b, c);
			else
				Sredn(a, b);
		}
		else if (b == 0) {
			if (c != 0)
				Sredn(a, c);
			else
				std::cout << "Ошибка. Два или более числа равны 0";
		}

	}
	else if (b != 0) {
		if (c != 0)
			Sredn(b, c);
		else
			std::cout << "Ошибка. Два или более числа равны 0";
	}
	else
		std::cout << "Ошибка. Два или более числа равны 0";
}
void Lab1(int x) {
	if (x != 0)
		std::cout << "\nОбратное: " << -x << "\nВторая степень: " << x * x << "\nПятая степень: " << pow(x, 5);
	else
		std::cout << "Ошибка. Число равно 0";
}

int main()
{
	SetConsoleOutputCP(1251);
	int n,x;
	float a,b,c;
	std::cout << "Выберите, какой пункт запускаем?: ";
	std::cin >> n;
	if (n == 1) {
		std::cout << "\nВведите три числа (0 не считается за число): ";
		std::cin >> a >> b >> c;
		SearchSredn(a, b, c);
	}
	if (n == 2) {
		std::cout << "Введите число, не равное 0: ";
		std::cin >> x;
		Lab1(x);
	}
	return 0;
}