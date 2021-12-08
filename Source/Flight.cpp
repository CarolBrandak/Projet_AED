#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"

Flight::Flight() {}

Flight::~Flight() {
    luggage.clear();
    passengers.clear();
}

Flight::Flight(string id, Date flightDate, short int flightDuration, string origin, string destination) :
                    id(id),
                    flightDate(flightDate),
                    FLIGHT_DURATION(flightDuration),
                    origin(origin),
                    destination(destination),
                    quantityOfPassengers(0),
                    quantityOfWeight(0) {
                    this->luggage = {};
                    this->passengers = {};
                    nextID = 0;
}

int Flight::getNextPassengerID() {
    nextID++;
    return nextID--;
}

string Flight::getID() const {
    return id;
}

Date Flight::getFlightDate() const {
    return flightDate;
}

void Flight::setFlightDate(const Date &newDate) {
    this->flightDate = newDate;
}

short int Flight::getFlightDuration() const {
    return FLIGHT_DURATION;
}

string Flight::getFlightOrigin() const {
    return origin;
}

string Flight::getFlightDestination() const {
    return destination;
}

unsigned int Flight::getPassengersQuantity() const {
    return quantityOfPassengers;
}

unsigned int Flight::getWeightQuantity() const {
    return quantityOfWeight;
}

bool Flight::operator == (const Flight &flight) const {
    return id == flight.getID();
}

bool Flight::operator < (const Flight &flight) const {
    return id < flight.getID();
}

bool byNumberOfPassengers(const Flight &f1, const Flight &f2) {
    return f1.quantityOfPassengers < f2.quantityOfPassengers;
}

bool byTotalWeight(const Flight &f1, const Flight &f2) {
    return f1.quantityOfWeight < f2.quantityOfWeight;
}

bool byDate(const Flight &f1, const Flight &f2) {
    return f1.flightDate < f2.flightDate;
}

bool byDuration(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DURATION < f2.FLIGHT_DURATION;
}

void Flight::addPassengers(const vector<Passenger*> &toPush) {

    for (Passenger *passenger : passengers) {
        if (id == passenger->getID().substr(0, 3)) {
            if (stoi(passenger->getID().substr(passenger->getID().find_last_of('-')+1, passenger->getID().size() - passenger->getID().find_last_of('-'))) > nextID) nextID++;
            this->quantityOfPassengers++;
            this->quantityOfWeight += passenger->getTotalWeight();
            passengers.push_back(passenger);
            for (Luggage *l : passenger->getLuggage()) {
                luggage.push_back(l);
            }
        } else continue;
    }
}

void Flight::addPassenger(Passenger& passenger) {
    if (id == passenger.getID().substr(0, 3)) {
        if (stoi(passenger.getID().substr(passenger.getID().find_last_of('-')+1, passenger.getID().size() - passenger.getID().find_last_of('-'))) > nextID) nextID++;
        //cout << "next ID = " << nextID << " and idP = " <<
        this->quantityOfWeight += passenger.getTotalWeight();
        this->quantityOfPassengers++;
        passengers.push_back(&passenger);
        for (Luggage *l : passenger.getLuggage()) {
            luggage.push_back(l);
        }
    } else return;
}

void Flight::removePassenger(Passenger &passenger) {

    for (Luggage *l : passenger.getLuggage()) {
        for (auto it = luggage.begin() ; it != luggage.end() ; it++) {
            if (l == *it) {
                luggage.erase(it);
                it--;
            }
        }
    }

    for (auto it = passengers.begin() ; it != passengers.end() ; it++) {
        if (&passenger == *it) {
            this->quantityOfPassengers--;
            this->quantityOfWeight -= passenger.getTotalWeight();
            passengers.erase(it);
            break;
        }
    }
}

void Flight::checkPassengers() {
    for (auto *passenger : passengers) {
        cout << *passenger << endl;
    }
}

vector<Passenger*> Flight::getPassengers() const {
    return passengers;
}

vector<Luggage*> Flight::getLuggage() const {
    return luggage;
}

std::ostream & operator << (std::ostream & os, const Flight &flight) {
    os  << "Flight ID: " << flight.getID()
        << "\nFlight Date: " << flight.getFlightDate()
        << "Flight Duration: " << flight.getFlightDuration()
        << " minutes\nOrigin: " << flight.getFlightOrigin()
        << "\nDestination: "<< flight.getFlightDestination()
        << "\nQuantity of Weight: " << flight.getWeightQuantity()
        << " Kgs\nQuantity Of Passengers: " << flight.getPassengersQuantity() << endl;
    return os;
}

#endif // PROJECT_AED_FLIGHT_CPP