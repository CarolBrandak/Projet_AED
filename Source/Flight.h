#pragma once
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

class Cart;

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
          * @var cart - A useful class for moving passengers' luggage
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
         * Return all transports in current flight
         * @return a vector with pointers to Transport objects
         */
         vector<Transport*> getAllTransports();

        /**
         * Prints out the information of all passengers
         */
        void checkPassengers();

        /**
         * A function that add a new transport in destination's airport
         * @param transport - a Transport object passed by pointer
         */
        void addTransport(Transport* transport);

        /**
         * A function that remove a transport in destination's airport
         * @param transport - a Transport object passed by pointer
         */
        void removeTransport(Transport* transport);

        /**
         * @overload
         * A functions that returns the transport with wanted time
         * @param hour - a integer value passed by reference containing the wanted hour
         * @param minute - a integer value passed by reference containing the wanted minute
         * @return a Transport pointer object
         */
        Transport* searchTransport(const int &hour, const int &minute);

        /**
         * @overload
         * A function that returns all the transports with wanted type
         * @param type - a string value passed by reference containing the wanted type
         * @return a vector with Transport pointer objects
         */
        vector<Transport*> searchTransport(const string &type);

        /**
         * @overload
         * A function that returns all the transports with wanted distance
         * @param distance - an integer value passed by reference containing the wanted distance
         * @return a Transport pointer object
         */
        Transport* searchTransport(const int &distance);

        /**
         * @overload
         * Adds passengers to the flight
         * @param passenger - Passenger object that will be added in the current flight
         */
        void addPassenger(Passenger& passenger);

        /**
         * @overload
         * Adds passengers to the flight
         * @param passengers - Passenger type vector that contains all passengers that will be added in flight
         */
        void addPassenger(const vector<Passenger*>& allPassengers);

        /**
         * Removes a passenger to the flight
         * @param passenger - Passenger type object that will be removed from flights
         */
        void removePassenger(Passenger &passenger);

        /**
         * A function that finds a passenger based in its passport
         * @param passport - a string passed by reference that contains the passenger's passport
         * @return a Passenger pointer object
         */
        Passenger* findPassenger(const string &passport);

        /**
         * Adds luggage to the flight
         * @param l - a Luggage object passed by pointer that will be added
         */
        void addLuggage(Luggage *l);

        /**
         * Removes luggage from the flight
         * @param id - a string passed by reference that contains a luggage's id
         */
        void removeLuggage(const string &id);

        /**
         * Find luggage in the flight based on its id
         * @param id - a string passed by reference that contains a luggage's id
         * @return a Luggage pointer object
         */
        Luggage* findLuggage(const string &id);

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
         * @overload
         * Function that returns all characteristics of the Flight being manipulated
         * @param os ostream object, passed by reference
         * @param flight object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Flight &flight);
};

#endif // PROJECT_AED_FLIGHT_H