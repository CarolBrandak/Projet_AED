#ifndef PROJET_AED_FLIGHT_H
#define PROJET_AED_FLIGHT_H

#include "Date.h"
#include "Passenger.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * A struct that defines a location
 * @var city - a string, that defines a city
 * @var airport - a string, that defines an airport
 */
struct Location {
        std::string city;
        std::string airport;
};
/**
 * A class to manage flights
 */
class Flight{
private:
    /**
     * @var FLIGHT_ID - a string constant variable that contains the ID of the flight
     */
    const std::string FLIGHT_ID;
    /**
     * @var flightDate - a Date type object that contains the date of the flight
     */
    Date flightDate;
    /**
     * @var FLIGHT_DURATION - a short int constant variable that contains the flight's duration in minutes
     */
    const short int FLIGHT_DURATION;
    /**
     * @var origin - a Location type struct that contains the origin of the flight
     */
    const Location origin;
    /**
     * @var destination - a Location type struct that contains the destination of the flight
     */
    const Location destination;
    /**
     * @var quantityOfPassengers - a short int variable that contains the quantity of passengers in the flight
     */
    short int quantityOfPassengers;
    /**
     * @var quantityOfWeight - a short int variable that contains the quantity of weight in the flight
     */
    short int quantityOfWeight;
    /**
     * @var passengers - a Passenger type vector that contains the data of all passengers in the flight
     */
    std::vector<Passenger> passengers;

public:
    /**
     * A default constructor
     */
    Flight();
    /**
     * Main constructor
     * @param flightDate - a Date type object that contains the date of the flight
     * @param FLIGHT_ID - a string constant variable thar contains the ID of the flight
     * @param FLIGHT_DURATION - a short int constant variable that contains the flight's duration in minutes
     * @param origin - a Location type struct that contains the origin of the flight
     * @param destination - a Location type struct that contains the destination of the flight
     * @param quantityOfPassengers - a short int variable that contains the quantity of passengers in the flight
     * @param quantityOfWeight - a short int variable that contains the quantity of weight in the flight
     */
    Flight(Date flightDate, std::string flightID, short int flightDuration, Location origin, Location destination,
           short int quantityOfPassengers, short int quantityOfWeight, vector<Passenger> passengers);
    /**
     * Returns the flight id
     * @return a string type, containing the flight's ID
     */
    std::string getFlightID() const;
    /**
     * Returns the flight date
     * @return an Date type object, containing the flight date
     */
    Date getFlightDate() const;
    /**
     * Sets the new date of the flight
     * @param newDate - a Date type object that contains the new date of the flight
     */
    void setFlightDate(const Date &newDate);
    /**
     * Returns the flight duration in minutes
     * @return an short int, containing the flight duration in minutes
     */
    short int getFlightDuration() const;
    /**
     * Returns the flight origin in a Location type struct
     * @return a Location type struct, containing the flight origin
     */
    Location getFlightOrigin() const;
    /**
     * Returns the flight destination
     * @return a Location type struct, containing the flight destination
     */
    Location getFlightDestination() const;

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
     * Adds a passenger to the flight
     * @param passenger
     * @return a boolean value that indicates if passenger was added or not
     */
    bool addPassenger(const Passenger& passenger, const int &MAX_PASSENGERS_CAPACITY, const int &MAX_WEIGHT_CAPACITY);
    /**
     * Removes a passenger to the flight
     * @param passenger
     * @return a boolean that indicates if passenger was removed or not
     */
    bool removePassenger(const Passenger &passenger);
    /**
     * Prints out the information of all passengers
     */
    void checkPassengers() const;
    /**
     * Prints out the information of one specific passenger
     * @param passenger
     */
    void checkPassenger(const Passenger& passenger) const;

    /**
     * @overload
     * Boolean function that compares two objects of this class
     * @param flight another object that will be compared
     * @return if the current object is equal to the object passed by reference
     */
    bool operator == (const Flight &flight) const;

};

/**
     * @overload
     * Function that returns all characteristics of the Employee being manipulated
     * @param os ostream object, passed by reference
     * @param Employee Employee object, passed by reference
     * @return ostream object
     */
ostream & operator << (ostream & os, const Flight &flight);

#endif //PROJET_AED_FLIGHT_H
