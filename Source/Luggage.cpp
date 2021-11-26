#ifndef Luggage_CPP
#define Luggage_CPP

#include "Luggage.h"

Luggage::Luggage() {}

Luggage::Luggage(short int weight, int width, int height, int depth, bool planeHold) {
    this->WEIGHT = weight;
    Volume volume;
    volume.width = width;
    volume.height = height;
    volume.depth = depth;
    this->VOLUME = volume;
    this->planeHold = planeHold;
}

void Luggage::setPlaneHold(bool planeHold) {
    this->planeHold = planeHold;
}

short int Luggage::getWeight() {
    return this->WEIGHT;
}

int Luggage::getVolume() {
    return this->VOLUME.width * this->VOLUME.height * this->VOLUME.depth;
}

bool Luggage::getPlaneHold() {
    return this->planeHold;
}

bool Luggage::operator == (const Luggage &luggage) const {
    return WEIGHT == luggage.getWeight() && getVolume() == luggage.getVolume() && planeHold == luggage.getPlaneHold();
}

bool Luggage::operator < (const Luggage &luggage) const {
    if (WEIGHT == luggage.getWeight()) return getVolume() < luggage.getVolume();
    return WEIGHT < luggage.getWeight();
}

ostream & operator << (ostream & os, const Luggage &luggage) {
    os << WEIGHT << " " << getVolume() << " " << planeHold << endl;
    return os;
}

#endif // Luggage_CPP