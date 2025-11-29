#include <iostream>
#include <vector>
#include <Windows.h>
#include <array>
#include <random>
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
	read(arr);
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
	read(arr);
}

void read_arr(std::array<int, 10>& arr) {
	for (int i = 0; i < 10; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void sort2(std::array<int, 10>& arr) {
	char sign;
	std::cout << "В какую сторону сотрируем?(>,<): " << '\n';
	std::cin >> sign;
	if (sign == '<') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
	else if (sign == '>') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
				if (arr[i] < arr[j]) {
					std::swap(arr[i], arr[j]);
				}
		}
	}
}

void sort3(int* arr) {
	char sign;
	std::cout << "В какую сторону сотрируем?(>,<): " << '\n';
	std::cin >> sign;
	if (sign == '<') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
				if (*(arr + i) > *(arr + j)) {
					std::swap(*(arr + i), *(arr + j));
				}
		}
	}
	else if (sign == '>') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
				if (*(arr+i) < *(arr + j)) {
					std::swap(*(arr + i), *(arr + j));
				}
		}
	}
}

void sort1(std::array<int, 10> arr) {
	char sign;
	std::cout << "В какую сторону сотрируем?(>,<): " << '\n';
	std::cin >> sign;
	if (sign == '<') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
				}
		}
	}
	else if (sign == '>') {
		for (int i = 0; i < 9; ++i) {
			for (int j = i + 1; j < 10; ++j)
				if (arr[i] < arr[j]) {
					std::swap(arr[i], arr[j]);
				}
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	int choise, point;
	std::cout << "Выберите пункт: ";
	std::cin >> point;
	switch (point)
	{
	case 1: {
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
		break;
		}
	case 2: {
		std::array<int, 10> array;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(-10, 10);
		int random_number, another_choise;
		for (int i = 0; i < 10; ++i) {
			random_number = distrib(gen);
			array[i] = random_number;
		}
		read_arr(array);
		std::cout << "Сортировка по значению(1)/ссылке(2)/указателю(3): ";
		std::cin >> another_choise;
		switch (another_choise)
		{
		case 1: sort1(array); read_arr(array); break; // При передаче по значению, внутри функции создаётся копия исходного массива, с которой и происходят все изменения, а исходный массив не изменяется, что видно из-за одинакового вывода до и после работы функции.
		case 2: sort2(array); read_arr(array); break; // При передаче по ссылке, в функцию передаётся как бы псевдоним исходного массива, который указывает на ту же область памяти, что и исходный массив. Из-за этого все изменения внутри функции применяются к исходному массиву.
		case 3: sort3(array.data()); read_arr(array); break; // Передача по указателю это практически тоже самое, что и передача по ссылке. При передаче по указателю внутрь функции передаётся указатель на первый элемент массива, исходя из адреса на который он указывает находятся остальные элементы. Из-за того, что передаётся именно указатель, все изменения внутри функции применяются к исходному массиву.
		default: std::cout << "Ошибка. Введено неверное число";
			break;
		}
		break;
		}
	case 3: {
		std::cout << "Выбор был очевиден, и std::vector и std::array не могут выполнять одинаковую роль в этих условиях. std::vector - это динамический массив. Именно поэтому он был использован в п.1, ведь мы не знали точного количества элементов. std::array - это массив фиксированной длины, которая как раз была дана в п.2. Если бы мы попытались использовать его в п.1, то потерпели бы неудачу, ведь насколько большим его размер ты не возьми, всегда есть шанс того, что нужно будет больше, когда у std::vector такой проблемы нет.";
		}

	}

	
}
