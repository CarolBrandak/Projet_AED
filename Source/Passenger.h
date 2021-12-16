#ifndef PROJECT_AED_PASSENGER_H
#define PROJECT_AED_PASSENGER_H

#include <vector>
#include "Person.h"
#include "Luggage.h"

/**
 * Person's derived class
 */
class Passenger : public Person {

    private:

        /**
         * @var id, a string
         */
        const string ID;

        /**
         * @var PASSPORT, a string
         */
        const string PASSPORT;

        /**
         * @var luggage, a vector with Luggage's objects
         */
        vector<Luggage*> luggage;

    public:

        /**
         * A default constructor of class Passenger. No arguments needed.
         */
        Passenger();

        /**
         * A default destructor of class Passenger
         */
        ~Passenger();

        /**
         * Main constructor
         * @param id Passengers id, a string passed by value
         * @param name Passenger's name, a string passed by value
         * @param age Passenger's age, a short integer passed by value
         * @param gender Passenger's gender, a char passed by value
         * @param passportNumber Passenger's passport number, a string passed by value
         */
        Passenger(string id, string name, short int age, char gender, string passportNumber);

        /**
         * Set Passenger luggage
         * @param luggages Passenger's new luggage, a vector with Luggage objects passed reference
         */
        void addLuggage(Luggage &luggage);

        /**
         * Returns Passenger's id
         * @returns a string, containing passenger's id
         */
         string getID() const;

        /**
         * Returns Passenger's passport number
         * @return a string, containing passenger's passport number
         */
        string getPassportNumber() const;

        /**
         * Returns Passenger's luggage
         * @return a vector, containing passenger's luggage objects
         */
        vector<Luggage*> getLuggage() const;

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
         * A function that removes luggage from the current Passenger
         * @param l - Luggage object that will be removed
         */
        void removeLuggage(Luggage* l);

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
         * @overload
         * Function that returns all characteristics of the Passenger being manipulated
         * @param os ostream object, passed by reference
         * @param passenger Passenger object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Passenger &passenger);
};

#endif //PROJECT_AED_PASSENGER_H