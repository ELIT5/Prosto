#include <iostream>
#include <array>

std::array<short, 10> func(unsigned short n) {
    short digit;
	std::array<short, 10> digits = { 0 };
	while (n != 0)
	{
		digit = n % 10;
		n /= 10;
		digits[digit]++;
	}
	return digits;
}	

int main()
{
	unsigned short n;
	std::array<short, 10> digits = func(n);
	for (int i = 0; i < 10; i++)
	{
		std::cout << digits[i] << std::endl;
	}
}
