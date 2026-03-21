#pragma once
#include <string>
#include <vector>
struct Battery{
    int current_charge = 100;
    int max_charge = 100;
};
class Workshop {
    public:
        Workshop() = default;
        Workshop(const Workshop& other);
        Workshop(const std::string adress, const std::vector<std::string> clocks_in_workshop);
        void change_battery(Battery& battery);
    private:
        std::string adress_;
        std::vector<std::string> clocks_in_workshop_;
};
