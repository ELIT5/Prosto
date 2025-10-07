#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    int n, first,a,sum = 0,min = 10000000,n_min,max_digit = 0,min_digit = 9;
    std::cin >> n;
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
        }
    }
    std::cout << "Сумма всех, больше первого " << sum << " Наименьшее из таких " << min << " Его номер в последовательности " << n_min << std::endl;
    while (sum > 0) {
        if (max_digit < sum % 10) {
            max_digit = sum % 10;
        }
        else if (min_digit > sum % 10) {
            min_digit = sum % 10;
        }
        sum /= 10;
    }

    std::cout << "Сумма наименьшей и наибольшей цифр " << max_digit + min_digit;
}
