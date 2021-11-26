#ifndef Employee_CPP
#define Employee_CPP

#include "Employee.h"

Employee::Employee() {}

Employee::Employee(string name, short int age, char gender, string ID) :
    Person (name, age, gender) {
    this->ID = ID;
}

void Employee::setID(string ID) {
    this->ID = ID;
}

string Employee::getID() {
    return this->ID;
}

bool operator == (const Employee &employee) const {
    return name == employee.getName() && age == employee.getAge() && gender == employee.getAge() &&
        ID == employee.getID();
}

bool operator < (const Employee &employee) const {
    if (age == employee.getAge()) return name < employee.getName();
    return age < employee.getAge();
}

ostream & operator << (ostream & os, const Employee &employee) {
    os << employee.getName << " " << employee.getAge << " " << employee.getGender << " " << passenger.getID << endl;
    return os;
}

#endif // Employee_CPP