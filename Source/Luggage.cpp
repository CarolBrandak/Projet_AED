#ifndef PROJECT_AED_LUGGAGE_CPP
#define PROJECT_AED_LUGGAGE_CPP

#include "Luggage.h"

Luggage::Luggage() {}

Luggage::Luggage(short int weight, Volume volume, bool planeHold) : WEIGHT(weight), VOLUME(volume) {
    this->planeHold = planeHold;
}

void Luggage::setPlaneHold(const bool &planeHold) {
    this->planeHold = planeHold;
}

short int Luggage::getWeight() const {
    return this->WEIGHT;
}

int Luggage::getVolume() const {
    return this->VOLUME.width * this->VOLUME.height * this->VOLUME.depth;
}

bool Luggage::getPlaneHold() const {
    return this->planeHold;
}

bool Luggage::operator == (const Luggage &luggage) const {
    return WEIGHT == luggage.getWeight() && getVolume() == luggage.getVolume() && planeHold == luggage.getPlaneHold();
}

bool Luggage::operator < (const Luggage &luggage) const {
    if (WEIGHT == luggage.getWeight()) return getVolume() < luggage.getVolume();
    return WEIGHT < luggage.getWeight();
}

bool byWeight(const Luggage &l1, const Luggage &l2) {
    return l1.getWeight() < l2.getWeight();
}

bool byVolume(const Luggage &l1, const Luggage &l2) {
    return l1.getVolume() < l2.getVolume();
}

ostream & operator << (ostream & os, const Luggage &luggage) {
    os << luggage.getWeight() << " " << luggage.getVolume() << " " << luggage.getPlaneHold() << endl;
    return os;
}

#endif // PROJECT_AED_LUGGAGE_CPP