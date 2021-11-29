#ifndef PROJECT_AED_PLANE_CPP
#define PROJECT_AED_PLANE_CPP

#include "Plane.h"

Plane::Plane() : MAX_WEIGHT_CAPACITY(0), MAX_PASSENGERS_CAPACITY(0),
                        LICENSE_PLATE(""), TYPE("") {}

Plane::Plane(std::list<Flight> flights,
             std::queue<Service> servicesToBeMade,
             std::list<Service> madeServices,
             std::string LICENSE_PLATE,
             std::string TYPE,
             unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PASSENGERS_CAPACITY) :

        LICENSE_PLATE(LICENSE_PLATE),
        TYPE(TYPE),
        MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
        MAX_PASSENGERS_CAPACITY(MAX_PASSENGERS_CAPACITY),
        flights(flights),
        madeServices(madeServices),
        servicesToBeMade(servicesToBeMade) {}

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

void Plane::checkFlights() {

    for (auto flight : flights) {
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

void Plane::setNextServiceAsDone() {
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
    for (auto const &service : madeServices)
        cout << service;
}

bool Plane::operator == (const Plane &plane) const {
    return true;
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

#endif // PROJECT_AED_PLANE_CPP