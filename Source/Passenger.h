#ifndef PROJECT_AED_PASSENGER_H
#define PROJECT_AED_PASSENGER_H

#include "Person.h"
#include "Luggage.h"

/**
 * Person's derived class
 */
class Passenger : public Person {

    private:

        /**
         * @var passportNumber, a string
         */
        string passportNumber;

        /**
         * @var luggage, a vector with Luggage's objects
         */
        vector<Luggage> luggage;

    public:

        /**
         * A default constructor of class Passenger. No arguments needed.
         */
        Passenger();

        /**
         * Main constructor
         * @param name Passenger's name, a string passed by value
         * @param age Passenger's age, a short integer passed by value
         * @param gender Passenger's gender, a char passed by value
         * @param passportNumber Passenger's passport number, a string passed by value
         * @param luggage Passenger's luggage, a vector of Luggage objects passed by value
         */
        Passenger(string name, short int age, char gender, string passportNumber, vector<Luggage> luggage);

        /**
         * Set Passenger passport number
         * @param passportNumber Passenger's new passport number, a string passed by reference
         */
        void setPassportNumber(const string &passportNumber);

        /**
         * Set Passenger luggage
         * @param luggage Passenger's new luggage, a vector with Luggage objects passed reference
         */
        void setLuggage(const vector<Luggage> &luggage);

        /**
         * Returns Passenger's passport number
         * @return a string, containing passenger's passport number
         */
        string getPassportNumber() const;

        /**
         * Returns Passenger's luggage
         * @return a vector, containing passenger's luggage objects
         */
        vector<Luggage> getLuggage() const;

        /**
         * Returns total weight of Passenger's luggage
         * @return an integer value, containing passenger's luggage total weight
         */
        int getTotalWeight() const;

        /**
         * Returns total volume of Passenger's luggage
         * @return an integer value, containing passenger's luggage total volume
         */
        int getTotalVolume() const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param passenger another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Passenger &passenger) const;

        /**
         * @overload
        * Boolean function that compares two objects of this class
        * @param passenger another object that will be compared
        * @return if the current object is less than object passed by reference
        */
        bool operator < (const Passenger &passenger) const;

        /**
         * Boolean function thar compares to objects of this class, based on their Name
         * @param p1 first person that will be compared
         * @param p2 second person that will be compared
         * @return if p1 has less name than p2, based on alphabetic order
         */
        friend bool byName(const Passenger &p1, const Passenger &p2);

        /**
        * Boolean function thar compares to objects of this class, based on their age
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less age than p2
        */
        friend bool byAge(const Passenger &p1, const Passenger &p2);

        /**
        * Boolean function thar compares to objects of this class, based on their total luggage's weight
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less luggage weight than p2
        */
        friend bool byLuggage(const Passenger &p1, const Passenger &p2);
};

/**
 * @overload
 * Function that returns all characteristics of the Passenger being manipulated
 * @param os ostream object, passed by reference
 * @param passenger Passenger object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Passenger &passenger);

#endif //PROJECT_AED_PASSENGER_H