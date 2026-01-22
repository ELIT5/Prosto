#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    std::cout << "Пункт 1" << '\n';
    int n, first,a,sum = 0,min = pow(2,32), n_min, max_digit = 0, min_digit = 9, k = 0;--min;
    std::cin >> n; n_min = n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a;
        if (i == 1) {
            first = a;
            continue;
        }
        if (a > first) {
            sum += a;
            if (a < min) {
                min = a;
                n_min = i;
            }
            ++k;
        }
    }
    if (k != 0) {
        std::cout << "Сумма всех, больше первого " << sum << " Наименьшее из таких " << min << " Его номер в последовательности " << n_min << std::endl;
    }
    std::cout << "Пункт 2" << '\n';
    int x;
    std::cin >> x;
    if (x > -1000 || x < 1000) {
        if (x < 0) {
            x = -x;
        }
        while (x > 0) {
            if (max_digit < x % 10) {
                max_digit = x % 10;
            }
            if (min_digit > x % 10) {
                min_digit = x % 10;
            }
            x /= 10;
        }
    }
    if (min_digit + max_digit != 0) {
        std::cout << "Сумма наименьшей и наибольшей цифр " << max_digit + min_digit;
    }
}

