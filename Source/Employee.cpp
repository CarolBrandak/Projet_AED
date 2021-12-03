#ifndef PROJECT_AED_EMPLOYEE_CPP
#define PROJECT_AED_EMPLOYEE_CPP

#include "Employee.h"

Employee::Employee() : id(""), Person() {}

Employee::Employee(string id, string name, short int age, char gender) : id(id), Person (name, age, gender) {}

string Employee::getID() const {
    return id;
}

bool Employee::operator == (const Employee &employee) const {
    return name == employee.getName() && age == employee.getAge() && gender == employee.getGender() &&
        id == employee.getID();
}

bool Employee::operator < (const Employee &employee) const {
    if (age == employee.getAge()) return name < employee.getName();
    return age < employee.getAge();
}

ostream & operator << (ostream & os, const Employee &employee) {
    os  << employee.getName()
        << " " << employee.getAge()
        << " " << employee.getGender()
        << " " << employee.getID() << endl;
    return os;
}

#endif //PROJECT_AED_EMPLOYEE_CPP