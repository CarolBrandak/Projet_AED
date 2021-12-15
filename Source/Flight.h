#ifndef PROJECT_AED_FLIGHT_H
#define PROJECT_AED_FLIGHT_H

#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <stack>
#include <queue>
#include <list>
#include "Passenger.h"
#include "Airport.h"
#include "Transport.h"
#include "Cart.h"
#include "BST.h"

/**
 * A class to manage flights
 */
class Flight {

    private:

        /**
         * @var ID - a string constant variable that contains the ID of the flight
         */
        const string ID;

        /**
         * @var FLIGHT_DATE - a const Date type object that contains the date of the flight
         */
        const Date FLIGHT_DATE;

        /**
         * @var FLIGHT_DURATION - a short int constant variable that contains the flight's duration in minutes
         */
        const short int FLIGHT_DURATION;

        /**
         * @var origin - a const string that contains the origin of the flight
         */
        const string ORIGIN;

        /**
         * @var airport - a Airport object that contains the destination ans transports of the flight
         */
         Airport airport;

        /**
         * @var quantityOfPassengers - a short int variable that contains the current quantity of passengers in the flight
         */
        short int quantityOfPassengers;

        /**
         * @var quantityOfWeight - a short int variable that contains the current quantity of weight in the flight
         */
        short int quantityOfWeight;

        /**
         * @var passengers - a Passenger type vector that contains all passengers in the flight
         */
        vector<Passenger*> passengers;

        /**
         * @var luggage - a Luggage type vector that contains all luggage in the flight
         */
        vector<Luggage*> luggage;

        /**
         * @var nextID - an integer value that contains the next Passenger ID in the flight
         */
        int nextID;

         /**
          * A friend useful class for moving passengers' luggage
          */
        friend class Cart;

    public:

        /**
         * A default constructor
         */
         Flight();

        /**
         * A default destructor
         */
        ~Flight();

        /**
         * Main constructor
         * @param ID - a string constant variable thar contains the ID of the flight
         * @param FLIGHT_DATE - a Date type object that contains the date of the flight
         * @param FLIGHT_DURATION - a short int constant variable that contains the flight's duration in minutes
         * @param ORIGIN - a string that contains the origin of the flight
         * @param airport - an Airport object that contains the destination of the flight and all transports
         */
        Flight(string id, Date flightDate, short int flightDuration, string origin, Airport airport);

        /**
         * Returns the flight id
         * @return a string type, containing the flight's ID
         */
        string getID() const;

        /**
         * Returns the flight date
         * @return an Date type object, containing the flight date
         */
        Date getFlightDate() const;

        /**
         * Returns the flight duration in minutes
         * @return an short int, containing the flight duration in minutes
         */
        short int getFlightDuration() const;

        /**
         * Returns the flight origin in a Location type struct
         * @return a string, containing the flight origin
         */
        string getFlightOrigin() const;

        /**
         * Returns the flight destination
         * @return a string, containing the flight destination
         */
        string getFlightDestination() const ;

        /**
         * Returns the flight' destination Airport object
         * @return an Airport object, containing destination city and all transports
         */
        Airport getAirport();

        /**
         * Returns the quantity of weight inside the plane
         * @return a string, containing the plane's weight quantity
         */
        unsigned int getWeightQuantity() const;

        /**
         * Returns the quantity of people inside the plane
         * @return an unsigned int, containing the quantity of people inside the plane
         */
        unsigned int getPassengersQuantity() const;

        /**
        * Return all passengers in current flight
        * @return a vector with pointers to Passenger objects
        */
        vector<Passenger*> getPassengers() const;

        /**
         * Return all luggage in current flight
         * @return a vector with pointers to Luggage objects
         */
        vector<Luggage*> getLuggage() const;

        /**
         * Generate and returns the next Passenger's ID based on last Passengers
         * @return a string, containing the next id
         */
        string getNextPassengerID();

        /**
         * Prints out the information of all passengers
         */
        void checkPassengers();

        /**
         *
         * @param transport
         */
        void addTransport(Transport* transport);

        void removeTransport(Transport* transport);

        void addTransport(Transport *transport);

        /**
         * Adds passengers to the flight
         * @param toPush - Passenger type vector that contains all passengers that will be added in flight
         */
        void addPassenger(Passenger& passenger);

        /**
        * Adds passengers to the flight
        * @param toPush - Passenger type vector that contains all passengers that will be added in flight
        */
        void addPassengers(const vector<Passenger*>& toPush);

        /**
         * Removes a passenger to the flight
         * @param passenger - Passenger type object that will be removed from flights
         */
        void removePassenger(Passenger &passenger);




        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param flight another object that will be compared
         * @return if the current object is equal to the object passed by reference
         */
        bool operator == (const Flight &flight) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param flight another object that will be compared
         * @return if the current object is equal to the object passed by reference
         */
        bool operator < (const Flight &flight) const;

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
};

/**
* @overload
* Function that returns all characteristics of the Flight being manipulated
* @param os ostream object, passed by reference
* @param flight object, passed by reference
* @return ostream object
*/
ostream & operator << (ostream & os, const Flight &flight);

#endif // PROJECT_AED_FLIGHT_H