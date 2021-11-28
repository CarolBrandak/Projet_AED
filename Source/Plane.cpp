#ifndef PROJET_AED_PLANE_CPP
#define PROJET_AED_PLANE_CPP

#include "Plane.h"

Plane::Plane(std::list<Flight> flights, std::string LICENSE_PLATE, std::string TYPE, unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PASSENGERS_CAPACITY):
        LICENSE_PLATE(std::move(LICENSE_PLATE)),
        TYPE(std::move(TYPE)),
        MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
        MAX_PASSENGERS_CAPACITY(MAX_PASSENGERS_CAPACITY),flights(std::move(flights)) {

}

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
    for (auto const &flight : flights) {
        cout << flight;
    }
}

void Plane::addFlight(Flight flight) {
    flights.push_back(flight);
}

void Plane::removeFlight(Flight flight) {
    //Sort flights and then use binary search
    for(list<Flight>::iterator it = flights.begin() ; it != flights.end() ; it++) {
        if((*it) == flight) {
            flights.erase(it);
            break;
        }
    }
}

#endif //PROJET_AED_PLANE_CPP