#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"

Flight::Flight(Date flightDate,std::string flightID, short int flightDuration, string origin, string destination,
                    short int quantityOfPassengers, short int quantityOfWeight, vector<Passenger> passengers, vector<Luggage> luggage):
               flightDate(flightDate),
               FLIGHT_ID(flightID),
               FLIGHT_DURATION(flightDuration),
               origin(origin),
               destination(destination) {
    this->quantityOfPassengers = quantityOfPassengers;
    this->quantityOfWeight = quantityOfWeight;
    this->passengers = passengers;
    this->luggage = luggage;
}

std::string Flight::getFlightID() const {
    return FLIGHT_ID;
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

bool Flight::operator==(const Flight &flight) const {
    return FLIGHT_ID == flight.getFlightID();
}

bool Flight::operator < (const Flight &flight) const {
    return this->getFlightID() < flight.getFlightID();
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
        for (Luggage l : passenger.getLuggage()) {
            luggage.push_back(l);
        }
    }
}

void Flight::removePassenger(const Passenger &passenger) {

    for (Luggage l : passenger.getLuggage()) {
        for (vector<Luggage>::iterator it = luggage.begin() ; it != luggage.end() ; it++) {
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
    os  << "Flight ID: " << flight.getFlightID()
        << "\nFlight Date: " << flight.getFlightDate()
        << "\nFlight Duration: " << flight.getFlightDuration()
        << "\nOrigin: " << flight.getFlightOrigin()
        << "\nDestination: "<< flight.getFlightDestination()
        << "\nQuantity of Weight: " << flight.getWeightQuantity()
        << "\nQuantity Of Passengers: " << flight.getPassengersQuantity() << endl;
    return os;
}

#endif // PROJECT_AED_FLIGHT_CPP