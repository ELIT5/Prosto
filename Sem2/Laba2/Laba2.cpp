#include <iostream>
#include "Class.hpp"


int main()
{
    zk::clock a;
    zk::clock b(7, 9, 2026, 15, 16, "Вторник", {"Почистить зубы", "Сходить в туалет", "Пойти в магазин"});
    a.print();
    b.print();
    zk::clock c = a + b;
    c.print();
    zk::clock d = a / b;
    d.print();
}