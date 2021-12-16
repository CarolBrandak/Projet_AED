#ifndef PROJECT_AED_LUGGAGE_CPP
#define PROJECT_AED_LUGGAGE_CPP

#include "Luggage.h"

Luggage::Luggage() {}

Luggage::~Luggage() {}

Luggage::Luggage(string id, short int weight, Volume volume, bool planeHold) : ID(id), WEIGHT(weight), VOLUME(volume), planeHold(planeHold) {}

void Luggage::setPlaneHold(const bool &planeHold) {
    this->planeHold = planeHold;
}

string Luggage::getID() const {
    return this->ID;
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
    return WEIGHT == luggage.WEIGHT && getTotalVolume() == luggage.getTotalVolume() && planeHold == luggage.planeHold;
}

bool Luggage::operator < (const Luggage &luggage) const {
    if (WEIGHT == luggage.WEIGHT) return getTotalVolume() < luggage.getTotalVolume();
    return WEIGHT < luggage.WEIGHT;
}

ostream & operator << (ostream & os, const Luggage &luggage) {
    os   << "ID: " << luggage.ID <<
            "\nWeight: " << luggage.WEIGHT <<
            "\nVolume: " << luggage.getTotalVolume() <<
            "\nPlaneHold: " << luggage.planeHold<< endl;
    return os;
}

#endif // PROJECT_AED_LUGGAGE_CPP