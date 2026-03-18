#include <iostream>
#include "Class.hpp"


int main()
{
    zk::clock a;
    a.print();
    a.add_minutes(144000);
    a.print();
    a.add_minutes(1064);
    a.print();
}