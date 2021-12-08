#ifndef PROJECT_AED_PASSENGER_CPP
#define PROJECT_AED_PASSENGER_CPP

#include "Person.h"
#include "Passenger.h"

Passenger::Passenger() {}

Passenger::~Passenger() {
    luggage.clear();
}

Passenger::Passenger(string id, string name, short int age, char gender, string passportNumber) :
    ID(ID), PASSPORT(passportNumber), Person(name, age, gender) {
    this->luggage = {};
}

void Passenger::setPassportNumber(const string &passportNumber) {
    this->PASSPORT = passportNumber;
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
    if (age == passenger.getAge()) return name < passenger.getName();
    return age < passenger.getAge();
}

bool Passenger::operator == (const Passenger &passenger) const {
    return this->PASSPORT == passenger.getPassportNumber();
}

bool byName(const Passenger &p1, const Passenger &p2) {
    return p1.name < p2.name;
}

bool byAge(const Passenger &p1, const Passenger &p2) {
    return p1.age < p2.age;
}

bool byLuggage(const Passenger &p1, const Passenger &p2) {
    return p1.luggage.size() < p2.luggage.size();
}

ostream & operator << (ostream & os, const Passenger &passenger) {
    os  << "ID: " << passenger.getID() <<
        "\nName: " << passenger.getName() <<
        "\nAge: " << passenger.getAge() <<
        "\nGender: " << passenger.getGender() <<
        "\nPassport Number: " << passenger.getPassportNumber() <<
        "\nNumber of luggages: " << passenger.getLuggage().size() << endl;
    return os;
}

#endif // PROJECT_AED_PASSENGER_CPP