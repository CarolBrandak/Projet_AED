#ifndef PROJECT_AED_PASSENGER_CPP
#define PROJECT_AED_PASSENGER_CPP

#include "Passenger.h"

Passenger::Passenger() {}

Passenger::~Passenger() {
    luggage.clear();
}

Passenger::Passenger(string id, string name, short int age, char gender, string passportNumber) :
    ID(id), PASSPORT(passportNumber), Person(name, age, gender) {
    this->luggage = {};
}

void Passenger::addLuggage(Luggage &newLuggage) {
    if (ID == newLuggage.getID()) luggage.push_back(&newLuggage);
}

string Passenger::getID() const {
    return ID;
}

string Passenger::getPassportNumber() const {
    return this->PASSPORT;
}

vector<Luggage*> Passenger::getLuggage() const {
    return this->luggage;
}

int Passenger::getTotalWeight() const {
    int total = 0;
    for (auto l : luggage) { total += l->getWeight(); }
    return total;
}

int Passenger::getTotalVolume() const {
    int total = 0;
    for (auto l : luggage) { total += l->getTotalVolume(); }
    return total;
}

bool Passenger::operator < (const Passenger &passenger) const {
    if (AGE == passenger.AGE) return NAME < passenger.NAME;
    return AGE < passenger.AGE;
}

bool Passenger::operator == (const Passenger &passenger) const {
    return this->PASSPORT == passenger.PASSPORT && this->ID == passenger.ID &&
            this->NAME == passenger.NAME && this->AGE == passenger.AGE && this->GENDER == passenger.GENDER;
}

void Passenger::removeLuggage(Luggage *l) {
    for (auto it = this->luggage.begin() ; it != this->luggage.end() ; it++) {
        if (*it == l) {
            luggage.erase(it);
            return;
        }
    }
}

ostream & operator << (ostream & os, const Passenger &passenger) {
    os  << "ID: " << passenger.ID <<
        "\nNome: " << passenger.NAME <<
        "\nIdade: " << passenger.AGE <<
        "\nGenero: " << passenger.GENDER <<
        "\nPassaporte: " << passenger.PASSPORT <<
        "\nNumero de malas: " << passenger.getLuggage().size() << endl;
    return os;
}

#endif // PROJECT_AED_PASSENGER_CPP