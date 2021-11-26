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

void Date::setDay(int day){
    this->day=day;
}

void Date::setMonth(int month){
    this->month=month;
}

void Date::setYear(int year){
    this->year=year;
}

bool Date::operator == (const Date &date) const {
    return day == date.getDay() && month == date.getMonth() && year == date.getYear();
}

bool Employee::operator < (const Date &date) const {
    if (day == date.getDay()) {
        if (month == date.getMonth()) {
            return year < date.getYear();
        } else return month < date.getMonth();
    } else return day < date.getDay();
}

ostream & operator << (ostream & os, const Date &date) {
    os << date.getDay() << "-" << date.getMonth() << "-" << date.getYear() << endl;
    return os;
}

#endif // Date_CPP