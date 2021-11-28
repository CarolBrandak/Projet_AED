#ifndef Date_CPP
#define Date_CPP

#include "Date.h"

Date::Date() {}

Date::Date(int day, int month, int year) {
    this -> day=day;
    this-> month=month;
    this-> year=year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(const int &day){
    this->day=day;
}

void Date::setMonth(const int &month){
    this->month=month;
}

void Date::setYear(const int &year){
    this->year=year;
}

bool Date::operator == (const Date &date) const {
    return day == date.getDay() && month == date.getMonth() && year == date.getYear();
}

bool Date::operator < (const Date &date) const {
    if (year == date.getYear()) {
        if (month == date.getMonth()) {
            return day < date.getDay();
        } else return month < date.getMonth();
    } else return year < date.getYear();
}

ostream & operator << (ostream & os, const Date &date) {
    os << setfill('0') << setw(2) << date.getDay() << "-" << setfill('0') << setw(2) << date.getMonth()
        << "-" << setfill('0') << setw(4) << date.getYear() << endl;
    return os;
}

#endif // Date_CPP