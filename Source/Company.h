#ifndef PROJECT_AED_COMPANY_H
#define PROJECT_AED_COMPANY_H

/**
 * Directories of all backup files
 */
#define FLIGHT_FILE "../Source/Files/Flights.txt"
#define LUGGAGE_FILE "../Source/Files/Luggages.txt"
#define PASSENGER_FILE "../Source/Files/Passengers.txt"
#define PLANE_FILE "../Source/Files/Planes.txt"
#define SERVICE_FILE "../Source/Files/Services.txt"
#define TRANSPORT_FILE "../Source/Files/Transports.txt"

#include <fstream>
#include <algorithm>
#include "Plane.h"
#include "Exceptions.h"

/**
 A class to manage a Company
 */
class Company {

    private:

        /**
         * @var name - a constant string containing the name of the current company
         */
        const string NAME;

        /**
         * @var nextPlaneID - an integer value that contain the next unique Plane ID, based on
         *                    the previous insertions
         */
        int nextPlaneID;

        /**
         * @var allPlanes - a vector with Plane pointer objects that contains all planes
         *                  and information of the application
         */
        vector<Plane*> allPlanes;

        /**
         * @var allFlights - a vector with Flights pointer objects that contains all flights of the application
         */
        vector<Flight*> allFlights;

        /**
        * @var allPassengers - a vector with Passengers pointer objects that contains all passengers of the application
        */
        vector<Passenger*> allPassengers;

        /**
        * @var allLuggage - a vector with Luggage pointer objects that contains all luggage of the application
        */
        vector<Luggage*> allLuggage;

        /**
        * @var allServices - a vector with Services pointer objects that contains all service of the application
        */
        vector<Service*> allServices;

        /**
        * @var allTransports - a vector with Transports pointer objects that contains all transports of the application
        */
        vector<Transport*> allTransports;

    public:

        /**
         * A default constructor of the class. No arguments needed
         */
        Company();

        /**
         * A default destructor of the class
         */
        ~Company();

        /**
         * Main constructor of the class.
         * @param name - a string containing the Company name
         */
        explicit Company(string name);

        /**
         * A void function that presents the company for the user
         */
        void presentation();

        /**
         * Returns the current name of the Company
         * @return a string containing the Company's name
         */
        string getName() const;

        /**
         * Returns the next and unique Plane ID, based on previous insertions
         * @return a string containing the next plane ID
         */
        string getNextPlaneID();

        /**
         * Returns all Planes of the system
         * @return a vector containing Plane pointer objects
        */
        vector<Plane*> getAllPlanes() const;

        /**
         * Returns all Luggages of the system
         * @return a vector containing Luggage pointer objects
         */
        vector<Luggage*> getAllLuggages() const;

        /**
        * Returns all Passengers of the system
        * @return a vector containing Passengers pointer objects
        */
        vector<Passenger*> getAllPassengers() const;

        /**
        * Returns all Services of the system
        * @return a vector containing Service pointer objects
        */
        vector<Service*> getAllServices() const;

        /**
        * Returns all Transports of the system
        * @return a vector containing Transport pointer objects
        */
        vector<Transport*> getAllTransports() const;

        /**
        * Returns all Flights of the system, by reading files
        * @return a vector containing Flight pointer objects
        */
        vector<Flight*> getAllFlights() const;

        /**
         * Void function that reads from a file all the characteristics of the Flights
         */
        void readFlights();

        /**
        * Void function that reads from a file all the characteristics of the Luggage
        */
        void readLuggage();

        /**
        * Void function that reads from a file all the characteristics of the Passengers
        */
        void readPassengers();

        /**
        * Void function that reads from a file all the characteristics of the Planes
        */
        void readPlanes();

        /**
        * Void function that reads from a file all the characteristics of the Services
        */
        void readServices();

        /**
        * Void function that reads from a file all the characteristics of the Transports
        */
        void readTransports();

