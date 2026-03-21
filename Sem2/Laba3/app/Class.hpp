#pragma once

#include <vector>
#include <string>
#include <lib.hpp>
namespace zk{
    struct FirstLastDate;
    class clock {
        public:
            clock();
            clock(const int day, const int month, const int year, const int hours, const int minutes, const std::string day_of_week, const std::vector<std::string> dela);
            clock(const clock& other);
            int get_day() const;
            int get_month() const;
            int get_year() const;
            int get_hours() const;
            int get_minutes() const;
            std::string get_day_of_week() const;
            void set_day_of_week(const std::string day);
            void add_minutes(int added);
            void print() const;
            ~clock();
            clock& operator=(const clock& other);
            clock& operator+(clock& other);
            clock& operator/(clock& other);
            bool define_date(const clock& date1, const clock& date2);
            Battery battery;
        private:
            bool is_month_31_(int month);
            bool is_month_30_(int month);
            int day_ = 22;
            int month_ = 1;
            int hours_ = 6;
            int minutes_ = 16;
            int monthes_31_[7] = { 1,3,5,7,8,10,12 };
            int monthes_30_[4] = { 4,6,9,11 };
            int year_ = 2026;
            std::string day_of_week_ = "Четверг";
            std::string days_[7] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
            std::vector<std::string> dela_ = {"Поесть", "Учёба"};
    }; 
}