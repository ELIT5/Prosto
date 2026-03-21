#include <iostream>
#include <Class.hpp>


int main()
{
    zk::clock a;
    a.print();
    a.add_minutes(144000);
    a.print();
    a.add_minutes(1064);
    a.print();
    std::vector<zk::clock*> clocks;
    zk::Workshop wp("here", clocks);
    wp.print();
    wp.add_clock_in_workshop(&a);
    wp.print();
    wp.change_battery(&a, zk::Battery_type::EXPENSIVE);
    wp.print();
    a.print();


}