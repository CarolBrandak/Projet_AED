#ifndef Date_H
#define Date_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * A class that represents a Date
 */
class Date {

    private:

        /**
         * @var day, an integer value
         */
        int day;

        /**
         * @var month, an integer value
         */
        int month;

        /**
         * @var year, an integer value
         */
        int year;

    public:

        /**
        * A default constructor of class Date.
        */
        Date();

        /**
         * Main constructor
         * @param day Date's day, a int passed by value
         * @param month Date's month, a int passed by value
         * @param year Date's year, a int passed by value
         */
        Date(int day, int month, int year);

        /**
         * Return Date's day
         * @return a int, containing date's day
         */
        int getDay() const;

        /**
         * Return Date's month
         * @return a int, containing date's month
         */
        int getMonth() const;

        /**
         * Return Date's year
         * @return a int, containing date's year
         */
        int getYear() const;

        /**
         * Set Date day
         * @param day Date's new day, a int passed by value
         */
        void setDay(int day);

        /**
         * Set Date month
         * @param month Date's new month, a int passed by value
         */
        void setMonth(int month);

        /**
         * Set Date year
         * @param year Date's new year, a int passed by value
         */
        void setYear(int year);

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param date another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Date &date) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param date another object that will be compared
         * @return if the current object is less than object passed by reference
         */
        bool operator < (const Date &date) const;
};

/**
* @overload
* Function that returns all characteristics of the Date being manipulated
* @param os ostream object, passed by reference
* @param date Date object, passed by reference
* @return ostream object
*/
ostream & operator << (ostream & os, const Date &date);

#endif // Date_H