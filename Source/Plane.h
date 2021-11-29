#ifndef PROJET_AED_PLANE_H
#define PROJET_AED_PLANE_H

#include <string>
#include <utility>
#include <list>
#include <iostream>
#include <iterator>
#include <queue>

#include "Flight.h"
#include "Service.h"

/**
 * A class to manage an Plane.
 */
class Plane {

    private:

        /**
         * @var licensePlate - string variable that contains the Plane's license plate in the form "XX-XXX"
         * where each X is a letter.
         */
         std::string LICENSE_PLATE;

        /**
         * @var type - string variable that contains the Plane's type in the form "AXXX" where each X is a number.
         */
         std::string TYPE;

        /**
         * @var MAX_WEIGHT_CAPACITY - constant that contains the plane's maximum weight capacity.
         */
         unsigned int MAX_WEIGHT_CAPACITY;

        /**
         * @var MAX_PASSENGERS_CAPACITY - constant that contains the plane's maximum passengers capacity.
         */
         unsigned int MAX_PASSENGERS_CAPACITY;

        /**
         * @var flights - list that contains all the flights programmed for the specific plane.
         */
        std::list<Flight> flights;

        /**
         * @var servicesToBeMade - queue that contains all the services to be made to the plane
         */
        std::queue<Service> servicesToBeMade;

        /**
         * @var madeServices - list that contains all the services that were made to the plane
         */
        std::list<Service> madeServices;
    
    public:

        /**
         * A default constructor
         */
        Plane();

        /**
         * Main constructor
         * @param flights - a list that contains Flight type objects
         * @param LICENSE_PLATE - a string containing license plate of the plane
         * @param TYPE - a string containing the type of the plane
         * @param MAX_WEIGHT_CAPACITY - a int constant containing the max weight capacity of the plane
         * @param MAX_PASSENGERS_CAPACITY - a int constant containing the max people capacity of the plane
         */
        Plane(std::list<Flight> flights,std::queue<Service> servicesToBeMade,std::list<Service> madeServices,std::string LICENSE_PLATE, std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY, unsigned int MAX_PASSENGERS_CAPACITY);

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
         * Returns the plane's list of flights
         * @return a list of flights to do
         */
        list<Flight> getFlights() const;

        /**
        * Returns the plane's maximum weight capacity
        * @return a unsigned int, containing the plane's maximum weight capacity
        */
        unsigned int getMaxWeightCapacity() const;

        /**
         * Returns the plane's maximum passengers capacity
         * @return a unsigned int, containing the plane's maximum passengers capacity
         */
        unsigned int getMaxPassengersCapacity() const;

        /**
         * Returns the number of flights
         * @return an unsigned, containing the number of flights
         */
        unsigned int getQuantityOfFlights() const;

        /**
         * Returns the number of services to be made
         * @return an integer, containing the number of services to be made
         */
        unsigned int getQuantityOfServicesToBeMade() const;

        /**
         * Returns the number of services done
         * @return an integer, containing the number of services done
         */
        unsigned int getQuantityOfMadeServices() const;

        /**
         * Prints all flights of the plane
         */
        void checkFlights();

        /**
         * Function that add a flight into vector flights
         * @param flight - A Flight type object that will be added to vector flights
         */
        void addFlight(const Flight &flight);

        /**
         * Functions that remove a flight from vector flights
         * @param flight - A Flight type object that will be removed to vector flights
         */
        void removeFlight(const Flight &flight);

        /**
         * Adds a service to the queue of services
         * @param service - a Service type object to be added to the queue of services
         */
        void addService(const Service &service);

        /**
         * Sets a service as done by popping it from the servicesToBeMade queue and adding it
         * to the madeServices list.
         */
        void setNextServiceAsDone();

        /**
         * Prints out all the services to be made
         */
        void checkServicesToBeMade();

        /**
         * Prints out all the made services
         */
        void checkMadeServices();

        /**
         * @overload
         * Boolean function that compares 2 objects of this class
         * @param plane - object to be compared
         * @return true, if objects are the same, false if they are different
         */
        bool operator == (const Plane &plane) const ;

        /**
         * @overload
         * Boolean function that compares 2 objects of this class
         * @param plane - object to be compared
         * @return true, if
         */
        bool operator < (const Plane &plane) const ;
};


ostream & operator << (ostream & os, const Plane &plane);

#endif //PROJET_AED_PLANE_H