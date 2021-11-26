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

void Passenger::setPassportNumber(string passportNumber) {
    this->passportNumber = passportNumber;
}

void Passenger::setLuggage(vector<Luggage> luggage) {
    this->luggage = luggage;
}

string Passenger::getPassportNumber() {
    return passportNumber;
}

vector<Luggage> Passenger::getLuggage(){
    return luggage;
}

bool Passenger::operator == (Passenger &passenger) const {
    return name == passenger.getName() && age == passenger.getAge() && gender == passenger.getAge() &&
            passportNumber == passenger.getPassportNumber() && luggage == passenger.getLuggage();
}

bool Passenger::operator < (Passenger &passenger) const {
    if (age == passenger.getAge()) return name < passenger.getName();
    return age < passenger.getAge();
}

ostream & operator << (ostream & os, const Passenger &passenger) {
    os << passenger.getName() << " " << passenger.getAge() << " " << passenger.getGender() << endl;
    return os;
}

#endif // Passenger_CPP