#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Agency.h"

Agency::Agency() {}

Agency::Agency(string name, vector<Airport> airports) : name(name), airports(airports) {}

Airport Agency::getAirportByName(const string &airportName) {
    for (Airport airport : airports) {
        if (airport.getName() == airportName) return airport;
    }
    vector<Plane> planes = {};
    return Airport("", "", "", planes);
}

void Agency::addAirport(const Airport &airport) {
    airports.push_back(airport);
}

string Agency::getAgencyName() const {
    return this->name;
}

#endif // PROJECT_AED_AGENCY_CPP