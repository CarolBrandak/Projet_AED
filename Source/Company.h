#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#define FLIGHT_FILE "../Source/Files/Flights.txt"
#define LUGGAGE_FILE "../Source/Files/Luggages.txt"
#define PASSENGER_FILE "../Source/Files/Passengers.txt"
#define PLANE_FILE "../Source/Files/Planes.txt"
#define SERVICE_FILE "../Source/Files/Services.txt"
#define TRANSPORT_FILE "../Source/Files/Transports.txt"

#include <vector>
#include <fstream>
#include <algorithm>
#include "Plane.h"
#include "Exceptions.h"

/**
 A class to manage an Company
 */
class Company {

    private:

        /**
         * @var name - a string containing the name of the current company
         */
        const string name;

        /**
         * @var nextPlaneID - an integer value that contain the next unique Plane ID, based on
         *                    the previous insertions
         */
        int nextPlaneID;

        /**
         * @var planes - a vector with Plane pointer objects that contains all planes
         *               and information of the application
         */
        vector<Plane*> planes;

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
        Company(string name);

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
         * Returns all Luggages of the system, by reading files
         * @return a vector containing Luggage pointer objects
         */
        vector<Luggage*> getAllLuggages();

        /**
        * Returns all Passengers of the system, by reading files
        * @return a vector containing Passengers pointer objects
        */
        vector<Passenger*> getAllPassengers();

        /**
        * Returns all Services of the system, by reading files
        * @return a vector containing Service pointer objects
        */
        vector<Service*> getAllServices();

        /**
        * Returns all Transports of the system, by reading files
        * @return a vector containing Transport pointer objects
        */
        vector<Transport*> getAllTransports();

        /**
        * Returns all Flights of the system, by reading files
        * @return a vector containing Flight pointer objects
        */
        vector<Flight*> getAllFlights();

        /**
        * Returns all Planes of the system, by reading files
        * @return a vector containing Plane pointer objects
        */
        vector<Plane*> getAllPlanes();


        // save data

        void saveLuggage(vector<Luggage*> luggage);
        void savePassengers(vector<Passenger*> passengers);
        void saveFlights(vector<Flight*> flights);
        void saveServices(vector<Service*> services);
        void savePlanes(vector<Plane*> planes);
        void saveTransports(vector<Transport*> transports);

        // Add
        void addPlane(Plane &plane);

        // Remove
        void removePlane(const string &id);

        // Search
        Plane* findPlane(const string &id);
        Flight* findFlight(const string &origin, const string &destination);

        // Save
        void refreshData();
        void save();
};

#endif // PROJECT_AED_AGENCY_H