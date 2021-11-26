#ifndef Passenger_H
#define Passenger_H

#include "Person.h"

/**
 * Person's derived class
 */
class Passenger : public Person {

    private string passportNumber;
    private vector<Luggage> passengerLuggage;

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
         * @param passengerLuggage Passenger's luggage, a vector of Luggage objects passed by value
         */
        Passenger(string name, short int age, char gender, string passportNumber, vector<Luggage> passengerLuggage);

        /**
         * Set Passenger passport number
         * @param passportNumber Passenger's new passport number, a string passed by value
         */
        void setPassportNumber(string passportNumber);

        /**
         * Set Passenger luggage
         * @param passengerLuggage Passenger's new luggage, a vector with Luggage objects passed value
         */
        void setPassengerLuggage(vector<Luggage> passengerLuggage);

        /**
         * Returns Passenger's passport number
         * @return a string, containing passenger's passport number
         */
        string getPassportNumber();

        /**
         * Returns Passenger's luggage
         * @return a vector, containing passenger's luggage objects
         */
        vector<Luggage> getPassengerLuggage();

        /**
         * Boolean function that compares two objects of this class
         * @param passenger another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Passenger &passenger) const;

        /**
        * Boolean function that compares two objects of this class
        * @param passenger another object that will be compared
        * @return if the current object is less than object passed by reference
        */
        bool operator < (const Passenger &passenger) const;
};

/**
 * Function that returns all characteristics of the Object being manipulated
 * @param os ostream object, passed by reference
 * @param passenger Passenger object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Passenger &passenger);

#endif // Passenger_H