        /**
         * A function that saves in correspondent file all Luggage data
         * @param luggage - a vector with Luggage pointer object that will be saved
         */
        void saveLuggage();

        /**
         * A function that saves in correspondent file all Passengers data
         */
        void savePassengers();

        /**
         * A function that saves in correspondent file all Flights data
         */
        void saveFlights();

        /**
         * A function that saves in correspondent file all Services data
         */
        void saveServices();

        /**
         * A function that saves in correspondent file all Planes data
         */
        void savePlanes();

        /**
         * A function that saves in correspondent file all Transports data
         */
        void saveTransports();

        /**
         * A function that adds a new plane in current Company
         * @param plane - a Plane object that will be added in current Company
         */
        void addPlane(Plane &plane);

        /**
         * A function that remove a plane from the current Company, based on its id
         * @param id - a string corresponding to the Plane id that will be removed from current Company
         */
        bool removePlane(const string &id);

        /**
         * Finds a plane in current Company based on its id
         * @param id - a string passed by reference containing the wanted Plane's id
         * @return a Plane pointer object
         */
        Plane* findPlane(const string &id);

        /**
         * Finds a flight in Company based on its origin and destination
         * @param origin - a string passed by reference containing the origin of the wanted flight
         * @param destination - a string passed by reference containing the destination of the wanted flight
         * @return a Flight pointer object
         */
        Flight* findFlight(const string &origin, const string &destination);

        /**
         * Adds flight to vector that contains all flights in the program
         * @param flight - flight to be added
         */
        void addFlight(Flight &flight);

        /**
         * Remove flight from the vector that contains all flights in the program
         * @param flight - flight to be removed
         */
        void removeFlight(Flight &flight);

        /**
         * Remove flight from vector that hocontainslds all flights in the program
         * @param id - id of the flight to be removed
         */
        void removeFlight(const string &id);

        /**
         * Adds luggage to vector that contains all luggages in the program
         * @param l - luggage to be added
         */
        void addLuggage(Luggage &l);

        /**
         * Removes luggage from vector that contains all luggages in the program
         * @param id - id of the luggage to be removed
         */
        void removeLuggage(const string &id);

        /**
         * Removes luggage from vector that contains all luggages in the program
         * @param l - luggage to be removed
         */
        void removeLuggage(Luggage &l);

        /**
         * Adds passenger to vector that contains all passengers in the program
         * @param passenger - passenger to be added
         */
        void addPassenger(Passenger &passenger);

        /**
         * Removes passenger from vector that contains all passengers in the program
         * @param id - id of the passenger to be removed
         */
        void removePassenger(const string &id);

        /**
         * Removes passenger from vector that contains all passengers in the program
         * @param passenger - passenger to be removed
         */
        void removePassenger(Passenger &passenger);

        /**
         * Adds services to the vector that contains all contains in the program
         * @param service - service to be added
         */
        void addService(Service &service);

        /**
         * Removes service from vector that contains all of the services in the program
         * @param id - id of the service to be removed
         */
        void removeService(const string &id);

        /**
         * Removes service from vector that contains all of the services in the program
         * @param service - service to be removed
         */
        void removeService(Service &service);

        /**
         * Sets the responsible for a specific service
         * @param service - service to be made
         * @param employee - employee to be responsible for the service
         */
        void setServiceResponsible(Service &service, Employee &employee);

        /**
         * Adds transport to vector that contains all of the transports in the program
         * @param transport - transport to be added
         */
        void addTransport(Transport &transport);

        /**
         * Removes transport from vector that contains all of the transports in the program
         * @param id - id of the transport to be removed
         */
        void removeTransport(const string &id);

        /**
         * Removes transport from vector that contains all of the transport in the program
         * @param service - service to be removed
         */
        void removeTransport(Transport &transport);

        /**
         * A function that refreshes all data in database, based on reading files
         */
        void refreshData();

        /**
         * A function that saves all manipulated data in corresponding files
         */
        void save();
};

#endif // PROJECT_AED_COMPANY_H