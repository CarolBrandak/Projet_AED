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

string Employee::getID() const {
    return this->ID;
}

bool Employee::operator == (const Employee &employee) const {
    return this->name == employee.getName() && this->age == employee.getAge() && this->gender == employee.getAge() &&
        ID == employee.getID();
}

bool Employee::operator < (const Employee &employee) const {
    if (age == employee.getAge()) return name < employee.getName();
    return age < employee.getAge();
}

ostream & operator << (ostream & os, const Employee &employee) {
    os << employee.getName() << " " << employee.getAge() << " " << employee.getGender() << " " << employee.getID() << endl;
    return os;
}

#endif // Employee_CPP