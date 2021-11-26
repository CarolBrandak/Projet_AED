#ifndef Passenger_CPP
#define Passenger_CPP

#include "Person.h"
#include "Passenger.h"

Passenger::Passenger() {}

Passenger::Passenger(string name, short int age, char gender, string passportNumber, vector<Luggage> passengerLuggage) :
    Person (name, age, gender) {
    this->passportNumber = passportNumber;
    this->passengerLuggage = passengerLuggage;
}

void setPassportNumber(string passportNumber) {
    this->passportNumber = passportNumber;
}

void setPassengerLuggage(vector<Luggage> passengerLuggage) {
    this->passengerLuggage = passengerLuggage;
}

string getPassportNumber() {
    return this->passportNumber;
}

vector<Luggage> getPassengerLuggage() {
    return this->passengerLuggage;
}

bool operator == (const Passenger &passenger) const {
    return name == passenger.getName() && age == passenger.getAge() && gender == passenger.getAge() &&
            passportNumber == passenger.getPassportNumber() && passengerLuggage == passenger.getPassengerLuggage();
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