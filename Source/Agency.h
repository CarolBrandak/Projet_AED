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
    const std::string name;
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
     * Main constructor the Agency object
     * @param name - string that contains the agency's name
     */
    Agency(string name);
    /**
     * Returns airport by city
     * @param airportName - name of the airport wanted
     * @return an Airport object that if empty means that there is no Airport by that name
     */
    Airport* getAirportByName(const std::string &airportName);
    /**
     * Add current airport in agency vector
     * @param airport - an Airport object that will be added
     */
    void addAirport(Airport &airport);
    /**
     * Returns the agency's name
     * @return a string, containing the agency's name
     */
     string getName() const;

     /**
      * gets all data!
      */
     void getData();

     void printData();
};

#endif // PROJECT_AED_AGENCY_H
