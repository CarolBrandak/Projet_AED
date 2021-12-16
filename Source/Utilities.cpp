#ifndef PROJECT_AED_UTILITIES_H
#define PROJECT_AED_UTILITIES_H

#include "Utilities.h"

// Para os voos

/**

bool byNumberOfPassengers(const Flight &f1, const Flight &f2) {
    return f1.getPassengersQuantity() < f2.getPassengersQuantity();
}

bool byTotalWeight(const Flight &f1, const Flight &f2) {
    return f1.quantityOfWeight < f2.quantityOfWeight;
}

bool byDate(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DATE < f2.FLIGHT_DATE;
}

bool byDuration(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DURATION < f2.FLIGHT_DURATION;
}

 bool byWeight(const Luggage &l1, const Luggage &l2) {
    return l1.getWeight() < l2.getWeight();
}

bool byVolume(const Luggage &l1, const Luggage &l2) {
    return l1.getTotalVolume() < l2.getTotalVolume();
}


bool byName(const Passenger &p1, const Passenger &p2) {
    return p1.name < p2.name;
}

bool byAge(const Passenger &p1, const Passenger &p2) {
    return p1.age < p2.age;
}

bool byLuggage(const Passenger &p1, const Passenger &p2) {
    return p1.luggage.size() < p2.luggage.size();
}

 bool byMaximumWeight(const Plane &p1, const Plane &p2) {
    return p1.MAX_WEIGHT_CAPACITY < p2.MAX_WEIGHT_CAPACITY;
}

bool byMaximumCapacity(const Plane &p1, const Plane &p2) {
    return p1.MAX_PASSENGERS_CAPACITY < p2.MAX_PASSENGERS_CAPACITY;
}

bool byNumberOfFlights(const Plane &p1, const Plane &p2) {
    return p1.getQuantityOfFlights() < p2.getQuantityOfFlights();
}

bool byNumberOfServices(const Plane &p1, const Plane &p2) {
    return (p1.getQuantityOfMadeServices() + p1.getQuantityOfServicesToBeMade()) < (p2.getQuantityOfMadeServices() + p2.getQuantityOfServicesToBeMade());
}

**/

// Outras coisas

#endif // PROJECT_AED_UTILITIES_H