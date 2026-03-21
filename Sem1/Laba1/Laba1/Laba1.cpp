#include <iostream>
#include <lib.hpp>

int main()
{
	int x; // т.к. не указаны границы числа x, кроме того, что x != 0 и x - целое => я взял самый популярный, но не самый большой целочисленный тип данных со знаком. В этом задании можно использовать любой целочисленный тип данных со знаком. Это будет влиять только на границы числа x.
	std::cin >> x;
	std::cout << sizeof x * 8 << " bites\n" << INT_MIN << '\n' << INT_MAX << '\n';
	int y,z,d;
	y = -x;
	z = x*x;
	d = pow(x, 5);
	std::cout << "int   " << y << std::endl;
	std::cout << "int   " << z << std::endl;
	std::cout << "int   " << d << std::endl;
	/*
	Многострочный
	Комментарий
	*/
	Workshop a;
	Battery b;
	b.current_charge = 10;
	b.max_charge = 100;
	std::cout << b.current_charge << " " << b.max_charge;

}
