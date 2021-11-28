#ifndef PROJET_AED_PLANE_H
#define PROJET_AED_PLANE_H

#include <string>
#include <utility>
#include <list>
#include <iostream>
#include <iterator>
#include "Flight.h"

/**
 * A class to manage an Plane.
 */
class Plane {
private:
    /**
     * @var licensePlate - string variable that holds the Plane's license plate in the form "XX-XXX"
     * where each X is a letter.
     */
    const std::string LICENSE_PLATE;

    /**
     * @var type - string variable that holds the Plane's type in the form "AXXX" where each X is a number.
     */
    const std::string TYPE;

    /**
     * @var MAX_WEIGHT_CAPACITY - constant that holds the plane's maximum weight capacity.
     */
    const unsigned int MAX_WEIGHT_CAPACITY;

    /**
     * @var MAX_PASSENGERS_CAPACITY - constant that holds the plane's maximum passengers capacity.
     */
    const unsigned short int MAX_PASSENGERS_CAPACITY;

    /**
     * @var flights - vector that holds all the flights programmed for the specific plane.
     */
    std::list<Flight> flights;

public:
    /**
     * Main constructor
     * @param flights - a list that contains Flight type objects
     * @param LICENSE_PLATE - a string containing license plate of the plane
     * @param TYPE - a string containing the type of the plane
     * @param MAX_WEIGHT_CAPACITY - a int constant containing the max weight capacity of the plane
     * @param MAX_PASSENGERS_CAPACITY - a int constant containing the max people capacity of the plane
     */
    Plane(std::list<Flight> flights,std::string LICENSE_PLATE, std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY, unsigned int MAX_PASSENGERS_CAPACITY);
    /**
     * Returns the plane's license plate
     * @return a string, containing the plane's license plate
     */
    std::string getLicensePlate() const;
    /**
     * Returns the plane's type
     * @return a string, containing the plane's type
     */
    std::string getType() const;
    /**
     * Returns the plane's maximum weight capacity
     * @return a string, containing the plane's maximum weight capacity
     */
    unsigned int getMaxWeightCapacity() const;
    /**
     * Returns the plane's maximum passengers capacity
     * @return a string, containing the plane's maximum passengers capacity
     */
    unsigned int getMaxPassengersCapacity() const;
    /**
     * Prints all flights of the plane
     */
    void checkFlights() const;
    /**
     * Function that add a flight into vector flights
     * @param flight - A Flight type object that will be added to vector flights
     */
    void addFlight(Flight flight);
    /**
     * Functions that remove a flight from vector flights
     * @param flight - A Flight type object thar will be removed to vector flights
     */
    void removeFlight(Flight flight);

    // plane1 == plane2
    // plane1 < plane2 --> capacity
    // cout << plane --> com todos os atributos
};

#endif //PROJET_AED_PLANE_H
