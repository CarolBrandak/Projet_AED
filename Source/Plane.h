#ifndef PROJECT_AED_PLANE_H
#define PROJECT_AED_PLANE_H

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
         * @var ID - a constant string that contains the Plane's id
         */
         const string ID;

        /**
         * @var LICENCE_PLATE a constant string that contains the Plane's license plate in the form "XX-XXX"
         * where each X is a letter.
         */
         const string LICENSE_PLATE;

        /**
         * @var TYPE - a string constant that contains the Plane's type in the form "LXXX" where each X is a number
         * and L is a letter
         */
         const string TYPE;

        /**
         * @var MAX_WEIGHT_CAPACITY - an unsigned integer constant that contains the plane's maximum weight capacity.
         */
         const unsigned int MAX_WEIGHT_CAPACITY;

        /**
         * @var MAX_PASSENGERS_CAPACITY - an unsigned integer constant that contains the plane's maximum passengers capacity.
         */
         const unsigned int MAX_PASSENGERS_CAPACITY;

        /**
         * @var flights - a list that contains all the flights programmed for the specific plane.
         */
        list<Flight*> flights;

        /**
         * @var servicesToBeMade - a queue that contains all the services to be made to the plane
         */
        queue<Service*> servicesToBeMade;

        /**
         * @var madeServices - a list that contains all the services that were made to the plane
         */
        list<Service*> madeServices;

        /**
         * @var nextFlightID - an integer containing the next Flight ID, based on past included Flight
         */
        int nextFlightID;
    
    public:

        /**
         * A default constructor
         */
        Plane();

        /**
         * A default destructor
         */
        ~Plane();

        /**
         * Main constructor
         * @param ID - a Plane's id
         * @param LICENSE_PLATE - a string containing license plate of the plane
         * @param TYPE - a string containing the type of the plane
         * @param MAX_WEIGHT_CAPACITY - a int constant containing the max weight capacity of the plane
         * @param MAX_PASSENGERS_CAPACITY - a int constant containing the max people capacity of the plane
         */
        Plane (string ID, string LICENSE_PLATE, string TYPE, unsigned int MAX_WEIGHT_CAPACITY, unsigned int MAX_PASSENGERS_CAPACITY);

        /**
         * Returns Plane's ID
         * @returns a string, containing plane's id
         */
         string getID() const;

        /**
         * Returns the plane's license plate
         * @return a string, containing the plane's license plate
         */
        string getLicensePlate() const;

        /**
         * Returns the plane's type
         * @return a string, containing the plane's type
         */
        string getType() const;

        /**
         * Returns the plane's list of flights
         * @return a list of flights to do
         */
        list<Flight*> getFlights() const;

        /**
         * Returns the plane's vector of flights
         * @return a list of flights to do
        */
        vector<Flight*> getVectorFlights() const;

        /**
         * Returns the plane's Services
         * @return a vector of Service objects
         */
        vector<Service*> getServices() const;

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
         * A function to generate and get the next Flight id of the sequence based on previous inclusions
         * @return a string containing the next
         */
        string getNextFlightID();

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
         * Prints all flights of the plane
         */
        void checkFlights();

        /**
         * Function that add a flight into vector flights
         * @param flight - A Flight type object that will be added to vector flights
         */
        void addFlight(Flight &flight);

        /**
         * Functions that remove a flight from vector flights
         * @param id - a string passed by reference used to locate a certain Flight object
         */
        void removeFlight(const string &id);

        /**
         * A bool function that returns if the flight passed by parameter exists in this plane
         * @param flight - a Flight object that will be searched
         * @return if flight exists in current plane
         */
        Flight* findFlight(const string &origin, const string &destination);

        /**
         * Adds a service to the queue of services
         * @param service - a Service type object to be added to the queue of services
         */
        void addService(Service &service);

        /**
         * A function that try to find a Service based on its date
         * @param date - a Date object passed by reference containing the date of wanted service
         * @return a Service pointer object
         */
        Service* findService(Date &date);

        /**
         * A function that try to find a Employee based on its name
         * @param name - a string passed by reference containing the name of wanted Employee
         * @return a Employee pointer object
         */
        Employee* findEmployee(const string &name);

        /**
         * A function that returns all Employees of current Plane
         * @return a vector with Employees pointer objects
         */
        vector<Employee*> getEmployees();

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
         * @return true, if first plane has less weight than second plane
         */
        bool operator < (const Plane &plane) const ;

        /**
         * @overload
         * Function that returns all characteristics of the Plane being manipulated
         * @param os ostream object, passed by reference
         * @param plane Plane object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Plane &plane);
};

#endif // PROJECT_AED_PLANE_H