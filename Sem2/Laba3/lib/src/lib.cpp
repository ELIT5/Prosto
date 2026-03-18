#include <string>
#include <vector>
#include <lib.hpp>
    Workshop::Workshop(const Workshop& other) {
        adress_ = other.adress_;
        clocks_in_workshop_ = other.clocks_in_workshop_;
    }
    Workshop::Workshop(const std::string adress, const std::vector<std::string> clocks_in_workshop) : adress_(adress), clocks_in_workshop_(clocks_in_workshop) {}
    void change_battery(Battery& battery) {
        battery.current_charge = battery.max_charge;
    }
