#ifndef PROJET_AED_FLIGHT_CPP
#define PROJET_AED_FLIGHT_CPP

#include "Flight.h"

Flight::Flight(Date flightDate,std::string flightID, short int flightDuration, string origin, string destination,
               short int quantityOfPassengers, short int quantityOfWeight, vector<Passenger> passengers):
               flightDate(flightDate),
               FLIGHT_ID(flightID),
               FLIGHT_DURATION(flightDuration),
               origin(origin),
               destination(destination){
    this->quantityOfPassengers = quantityOfPassengers;
    this->quantityOfWeight = quantityOfWeight;
    this->passengers = passengers;
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

bool Flight::addPassenger(const Passenger& passenger, const int &MAX_PASSENGERS_CAPACITY, const int &MAX_WEIGHT_CAPACITY) {
    int auxWeight = passenger.getTotalWeight() + this->getWeightQuantity();

    if(quantityOfPassengers < MAX_PASSENGERS_CAPACITY && auxWeight < MAX_WEIGHT_CAPACITY) {
        passengers.push_back(passenger);
        quantityOfPassengers++;
        return true;
    }
    return false;
}

bool Flight::removePassenger(const Passenger &passenger) {
    //Sort and binary search
    size_t passengerIndex = INT_MAX;
    for(size_t i = 0; i < passengers.size(); i++) {
        if(passengers.at(i) == passenger) {
            passengerIndex = i;
            break;
        }
    }
    if(passengerIndex != INT_MAX) {
        this->quantityOfWeight-=passengers.at(passengerIndex).getTotalWeight();
        passengers.erase(passengers.begin()+passengerIndex);
        return true;
    } else {
        return false;
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
    os << "Flight ID: " << flight.getFlightID() << "\nFlight Date: " << flight.getFlightDate() << "\nFlight Duration: "
    << flight.getFlightDuration() << "\nOrigin: " << flight.getFlightOrigin() << " " << flight.getFlightOrigin()
    << "\nDestination: "<< flight.getFlightDestination() << " " << flight.getFlightDestination() <<
    "\nQuantity of Weight: " << flight.getWeightQuantity() << "\nQuantity Of Passengers: "
    << flight.getPassengersQuantity() << std::endl;
    return os;
}

#endif //PROJET_AED_FLIGHT_CPP