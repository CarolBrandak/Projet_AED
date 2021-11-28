#ifndef Passenger_CPP
#define Passenger_CPP

#include "Person.h"
#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string name, short int age, char gender, string passportNumber, vector<Luggage> luggage) :
    Person (name, age, gender) {
    this->passportNumber = passportNumber;
    this->luggage = luggage;
}

void Passenger::setPassportNumber(const string &passportNumber) {
    this->passportNumber = passportNumber;
}

void Passenger::setLuggage(const vector<Luggage> &luggage) {
    this->luggage = luggage;
}

string Passenger::getPassportNumber() const {
    return this->passportNumber;
}

vector<Luggage> Passenger::getLuggage() {
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

ostream & operator << (ostream & os, const Passenger &passenger) {
    os << passenger.getName() << " " << passenger.getAge() << " " << passenger.getGender() << " " << passenger.getPassportNumber() << endl;
    return os;
}

#endif // Passenger_CPP