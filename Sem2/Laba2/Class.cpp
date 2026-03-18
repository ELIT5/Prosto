#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <random>
#include "Class.hpp"

namespace zk {
    clock::clock() = default;



    clock::clock(const int day, const int month, const int year, const int hours, const int minutes, const std::string day_of_week, const std::vector<std::string> dela)
        : day_(day), month_(month), year_(year), hours_(hours), minutes_(minutes), day_of_week_(day_of_week), dela_(dela) {
    }



    clock::clock(const clock& other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        minutes_ = other.minutes_;
        day_of_week_ = other.day_of_week_;
        dela_.resize(other.dela_.size());
        std::copy(other.dela_.begin(), other.dela_.end(), dela_.begin());
    }


    int clock::get_day() const {
        return day_;
    }
    int clock::get_month() const {
        return month_;
    }
    int clock::get_year() const {
        return year_;
    }
    int clock::get_hours() const {
        return hours_;
    }
    int clock::get_minutes() const {
        return minutes_;
    }
    std::string clock::get_day_of_week() const {
        return day_of_week_;
    }


    void clock::set_day_of_week(const std::string day) {
        if (days_->find(day) != std::string::npos) {
            day_of_week_ = day;
        }
    }
    
    void clock::add_minutes(int added) {
        minutes_ += added;
        if (minutes_ >= 60) {
            hours_ += minutes_ / 60;
            minutes_ = minutes_ % 60;
            if (hours_ >= 24) {
                int days_added = hours_ / 24;
                day_ += days_added;
                if (std::distance(std::begin(days_), std::find(std::begin(days_), std::end(days_), day_of_week_)) + days_added >= 7) {
                     int days_of_week_added = (std::distance(std::begin(days_), std::find(std::begin(days_), std::end(days_), day_of_week_)) + days_added) % 7;
                    day_of_week_ = days_[days_of_week_added];
                }
                else {
                    day_of_week_ = days_[std::distance(std::begin(days_), std::find(std::begin(days_), std::end(days_), day_of_week_)) + days_added];
                }
                hours_ = hours_ % 24;
                if (day_ > 28 && month_ == 2) {
                    month_ += 1;
                    day_ = day_ - 28;
                }
                if (day_ > 31 && is_month_31_(month_)) {
                    month_ += day_ / 31;
                    day_ = day_ % 31;
                    if (month_ > 12) {
                        year_ += month_ / 12;
                        month_ = month_ % 12;
                    }
                }
                else if (day_ > 30 && is_month_30_(month_)) {
                    month_ += day_ / 30;
                    day_ = day_ % 30;
                    if (month_ > 12) {
                        year_ += month_ / 12;
                        month_ = month_ % 12;
                    }
                }
            }
        }
    }
    

    void clock::print() const {
        std::cout << day_ << '.' << month_ << '.' << year_ << ' ' << hours_ << ':' << minutes_ << ' ' << day_of_week_ << " [";
        for (int i = 0; i < dela_.size()-1; ++i){
            std::cout << dela_[i] << ", ";
        }
        std::cout << dela_[dela_.size()-1] << ']' << std::endl;
    }


    clock::~clock() {
        std::cout << "Деструктор был вызван" << std::endl;
        dela_.clear();
    }
    
    clock& clock::operator=(const clock& other) {
        dela_.clear();
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        minutes_ = other.minutes_;
        day_of_week_ = other.day_of_week_;
        dela_.resize(other.dela_.size());
        std::copy(other.dela_.begin(), other.dela_.end(), dela_.begin());
        return *this;
    }

    clock& clock::operator+(clock& other) {
        if (define_date(*this, other)){
            for (int i = 0; i < other.dela_.size(); ++i){
                if (std::count(dela_.begin(), dela_.end(), other.dela_[i]) == 0) {
                    dela_.push_back(other.dela_[i]);
                }
            }
            this->add_minutes(10140);
            return *this;
        }
        for (int i = 0; i < dela_.size(); ++i){
            if (std::count(other.dela_.begin(), other.dela_.end(), dela_[i]) == 0) {
                other.dela_.push_back(dela_[i]);
            }
        }
        other.add_minutes(10140);
        return other;
    }
    clock& clock::operator/(clock& other) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist1(0, dela_.size()-1);
        std::uniform_int_distribution<> dist2(0, other.dela_.size()-1);
        int rand1 = dist1(gen);
        int rand2 = dist2(gen);
        if (!define_date(*this, other)){
            this->add_minutes(4320);
        } 
        else {
            other.add_minutes(4320);
        }
        std::vector<std::string> dela_tmp = dela_;
        dela_.clear();
        dela_.reserve(rand1+rand2);
        for (int i = 0; i < rand1; ++i) {
            dela_.push_back(dela_tmp[i]);
        }
        for (int i = 0; i < rand2; ++i) {
            if (std::count(dela_.begin(), dela_.end(), other.dela_[i]) == 0) {
                dela_.push_back(other.dela_[i]);
            }
            else {
                if (++rand2 <= other.dela_.size()) {
                    ++rand2;
                }
            }
        }
        return *this;
    }
    
    bool clock::is_month_31_(int month) {
        bool answer = false;
        for (int i = 0; i < 7; ++i) {
            if (month == monthes_31_[i]) { answer = true; }
        }
        return answer;
    }

    bool clock::is_month_30_(int month) {
        bool answer = false;
        for (int i = 0; i < 4; ++i) {
            if (month == monthes_30_[i]) { answer = true; }
        }
        return answer;
    }

    bool clock::define_date(const clock& date1, const clock& date2){
        if ((date1.year_ > date2.year_) || (date1.year_ == date2.year_ && date1.month_ > date2.month_) || (date1.year_ == date2.year_ && date1.month_ == date2.month_ && date1.day_ > date2.day_)) {
            return 1;
        }
        return 0;
    }
    
}