#ifndef PROJECT_AED_AIRPORT_H
#define PROJECT_AED_AIRPORT_H

#include <iostream>
#include <vector>
#include <string>

#include "Flight.h"
#include "Passenger.h"
#include "Plane.h"

/**
 * A class to manage an Airport
 */
class Airport {

    private:

        /**
         * @var id - a constant string containing Airport's id
         */
        string id;

        /**
         * @var name - a constant string containing Airport's name
         */
        string name;

        /**
         * @var city - a constant string containing the name of the city where the airport is
         */
        string city;

        /**
         * @var planes - vector with Plane objects
         */
        vector<Plane> planes;

    public:

        /**
         * A default constructor of class
         */
        Airport();

        /**
         * Main constructor
         * @param id - a string containing airport's id
         * @param name - a string containing airport's name
         * @param city - a string containing airport's city
         */
        Airport(string id, string name, string city);

        /**
         * Returns the airport's id
         * @return a string containing the airport's id
         */
        string getID() const;

        /**
         * Returns the airport's name
         * @return a string containing the airport's name
         */
        string getName() const;

        /**
         * Returns the airport's city
         * @return a string containing the airport's city
         */
        string getCity() const;

        /**
         * Returns all airport's planes
         * @return a vector with Plane objects
         */
        vector<Plane> getPlanes() const;

        /**
         * Returns all possible flights, filtered by destination city and arrival date
         * @param city - a string containing a city to search
         * @param date - a Date object to search
         * @return a vector of Flight objects that matches the requirements
         */
        vector<Flight> getPossibleFlights(const string &city, const Date &date) const;

        /**
         * Prints all planes of the airport
         */
        void checkPlanes();

        /**
         * Void function that add a plane into vector planes
         * @param plane - a Plane object that will added in current airport
         */
        void addPlane(const Plane &plane);

        /**
         * Void function that remove a plane from current airport
         * @param plane - a Plane object that will be removed
         */
        void removePlane(const Plane &plane);

        /**
         * Prints out all the the possible Flights
         * @param possibleFlights - a vector with Flights that will be printed
         */
        void showPossibleFlights(const vector<Flight> &possibleFlights);

        /**
         * A boolean function that tries to buy a ticket
         * @param flight - a Flight object that the passengers wants
         * @param passengers - vector of Passengers objects that will buy a ticket
         * @return if the purchase was successful
         */
        bool buyTicket(Flight flight, const vector<Passenger> &passengers);

        /**
        * @overload
        * Boolean function that compares 2 objects of this class
        * @param airport - object to be compared
        * @return true, if objects are the same, false if they are different
        */
        bool operator == (const Airport &airport) const;

        /**
        * @overload
        * Boolean function that compares 2 objects of this class
        * @param airport - object to be compared
        * @return true, if objects has less planes than other
        */
        bool operator < (const Airport &airport) const;

        /**
        * Boolean function that compares to objects of this class, based on their names
        * @param a1 first airport that will be compared
        * @param a2 second airport that will be compared
        * @return if a1 has less name than a2, based on alphabetic order
        */
        friend bool byName(const Airport &a1, const Airport &a2);

        /**
        * Boolean function that compares to objects of this class, based on their planes
        * @param a1 first airport that will be compared
        * @param a2 second airport that will be compared
        * @return if a1 has less planes than a2
        */
        friend bool byQuantityOfPlanes(const Airport &a1, const Airport&a2);
};

/**
 * @overload
 * Function that returns all characteristics of the Airport being manipulated
 * @param os ostream object, passed by reference
 * @param airport object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Airport &airport);

#endif // PROJECT_AED_AIRPORT_H