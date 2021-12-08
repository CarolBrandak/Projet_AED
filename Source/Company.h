#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#include <string>
#include <vector>
#include <fstream>
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


        vector<Service*> getAllServices(string directory);
        vector<Passenger*> getAllPassengers(string directory);
        vector<Luggage*> getAllLuggages(string directory);
        vector<Flight*> getAllFlights(string directory);
        vector<Plane*> getAllPlanes(string directory);
        vector<Plane*> getPlanes();


        void addAirport(Flight &flight);

        /**
         * Returns the agency's name
         * @return a string, containing the agency's name
         */
        string getName() const;

         /**
          * Load all data contained in files directory
          */
         vector<Plane*> getData();

         /**
          * Show all data contained in files directory
          */
         void printData();

         /**
          * Writes all modified data in files directory
          */
         void saveData();
};

#endif // PROJECT_AED_AGENCY_H
