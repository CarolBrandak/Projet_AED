#ifndef PROJECT_AED_LUGGAGE_CPP
#define PROJECT_AED_LUGGAGE_CPP

#include "Luggage.h"

Luggage::Luggage() {}

Luggage::~Luggage() {}

Luggage::Luggage(string id, short int weight, Volume volume, bool planeHold) : id(id), WEIGHT(weight), VOLUME(volume), planeHold(planeHold) {}

void Luggage::setPlaneHold(const bool &planeHold) {
    this->planeHold = planeHold;
}

string Luggage::getID() const {
    return this->id;
}

short int Luggage::getWeight() const {
    return this->WEIGHT;
}

int Luggage::getTotalVolume() const {
    return this->VOLUME.width * this->VOLUME.height * this->VOLUME.depth;
}

Volume Luggage::getVolume() const {
    return this->VOLUME;
}

bool Luggage::getPlaneHold() const {
    return this->planeHold;
}

bool Luggage::operator == (const Luggage &luggage) const {
    return WEIGHT == luggage.getWeight() && getTotalVolume() == luggage.getTotalVolume() && planeHold == luggage.getPlaneHold();
}

bool Luggage::operator < (const Luggage &luggage) const {
    if (WEIGHT == luggage.getWeight()) return getTotalVolume() < luggage.getTotalVolume();
    return WEIGHT < luggage.getWeight();
}

bool byWeight(const Luggage &l1, const Luggage &l2) {
    return l1.getWeight() < l2.getWeight();
}

bool byVolume(const Luggage &l1, const Luggage &l2) {
    return l1.getTotalVolume() < l2.getTotalVolume();
}

ostream & operator << (ostream & os, const Luggage &luggage) {
    os   << "ID: " << luggage.getID() <<
            "\nWeight: " << luggage.getWeight() <<
            "\nVolume: " << luggage.getTotalVolume() <<
            "\nPlaneHold: " << luggage.getPlaneHold() << endl;
    return os;
}

#endif // PROJECT_AED_LUGGAGE_CPP