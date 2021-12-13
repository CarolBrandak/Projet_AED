#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#define FOLDER "../Source/Files/"
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

/**
 A class to manage an Company
 */
class Company {

    private:

        /**
         * @var - a string attribute that defines the agency's name
         */
        const string name;

        /**
         * @var - a vector that contains all the airports that the city has access to
         */
        vector<Plane*> planes;

        /**
         * @var taltal
         */
        int nextPlaneID;

    public:

        /**
         * Default constructor
         */
        Company();

        /**
         * Default destructor
         */
        ~Company();

        /**
         * Main constructor the Company object
         * @param name - string that contains the agency's name
         */
        Company(string name);

        string getName() const;

        void addPlane(Plane &plane);

        vector<Luggage*> getAllLuggages();

        vector<Passenger*> getAllPassengers();

        vector<Service*> getAllServices();

        vector<Transport*> getAllTransports();

        vector<Flight*> getAllFlights();

        vector<Plane*> getAllPlanes();

        int getNextPlaneID();

         /**
          * Show all data contained in files directory
          */
         void printData();

         /**
          * Writes all modified data in files directory
          * @param folder - a string contains the folder of backup
          */
         void save();


         Flight* findFlight(const string &origin, const string &destination);

        void presentation();
        void listing();
};

#endif // PROJECT_AED_AGENCY_H
