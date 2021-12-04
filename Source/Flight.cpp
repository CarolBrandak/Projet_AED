#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"

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

void Flight::addPassengers(const vector<Passenger> &toPush) {

    for (Passenger passenger : passengers) {
        this->quantityOfPassengers++;
        this->quantityOfWeight += passenger.getTotalWeight();
        passengers.push_back(passenger);
        for (Luggage *l : passenger.getLuggage()) {
            //luggage.push_back(l);
        }
    }
}

void Flight::addPassenger(const Passenger& passenger) {
    if (id[2] == passenger.getID()[2]) passengers.push_back(passenger);
}

void Flight::removePassenger(const Passenger &passenger) {

    /**
    for (Luggage *l : passenger.getLuggage()) {
        for (vector<Luggage*>::iterator it = luggage.begin() ; it != luggage.end() ; it++) {
            if (l == *it) {
                luggage.erase(it);
                it--;
            }
        }
    }

    for (vector<Passenger>::iterator it = passengers.begin() ; it != passengers.end() ; it++) {
        if (passenger == *it) {
            this->quantityOfPassengers--;
            this->quantityOfWeight -= passenger.getTotalWeight();
            passengers.erase(it);
            break;
        }
    }
     */
}

void Flight::checkPassengers() const {
    for(size_t i = 0; i < passengers.size(); i++) {
        cout << passengers.at(i);
    }
}

void Flight::checkPassenger(const Passenger& passenger) const {
    cout << passenger;
}

std::ostream & operator << (std::ostream & os, const Flight &flight) {
    os  << "Flight ID: " << flight.getID()
        << "\nFlight Date: " << flight.getFlightDate()
        << "Flight Duration: " << flight.getFlightDuration()
        << "\nOrigin: " << flight.getFlightOrigin()
        << "\nDestination: "<< flight.getFlightDestination()
        << "\nQuantity of Weight: " << flight.getWeightQuantity()
        << "\nQuantity Of Passengers: " << flight.getPassengersQuantity() << endl;
    return os;
}

#endif // PROJECT_AED_FLIGHT_CPP