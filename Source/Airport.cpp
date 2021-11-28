#ifndef PROJET_AED_AIRPORT_CPP
#define PROJET_AED_AIRPORT_CPP

#include "Airport.h"

Airport::Airport() : name(""), city("") {}

Airport::Airport(string name, string city, vector<Plane> planes) :
    name(name), city(city), planes(planes) {
}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

vector<Plane> Airport::getPlanes() const {
    return planes;
}

vector<Flight> Airport::getPossibleFlights(const string &city, const Date &date) const {

    vector<Flight> possibleFlights = {};
    for (Plane plane : planes) {
        for (Flight flight : plane.getFlights()) {
            if (flight.getFlightDestination() == city && flight.getFlightDate() == date) {
                possibleFlights.push_back(flight);
            }
        }
    }

    return possibleFlights;
}

void Airport::checkPlanes() {
    for (Plane plane : planes) {
        cout << plane;
    }
}

void Airport::addPlane(const Plane &plane) {
    planes.push_back(plane);
}

void Airport::removePlane(const Plane &plane) {

    cout << "Teste" << endl;

    for (auto it = planes.begin() ; it != planes.end() ; it++) {
        if (*it == plane) {
            planes.erase(it);
            return;
        }
    }

}

void Airport::showPossibleFlights(const vector<Flight> &possibleFlights) {
    for (Flight flight : possibleFlights) {
        cout << flight;
    }
}

void Airport::buyFlight(Flight flight, const vector<Passenger> &passengers) {

    cout << "Ainda não implementada!" << endl;
}

bool Airport::operator == (const Airport &airport) const {
    return this->getName() == airport.getName() && this->getCity() == airport.getCity() &&
                this->getPlanes().size() == airport.getPlanes().size();
}

bool Airport::operator < (const Airport &airport) const {
    return this->getName() < airport.getName();
}

ostream & operator << (ostream & os, const Airport &airport) {
    os  << "Name: " << airport.getName()
        << "\nCity: " << airport.getCity()
        << "\nNumber of planes: " << airport.getPlanes().size() << endl;
    return os;
}

#endif //PROJET_AED_AIRPORT_CPP