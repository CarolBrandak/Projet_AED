#ifndef PROJECT_AED_TRANSPORT_H
#define PROJECT_AED_TRANSPORT_H

#include "Date.h"

/**
 * A class to manage an Airport's Transport
 */
class Transport {

    private:

        /**
         * @var ID - a constant string containing Transport's ID
         */
        const string ID;

        /**
         * @var TYPE - a constant string containing Transport's TYPE
         */
        const string TYPE;

        /**
         * @var DISTANCE - a constant integer value containing the distance to the airport
         */
        const int DISTANCE;

        /**
         * @var DATE - a constant Date object containing the transport departure time (hour and minute)
         */
        const Date DATE;

    public:

        /**
         * A default constructor of the class. No arguments needed
         */
        Transport();

        /**
         * A default destructor of the class
         */
        ~Transport();

        /**
         * Main constructor of the class
         * @param id - a string containing Transport's id
         * @param type - a string containing Transport's type
         * @param distance - a integer value containing the distance to the airport
         * @param date - a date object containing the transport departure time (hour and minute)
         */
        Transport(string id, string type, int distance, Date date);

        /**
         * A function to get the current ID of the Transport
         * @return a string containing the Transport id
         */
        string getID() const;

        /**
         * A function to get the current Type of the Transport
         * @return a string containing the Transport type
         */
        string getType() const;

        /**
         * A function to get the current distance to the airport
         * @return an integer value containing the wanted distance
         */
        int getDistance() const;

        /**
         * A function to get a transport Time
         * @return a Date object containing the wanted time (hour and minute)
         */
        Date getDate() const;

        /**
         * @overload
         * Boolean function that compares two objects of class Transport
         * @param transport another object that will be compared
         * @return if the current object is the same than object passed by reference
        */
        bool operator == (const Transport &transport) const;

        /**
         * @overload
         * Boolean function that compares two objects of class Transport
         * @param transport another object that will be compared
         * @return if the current object is less than object passed by reference
        */
        bool operator < (const Transport &transport) const;

        /**
         * @overload
         * Function that returns all characteristics of the Transport being manipulated
         * @param os - ostream object, passed by reference
         * @param transport - Transport object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream &os, const Transport &transport);
};

#endif // PROJECT_AED_TRANSPORT_H