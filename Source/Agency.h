#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#include <string>
#include <vector>
#include <fstream>
#include "Airport.h"

/**
 A class to manage an Agency
 */
class Agency {

    private:

        /**
         * @var - a string attribute that defines the agency's name
         */
        const string name;

        /**
         * @var - a vector that contains all the airports that the city has access to
         */
        vector<Airport*> airports;

    public:

        /**
         * Default constructor
         */
        Agency();

        /**
         * Default destructor
         */
        ~Agency();

        /**
         * Main constructor the Agency object
         * @param name - string that contains the agency's name
         */
        Agency(string name);

        /**
         * Returns airport by city
         * @param city - name of city wanted
         * @return an Airport pointer object that if empty means that there is no Airport by that city
         */
        Airport* getAirportInCity(const string &city);

        /**
         * Add current airport in agency vector
         * @param airport - an Airport object that will be added, passed by reference
         */
        void addAirport(Airport &airport);

        /**
         * Returns the agency's name
         * @return a string, containing the agency's name
         */
        string getName() const;

        /**
         * Prints all airports managed by Agency
         */
        void checkAirports();

         /**
          * Load all data contained in files directory
          */
         void getData();

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
