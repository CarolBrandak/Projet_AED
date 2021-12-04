#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Agency.h"

Agency::Agency() : name("") {}

Agency::Agency(string name) : name(name) {
    this->airports = {};
}

string Agency::getName() const {
    return name;
}

Airport Agency::getAirportByName(const string &airportName) {
    for (Airport airport : airports) {
        if (airport.getName() == airportName) return airport;
    }
    return Airport("", "", "");
}

void Agency::addAirport(const Airport &airport) {
    airports.push_back(airport);
}

#endif // PROJECT_AED_AGENCY_CPP