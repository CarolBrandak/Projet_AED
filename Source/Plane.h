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
         * @var id - string variable that contains the Plane's id
         */
         const string ID;

        /**
         * @var licensePlate - string variable that contains the Plane's license plate in the form "XX-XXX"
         * where each X is a letter.
         */
         const string LICENSE_PLATE;

        /**
         * @var type - string variable that contains the Plane's type in the form "LXXX" where each X is a number
         * and L is a letter
         */
         const string TYPE;

        /**
         * @var MAX_WEIGHT_CAPACITY - constant that contains the plane's maximum weight capacity.
         */
         const unsigned int MAX_WEIGHT_CAPACITY;

        /**
         * @var MAX_PASSENGERS_CAPACITY - constant that contains the plane's maximum passengers capacity.
         */
         const unsigned int MAX_PASSENGERS_CAPACITY;

        /**
         * @var flights - list that contains all the flights programmed for the specific plane.
         */
        list<Flight*> flights;

        /**
         * @var servicesToBeMade - queue that contains all the services to be made to the plane
         */
        queue<Service*> servicesToBeMade;

        /**
         * @var madeServices - list that contains all the services that were made to the plane
         */
        list<Service*> madeServices;

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
         * Returns the plane's Services
         * @return a queue of Service objects
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
         * @param flight - A Flight type object that will be removed to vector flights
         */
        void removeFlight(Flight &flight);

        /**
         * Adds a service to the queue of services
         * @param service - a Service type object to be added to the queue of services
         */
        void addService(Service &service);

        /**
         * A bool function that returns if the flight passed by parameter exists in this plane
         * @param flight - a Flight object that will be searched
         * @return if flight exists in current plane
         */
        Flight* findFlight(const string &origin, const string &destination);

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

        int getNextFlightID();

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
        * Boolean function thar compares to objects of this class, based on their total weight capacity
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less weight capacity than p2
        */
        friend bool byMaximumWeight(const Plane &p1, const Plane &p2);

        /**
        * Boolean function thar compares to objects of this class, based on their total capacity
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less capacity than p2
        */
        friend bool byMaximumCapacity(const Plane &p1, const Plane &p2);

        /**
        * Boolean function thar compares to objects of this class, based on their total number of flights
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less flights than p2
        */
        friend bool byNumberOfFlights(const Plane &p1, const Plane &p2);

        /**
        * Boolean function thar compares to objects of this class, based on their total number of services
        * @param p1 first person that will be compared
        * @param p2 second person that will be compared
        * @return if p1 has less services than p2
        */
        friend bool byNumberOfServices(const Plane &p1, const Plane &p2);
};

/**
 * @overload
 * Function that returns all characteristics of the Plane being manipulated
 * @param os ostream object, passed by reference
 * @param plane Plane object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Plane &plane);

#endif // PROJECT_AED_PLANE_H