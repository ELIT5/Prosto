#pragma once
#include <string>
#include <vector>

namespace zk {
    class clock;
    enum class Battery_type{
        CHEAP,
        NORMAL,
        EXPENSIVE
    };
    struct Battery{
        int current_charge = 100;
        int max_charge = 100;
        Battery_type type = Battery_type::NORMAL;
    };
    class Workshop {
        public:
            Workshop() = default;
            Workshop(const Workshop& other);
            Workshop(const std::string adress, const std::vector<zk::clock*> clocks_in_workshop);
            void change_battery(zk::clock* clock, const Battery_type type);
            void add_clock_in_workshop(zk::clock* clock);
            void print();
        private:
            void delete_clock_from_workshop(zk::clock* clock);
            std::string adress_;
            std::vector<zk::clock*> clocks_in_workshop_;
    };
}