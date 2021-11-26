#ifndef Passenger_CPP
#define Passenger_CPP

#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string name, short int age, char gender, string passportNumber, vector<Luggage> luggage) :
    Person (name, age, gender) {
    this->passportNumber = passportNumber;
    this->luggage = luggage;
}

void setPassportNumber(string passportNumber) {
    this->passportNumber = passportNumber;
}

void setLuggage(vector<Luggage> luggage) {
    this->luggage = luggage;
}

string getPassportNumber() {
    return this->passportNumber;
}

vector<Luggage> getLuggage() {
    return this->luggage;
}

bool operator == (const Passenger &passenger) const {
    return name == passenger.getName() && age == passenger.getAge() && gender == passenger.getAge() &&
            passportNumber == passenger.getPassportNumber() && luggage == passenger.getLuggage();
}

bool operator < (const Passenger &passenger) const {
    if (age == passenger.getAge() return name < passenger.getName();
    return age < passenger.getAge();
}

ostream & operator << (ostream & os, const Passenger &passenger) {
    os << passenger.getName << " " << passenger.getAge << " " << passenger.getGender << " " << passenger.getPassportNumber << endl;
    return os;
}

#endif // Passenger_CPP