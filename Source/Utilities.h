#ifndef PROJECT_AED_UTILITIES_H
#define PROJECT_AED_UTILITIES_H

#include "Flight.h"

/**
* Boolean function thar compares to objects of this class, based on their number of passengers
* @param f1 first flight that will be compared
* @param f2 second flight object that will be compared
* @return if f1 has less number of passengers than f2
*/
friend bool byNumberOfPassengers(const Flight &f1, const Flight &f2);

        /**
        * Boolean function thar compares to objects of this class, based on their total weight
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 has less total weight than f2
        */
        friend bool byTotalWeight(const Flight &f1, const Flight &f2);

        /**
        * Boolean function thar compares to objects of this class, based on their date
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 occurs before f2
        */
        friend bool byDate(const Flight &f1, const Flight &f2);

        /**
        * Boolean function thar compares to objects of this class, based on their duration
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 has less duration than f2
        */
        friend bool byDuration(const Flight &f1, const Flight &f2);



#endif // PROJECT_AED_UTILITIES_H