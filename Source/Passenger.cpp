#ifndef PROJECT_AED_PASSENGER_CPP
#define PROJECT_AED_PASSENGER_CPP

#include "Person.h"
#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string id, string name, short int age, char gender, string passportNumber, vector<Luggage> luggage) :
    id(id), passportNumber(passportNumber), luggage(luggage), Person(name, age, gender) {}

void Passenger::setPassportNumber(const string &passportNumber) {
    this->passportNumber = passportNumber;
}

void Passenger::setLuggage(const vector<Luggage> &luggage) {
    this->luggage = luggage;
}

string Passenger::getID() const {
    return id;
}

string Passenger::getPassportNumber() const {
    return this->passportNumber;
}

vector<Luggage> Passenger::getLuggage() const {
    return this->luggage;
}

int Passenger::getTotalWeight() const {
    int total = 0;
    for (auto l : luggage) { total += l.getWeight(); }
    return total;
}

int Passenger::getTotalVolume() const {
    int total = 0;
    for (auto l : luggage) { total += l.getVolume(); }
    return total;
}

bool Passenger::operator < (const Passenger &passenger) const {
    if (age == passenger.getAge()) return name < passenger.getName();
    return age < passenger.getAge();
}

bool Passenger::operator==(const Passenger &passenger) const {
    return this->passportNumber == passenger.getPassportNumber();
}

bool byName(const Passenger &p1, const Passenger &p2) {
    return p1.name < p2.name;
}

bool byAge(const Passenger &p1, const Passenger &p2) {
    return p1.age < p2.age;
}

bool byLuggage(const Passenger &p1, const Passenger &p2) {
    return p1.luggage < p2.luggage;
}

ostream & operator << (ostream & os, const Passenger &passenger) {
    os << passenger.getName() << " " << passenger.getAge() << " " << passenger.getGender() << " " << passenger.getPassportNumber() << endl;
    return os;
}

#endif //PROJECT_AED_PASSENGER_CPP