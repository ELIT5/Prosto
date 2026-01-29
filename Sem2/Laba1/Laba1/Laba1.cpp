#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <iterator>


namespace zk {


    class clock {
    public:
        clock() = default;



        clock(const short day, const short month, const int year, const short hours, const short minutes, const std::string day_of_week)
            : day_(day), month_(month), year_(year), hours_(hours), minutes_(minutes), day_of_week_(day_of_week) {
        }



        clock(const clock& other) {
            day_ = other.day_;
            month_ = other.month_;
            year_ = other.year_;
            hours_ = other.hours_;
            minutes_ = other.minutes_;
            day_of_week_ = other.day_of_week_;
        }


        short get_day() const {
            return day_;
        }
        short get_month() const {
            return month_;
        }
        int get_year() const {
            return year_;
        }
        short get_hours() const {
            return hours_;
        }
        short get_minutes() const {
            return minutes_;
        }
        std::string get_day_of_week() const {
            return day_of_week_;
        }


        void set_day_of_week(const std::string day) {
            if (days_->find(day) != std::string::npos) {
                day_of_week_ = day;
            }
        }


        void add_minutes(int added) {
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
                        if (month_ > 12) {
                            year_ += month_ / 12;
                            month_ = month_ % 12;
                        }
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


        void print() const {
            std::cout << day_ << '.' << month_ << '.' << year_ << ' ' << hours_ << ':' << minutes_ << ' ' << day_of_week_ << std::endl;
        }


        ~clock() {
            std::cout << "Деструктор был вызван" << std::endl;
        }
    private:
        bool is_month_31_(short month) {
            bool answer = false;
            for (int i = 0; i < 7; ++i) {
                if (month == monthes_31_[i]) { answer = true; }
            }
            return answer;
        }
        bool is_month_30_(short month) {
            bool answer = false;
            for (int i = 0; i < 4; ++i) {
                if (month == monthes_30_[i]) { answer = true; }
            }
            return answer;
        }
        short day_ = 22;
        short month_ = 1;
        int year_ = 2026;
        short hours_ = 6;
        short minutes_ = 16;
        std::string day_of_week_ = "Четверг";
        std::string days_[7] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
        short monthes_31_[7] = { 1,3,5,7,8,10,12 };
        short monthes_30_[4] = { 4,6,9,11 };
    };
}
int main()
{
    SetConsoleOutputCP(1251);
    zk::clock a;
    a.add_minutes(9999);
    a.print();
}