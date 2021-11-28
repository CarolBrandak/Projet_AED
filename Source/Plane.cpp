#include "Plane.h"

#include <utility>
#include <iostream>

Plane::Plane(std::vector<Flight> flights, std::string LICENSE_PLATE, std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PASSENGERS_CAPACITY):
        LICENSE_PLATE(std::move(LICENSE_PLATE)),
        TYPE(std::move(TYPE)),
        MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
        MAX_PASSENGERS_CAPACITY(MAX_PASSENGERS_CAPACITY) {

    this->flights = std::move(flights);

}

Plane::Plane(std::string LICENSE_PLATE, std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PEOPLE_CAPACITY):
        LICENSE_PLATE(std::move(LICENSE_PLATE)),
        TYPE(std::move(TYPE)),
        MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
        MAX_PASSENGERS_CAPACITY(MAX_PEOPLE_CAPACITY) {}

std::string Plane::getLicensePlate() const {
    return LICENSE_PLATE;
}

std::string Plane::getType() const {
    return TYPE;
}

unsigned int Plane::getMaxWeightCapacity() const {
    return MAX_WEIGHT_CAPACITY;
}

unsigned int Plane::getMaxPassengersCapacity() const {
    return MAX_PASSENGERS_CAPACITY;
}

void Plane::checkFlights() const {
    //Do a toString for flights
    for(size_t i = 0; i < flights.size(); i++) {
        std::cout << flights.at(i);
    }
}

void Plane::addFlight(Flight flight) {
    flights.push_back(flight);
}

void Plane::removeFlight(Flight flight) {
    //Sort flights and then use binary search
    for(size_t i = 0; i < flights.size(); i++) {
        if(flights.at(i) == flight) {
            flights.erase(flights.begin()+i); break;
        }
    }
}

