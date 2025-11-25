#include <iostream>
#include <vector>
#include <Windows.h>
using vec = std::vector<int>;
void read(vec& arr) {
	std::cout << '[';
	if (arr.size() > 0) {
		std::cout << arr[0];
		if (arr.size() > 1) {
			for (int i = 1; i < arr.size(); ++i) {
				std::cout << " " << arr[i];
			}
		}
	}
	std::cout << ']' << '\n';
}	

void add_start(vec& arr, int num) {
	if (arr.capacity() > arr.size() + 1) {
		arr.push_back(arr.size() + 1);
	}
	else {
		arr.reserve(20);
		arr.push_back(arr.size() + 1);
	}
	for (int i = arr.size()-1; i > 0; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = num;
}

void add_end(vec& arr, int num) {
	if (arr.capacity() > arr.size() + 1) {
		arr.push_back(arr.size() + 1);
	}
	else {
		arr.reserve(20);
		arr.push_back(arr.size() + 1);
	}
	arr[arr.size()-1] = num;
}

void find_el(vec& arr, int num) {
	vec answ;
	answ.reserve(arr.size());
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == num) {
			add_end(answ, i);
		}
	}
	read(answ);
}

void variant_task(vec& arr) {
	int tmp = 0;
	for (int i = 0; i <= ((arr.size()-1)/2); ++i) {
		if ((arr[i] % 7 != 0 || arr[i] == 777) && arr[arr.size() - i - 1] % 7 != 0) {
			std::swap(arr[i], arr[arr.size() - i - 1]);
		}
		else {
			if (arr[i] % 7 == 0 && arr[i] != 777)
				arr[arr.size() - i - 1] = arr[i];
			else if (arr[arr.size() - i - 1] % 7 == 0 && arr[arr.size() - i - 1] != 777)
				arr[i] = arr[arr.size() - i - 1];
			else
				continue;
			tmp++;
		}
	}
	if (tmp == 0) {
		for (int i = 0; i < 3; ++i) {
			add_end(arr, 0);
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	int choise;
	vec arr;
	arr.reserve(20);
	while (true) {
		std::cout << "0. Выход." << '\n' << "1. Просмотр массива." << '\n' << "2. Добавить элемент в начало." << '\n' << "3. Добавить элемент в конец." << '\n' << "4. Очистка всего массива." << '\n' << "5. Поиск элемента в массиве." << '\n' << "6. Задание варианта." << '\n' << "7. Очистить консоль." << '\n';
		std::cin >> choise;
		switch (choise)
		{
		case 0: exit(0); break;
		case 1: read(arr); break;
		case 2: int tmp; std::cin >> tmp; add_start(arr, tmp); break;
		case 3: std::cin >> tmp; add_end(arr, tmp); break;
		case 4: arr.clear(); break;
		case 5: std::cin >> tmp; find_el(arr, tmp); break;
		case 6: variant_task(arr); break;
		case 7: system("cls"); break;
		default:
			std::cout << "Вы ввели неверный символ.";
			break;
		}
	}
}
