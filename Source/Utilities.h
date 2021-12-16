//#ifndef PROJECT_AED_UTILITIES_H
#define PROJECT_AED_UTILITIES_H

#include "Flight.h"

/**

* Boolean function thar compares to objects of this class, based on their number of passengers
* @param f1 first flight that will be compared
* @param f2 second flight object that will be compared
* @return if f1 has less number of passengers than f2

bool byNumberOfPassengers(const Flight &f1, const Flight &f2);


        * Boolean function thar compares to objects of this class, based on their total weight
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 has less total weight than f2

        bool byTotalWeight(const Flight &f1, const Flight &f2);


        * Boolean function thar compares to objects of this class, based on their date
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 occurs before f2

        bool byDate(const Flight &f1, const Flight &f2);


        * Boolean function thar compares to objects of this class, based on their duration
        * @param f1 first flight that will be compared
        * @param f2 second flight object that will be compared
        * @return if f1 has less duration than f2

        bool byDuration(const Flight &f1, const Flight &f2);


         * Boolean function thar compares to objects of this class, based on their weight
         * @param l1 first luggage that will be compared
         * @param l2 second luggage object that will be compared
         * @return if l1 has less weight than l2

friend bool byWeight(const Luggage &l1, const Luggage &l2);


 * Boolean function thar compares to objects of this class, based on their volume
 * @param l1 first luggage that will be compared
 * @param l2 second luggage object that will be compared
 * @return if l1 has less volume than l2

friend bool byVolume(const Luggage &l1, const Luggage &l2);



         * Boolean function thar compares to objects of this class, based on their Name
         * @param p1 first person that will be compared
         * @param p2 second person that will be compared
         * @return if p1 has less name than p2, based on alphabetic order

friend bool byName(const Passenger &p1, const Passenger &p2);


* Boolean function thar compares to objects of this class, based on their age
* @param p1 first person that will be compared
* @param p2 second person that will be compared
* @return if p1 has less age than p2

friend bool byAge(const Passenger &p1, const Passenger &p2);


* Boolean function thar compares to objects of this class, based on their total luggage's weight
* @param p1 first person that will be compared
* @param p2 second person that will be compared
* @return if p1 has less luggage weight than p2

friend bool byLuggage(const Passenger &p1, const Passenger &p2);

*/


//#endif // PROJECT_AED_UTILITIES_H