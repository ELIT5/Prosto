#include <iostream>
#include <bitset>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
    std::cout << "1." << '\n';
    int i;
    short A;
    bool bit_i;
    std::cin >> A >> i;
    bit_i = A == (A | (1 << i));
    if (i >= 0 && i < 15) {
        if (bit_i != 0) {
            A = A & ~(~A | 1 << (i));
            std::bitset<16> A1 = A;
            std::cout << A1.to_string() << '\n';
        }
        else {
            int x1, x2;
            std::cin >> x1 >> x2;
            if ((x1 > 0 && x2 > 0 && x1 > x2) || (x1 < 0 && x2 < 0 && x1 < x2) || (x1 > 0 && x2 < 0 && x1 > -x2) || (x1 < 0 && x2 > 0 && -x1 > x2)) {
                std::cout << x1 << x1 << '\n';
            }
            else {
                std::cout << x2 << x2 << '\n';
            }
        }
    }
    std::cout << "2." << '\n';
    int N,M;
    std::cin >> N >> M;
    if (0 < N && N < 10 && 0 < M && M < 10) {
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
