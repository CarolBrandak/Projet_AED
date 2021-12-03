#ifndef PROJECT_AED_AIRPORT_CPP
#define PROJECT_AED_AIRPORT_CPP

#include "Airport.h"

Airport::Airport() : id(""), name(""), city("") {}

Airport::Airport(string id, string name, string city, vector<Plane> planes) :
    id(id), name(name), city(city), planes(planes) {
}

string Airport::getID() const {
    return id;
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

    for (auto it = planes.begin() ; it != planes.end() ; it++) {
        if (*it == plane) {
            planes.erase(it);
            break;
        }
    }
}

void Airport::showPossibleFlights(const vector<Flight> &possibleFlights) {
    for (Flight flight : possibleFlights) {
        cout << flight;
    }
}

bool Airport::buyTicket(Flight flight, const vector<Passenger> &passengers) {

    int totalPassengers = passengers.size();
    int totalPassengersWeight = 0;

    for (Passenger passenger : passengers) totalPassengersWeight += passenger.getTotalWeight();

    for (Plane plane : planes) {

        bool found = plane.findFlight(flight);
        if (found) {

            int futureTotalPassengers = totalPassengers + flight.getPassengersQuantity();
            int futureTotalWeight = totalPassengersWeight + flight.getWeightQuantity();

            if (futureTotalPassengers <= plane.getMaxPassengersCapacity() &&
                futureTotalWeight <= plane.getMaxWeightCapacity() ) {

                flight.addPassengers(passengers);
                if (passengers.size() == 1) cout << "Bilhete comprado com sucesso, ou algo do tipo" << endl;
                else cout << "Bilhetes comprados com sucesso, ou algo" << endl;
                return true;

            } else {
                cout << "Não podes ir no voo que indicaste -> levas peso a mais ou pessoas a mais!" << endl;
                return false;
            }
        }
    }
    return false;
}

bool Airport::operator == (const Airport &airport) const {
    return this->getName() == airport.getName() && this->getCity() == airport.getCity() &&
    this->getPlanes().size() == airport.getPlanes().size();
}

bool Airport::operator < (const Airport &airport) const {
    return this->getName() < airport.getName();
}

bool byName(const Airport &a1, const Airport&a2) {
    return a1.name < a2.name;
}

bool byQuantityOfPlanes(const Airport &a1, const Airport&a2) {
    return a1.planes.size() < a2.planes.size();
}

ostream & operator << (ostream & os, const Airport &airport) {
    os  << "Name: " << airport.getName()
        << "\nCity: " << airport.getCity()
        << "\nNumber of planes: " << airport.getPlanes().size() << endl;
    return os;
}

#endif // PROJECT_AED_AIRPORT_CPP