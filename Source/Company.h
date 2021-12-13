#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#include <vector>
#include <fstream>
#include <algorithm>
#include "Plane.h"
#include "Flight.h"
#include "Transport.h"
#include "BST.h"

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

        void addPlane(Plane* plane);

        vector<Luggage*> getAllLuggages(string directory);

        vector<Passenger*> getAllPassengers(string directory);

        vector<Service*> getAllServices(string directory);

        vector<Transport*> getAllTransports(string directory);

        vector<Flight*> getAllFlights(string directory);

        vector<Plane*> getAllPlanes(string directory);

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
