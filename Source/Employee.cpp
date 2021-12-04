#ifndef PROJECT_AED_EMPLOYEE_CPP
#define PROJECT_AED_EMPLOYEE_CPP

#include "Employee.h"

Employee::Employee() : Person() {}

Employee::Employee(string name, short int age, char gender) : Person (name, age, gender) {}

bool Employee::operator == (const Employee &employee) const {
    return name == employee.getName() && age == employee.getAge() && gender == employee.getGender();
}

bool Employee::operator < (const Employee &employee) const {
    if (age == employee.getAge()) return name < employee.getName();
    return age < employee.getAge();
}

ostream & operator << (ostream & os, const Employee &employee) {
    os  << employee.getName()
        << " " << employee.getAge()
        << " " << employee.getGender() << endl;
    return os;
}

#endif //PROJECT_AED_EMPLOYEE_CPP