#ifndef PROJET_AED_PLANE_CPP
#define PROJET_AED_PLANE_CPP

#include "Plane.h"

Plane::Plane() : MAX_WEIGHT_CAPACITY(0), MAX_PASSENGERS_CAPACITY(0) {}

Plane::Plane(std::list<Flight> flights,std::queue<Service> servicesToBeMade,
             std::list<Service> madeServices,std::string LICENSE_PLATE,
             std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PASSENGERS_CAPACITY):
        LICENSE_PLATE(LICENSE_PLATE),
        TYPE(TYPE),
        MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
        MAX_PASSENGERS_CAPACITY(MAX_PASSENGERS_CAPACITY),
        flights(flights) {}

std::string Plane::getLicensePlate() const {
    return LICENSE_PLATE;
}

std::string Plane::getType() const {
    return TYPE;
}

list<Flight> Plane::getFlights() const {
    return flights;
}

unsigned int Plane::getMaxWeightCapacity() const {
    return MAX_WEIGHT_CAPACITY;
}

unsigned int Plane::getMaxPassengersCapacity() const {
    return MAX_PASSENGERS_CAPACITY;
}

void Plane::checkFlights() const {

    for (auto const &flight : flights) {
        cout << flight;
    }
}

void Plane::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

void Plane::removeFlight(const Flight &flight) {

    for(auto it = flights.begin() ; it != flights.end() ; it++) {
        if((*it) == flight) {
            flights.erase(it);
            break;
        }
    }
}

void Plane::addService(const Service &service) {
    servicesToBeMade.push(service);
}

void Plane::setServiceAsDone() {
    madeServices.push_back(servicesToBeMade.front());
    servicesToBeMade.pop();
}

void Plane::checkServicesToBeMade() {
    queue<Service> copy = servicesToBeMade;
    while (!copy.empty()) {
        cout << copy.front();
        copy.pop();
    }
}

void Plane::checkMadeServices() {
    for(auto it = madeServices.begin(); it != madeServices.end(); it++)
        cout << *it;
}

bool Plane::operator == (const Plane &plane) const {
    return LICENSE_PLATE == plane.getLicensePlate() && TYPE == plane.getType() && MAX_WEIGHT_CAPACITY == plane.getMaxWeightCapacity() &&
        MAX_PASSENGERS_CAPACITY == plane.getMaxPassengersCapacity();
}

bool Plane::operator < (const Plane &plane) const {
    if (MAX_PASSENGERS_CAPACITY == plane.getMaxPassengersCapacity()) return MAX_WEIGHT_CAPACITY < plane.getMaxWeightCapacity();
    return MAX_PASSENGERS_CAPACITY < plane.getMaxPassengersCapacity();
}

unsigned int Plane::getQuantityOfFlights() const {
    return flights.size();
}

unsigned int Plane::getQuantityOfServicesToBeMade() const {
    return servicesToBeMade.size();
}

unsigned int Plane::getQuantityOfMadeServices() const {
    return madeServices.size();
}

ostream & operator << (ostream & os, const Plane &plane) {
    os << "License Plate: " << plane.getLicensePlate() <<
        "\nType: " << plane.getType() <<
        "\nMax Weight Capacity: "  << plane.getMaxWeightCapacity() <<
        "\nMax Passengers Capacity: " << plane.getMaxPassengersCapacity() <<
        "\nQuantity of flights: " << plane.getQuantityOfFlights() <<
        "\nQuantity of services to be made: " << plane.getQuantityOfServicesToBeMade() <<
        "\nQuantity of made services: " << plane.getQuantityOfMadeServices();
    return os;
}

#endif //PROJET_AED_PLANE_CPP