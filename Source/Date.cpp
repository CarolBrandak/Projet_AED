#ifndef PROJECT_AED_DATE_CPP
#define PROJECT_AED_DATE_CPP

#include "Date.h"

Date::Date() {}

Date::~Date() {}

Date::Date(int day, int month, int year, int hour, int minute) {
    this -> day=day;
    this -> month=month;
    this -> year=year;
    this -> hour = hour;
    this -> minute = minute;
}

Date::Date(int day, int month, int year) {
    this -> day=day;
    this -> month=month;
    this -> year=year;
    this -> hour = 0;
    this -> minute = 0;
}

Date::Date(int hour, int minute) {
    this->hour = hour;
    this->minute = minute;
    this->day = 0;
    this->month = 0;
    this->year = 0;
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

int Date::getHour() const {
    return hour;
}

int Date::getMinute() const {
    return minute;
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

void Date::setHour(const int &hour) {
    this->hour = hour;
}

void Date::setMinute(const int &minute) {
    this->minute = minute;
}

bool Date::operator == (const Date &date) const {
    if (!day && !month && !year) {
        return hour == date.hour && minute == date.minute;
    } else if (!hour && !minute) {
        return day == date.day && month == date.month && year == date.year;
    }
    return day == date.day && month == date.month && year == date.year &&
            hour == date.hour && minute == date.minute;
}

bool Date::operator < (const Date &date) const {
    if (year == date.year) {
        if (month == date.month) {
            if (hour == date.hour) {
                return minute < date.minute;
            } else return hour < date.hour;
        } else return month < date.hour;
    } else return year < date.year;
}

ostream & operator << (ostream & os, const Date &date) {

    if (!date.day && !date.month && !date.year) {
        os << " " << setfill('0') << setw(2) << date.hour
           << ":" << setfill('0') << setw(2) << date.minute << endl;

    } else if (!date.hour && !date.minute) {

        os  << setfill('0') << setw(2) << date.day
            << "-" << setfill('0') << setw(2) << date.month
            << "-" << setfill('0') << setw(4) << date.year << endl;

    } else {
        os << setfill('0') << setw(2) << date.day
           << "-" << setfill('0') << setw(2) << date.month
           << "-" << setfill('0') << setw(4) << date.year
           << " " << setfill('0') << setw(2) << date.hour
           << ":" << setfill('0') << setw(2) << date.minute
           << endl;
    }
    return os;
}

#endif // PROJECT_AED_DATE_CPP