#include <string>
#include <vector>
#include <lib.hpp>
#include "Class.hpp"
#include <iterator>
#include <iostream>
namespace zk {
    Workshop::Workshop(const Workshop& other) {
        adress_ = other.adress_;
        clocks_in_workshop_ = other.clocks_in_workshop_;
    }
    Workshop::Workshop(const std::string adress, const std::vector<zk::clock*> clocks_in_workshop) : adress_(adress), clocks_in_workshop_(clocks_in_workshop) {}
    void Workshop::add_clock_in_workshop(zk::clock* clock) {
        try {
            if (std::count(clocks_in_workshop_.begin(), clocks_in_workshop_.end(), clock) != 0){
                throw "Ошибка. Часы уже находятся в этой мастерской";
            }
            clocks_in_workshop_.push_back(clock);
        }
        catch (const char* message){
            std::cout << message << std::endl;
        }
    }
    void Workshop::delete_clock_from_workshop(zk::clock* clock) {
        try {
            if (std::count(clocks_in_workshop_.begin(), clocks_in_workshop_.end(), clock) == 0){
                throw "Ошибка. Часы не находятся в этой мастерской";
            }
            auto it = std::find(clocks_in_workshop_.begin(), clocks_in_workshop_.end(), clock);
            clocks_in_workshop_.erase(it);
        }
        catch (const char* message){
            std::cout << message << std::endl;
        }
    }
    void Workshop::print(){
        std::cout << adress_;
        if (clocks_in_workshop_.size() > 0) {
            std::cout << " [";
            for (int i = 0; i < clocks_in_workshop_.size()-1; ++i){
                std::cout << clocks_in_workshop_[i] << ", ";
            }
            std::cout << clocks_in_workshop_[clocks_in_workshop_.size()-1] << ']';
        }
        std::cout << std::endl;
    }
    void Workshop::change_battery(zk::clock* clock, const Battery_type type) {
        try {
            if (std::count(clocks_in_workshop_.begin(), clocks_in_workshop_.end(), clock) == 0){
                throw "Ошибка. Часы не находятся в этой мастерской";
            }
            switch(type){
                case Battery_type::CHEAP: clock->battery.max_charge = 50; clock->battery.current_charge = 50; break; 
                case Battery_type::NORMAL: clock->battery.max_charge = 100; clock->battery.current_charge = 100; break; 
                case Battery_type::EXPENSIVE: clock->battery.max_charge = 200; clock->battery.current_charge = 200; break; 
            }
            Workshop::delete_clock_from_workshop(clock);
        }
        catch (const char* message){
            std::cout << message << std::endl;
        }
    }
}