#ifndef PROJECT_AED_EMPLOYEE_CPP
#define PROJECT_AED_EMPLOYEE_CPP

#include "Employee.h"

Employee::Employee() {}

Employee::Employee(int id, string name, short int age, char gender) : id(id), Person (name, age, gender) {}

int Employee::getID() const {
    return this->id;
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