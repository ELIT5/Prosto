#include <iostream>
#include <bitset>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
    std::cout << "1." << '\n';
    int A,i;
    std::cin >> A >> i;
    if (i > 0) {
        if ((A & (1 << i - 1)) == (A & (0 << i - 1))) {
            int x1, x2;
            std::cin >> x1 >> x2;
            if ((x1 > 0 && x2 > 0 && x1 > x2) || (x1 < 0 && x2 < 0 && x1 < x2) || (x1 > 0 && x2 < 0 && x1 > -x2) || (x1 < 0 && x2 > 0 && -x1 > x2)) {
                std::cout << x1 << x1 << '\n';
            }
            else {
                std::cout << x2 << x2 << '\n';
            }
        }
        else {
            A = A & ~(~A | 1 << (i-1));
            std::bitset<8> A1 = A;
            std::cout << A1.to_string() << '\n';
        }
    }
    std::cout << "2." << '\n';
    int N,M;
    std::cin >> N >> M;
    if (0 < N < 10 && 0 < M < 10) {
        switch (10 * N + M)
        {
        case 11: std::cout << "Барабанные палочки"; break;
        case 22: std::cout << "Гуси-лебеди, утята"; break;
        case 33: std::cout << "Кудри, богатыри"; break;
        case 44: std::cout << "Стульчики"; break;
        case 55: std::cout << "Пенсионерка, перчатки, варежки, два петуха"; break;
        case 66: std::cout << "Валенки, салазки"; break;
        case 77: std::cout << "Топорики, Семён Семёныч"; break;
        case 88: std::cout << "Крендельки, бублики, матрёшки, снеговики"; break;
        default: std::cout << "Номер не дубль"; break;
        }
    }
}
