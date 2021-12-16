#ifndef PROJECT_AED_UTILITIES_CPP
#define PROJECT_AED_UTILITIES_CPP

#include "Utilities.h"

bool byEmployeeName(const Employee &e1, const Employee &e2) {
    return e1.getName() < e2.getName();
}

bool byNumberOfPassengers(const Flight &f1, const Flight &f2) {
    return f1.getPassengersQuantity() < f2.getPassengersQuantity();
}

bool byTotalWeight(const Flight &f1, const Flight &f2) {
    return f1.getWeightQuantity() < f2.getWeightQuantity();
}

bool byDate(const Flight &f1, const Flight &f2) {
    return f1.getFlightDate() < f2.getFlightDate();
}

bool byDuration(const Flight &f1, const Flight &f2) {
    return f1.getFlightDuration() < f2.getFlightDuration();
}

 bool byWeight(const Luggage &l1, const Luggage &l2) {
    return l1.getWeight() < l2.getWeight();
}

bool byVolume(const Luggage &l1, const Luggage &l2) {
    return l1.getTotalVolume() < l2.getTotalVolume();
}

bool byPassengerName(const Passenger &p1, const Passenger &p2) {
    return p1.getName() < p2.getName();
}

bool byAge(const Passenger &p1, const Passenger &p2) {
    return p1.getAge() < p2.getAge();
}

bool byLuggage(const Passenger &p1, const Passenger &p2) {
    return p1.getLuggage().size() < p2.getLuggage().size();
}

 bool byMaximumWeight(const Plane *p1, const Plane *p2) {
    return p1->getMaxWeightCapacity() < p2->getMaxWeightCapacity();
}

bool byMaximumCapacity(const Plane *p1, const Plane *p2) {
    return p1->getMaxPassengersCapacity() < p2->getMaxPassengersCapacity();
}

bool byNumberOfFlights(const Plane *p1, const Plane *p2) {
    return p1->getQuantityOfFlights() < p2->getQuantityOfFlights();
}

bool byNumberOfServices(const Plane *p1, const Plane *p2) {
    return (p1->getQuantityOfMadeServices() + p1->getQuantityOfServicesToBeMade()) < (p2->getQuantityOfMadeServices() + p2->getQuantityOfServicesToBeMade());
}

bool byServiceDate(const Service &s1, const Service &s2) {
    return s1.getServiceDate() < s2.getServiceDate();
}

bool byServiceType(const Service &s1, const Service &s2) {
    return s1.getServiceType() < s2.getServiceType();
}

bool byDistance(const Transport &t1, const Transport &t2) {
    return t1.getDistance() < t2.getDistance();
}

bool byTransportType(const Transport &t1, const Transport &t2) {
    return t1.getType() < t2.getType();
}

bool byTransportTime(const Transport &t1, const Transport &t2) {
    return t1.getDate() < t2.getDate();
}

#endif // PROJECT_AED_UTILITIES_CPP