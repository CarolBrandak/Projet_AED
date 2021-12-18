#ifndef PROJECT_AED_EMPLOYEE_CPP
#define PROJECT_AED_EMPLOYEE_CPP

#include "Employee.h"

Employee::Employee() : Person() {}

Employee::~Employee() {}

Employee::Employee(string name, short int age, char gender) : Person (name, age, gender) {}

bool Employee::operator == (const Employee &employee) const {
    return name == employee.name && age == employee.age && gender == employee.gender;
}

bool Employee::operator < (const Employee &employee) const {
    if (age == employee.age) return name < employee.name;
    return age < employee.age;
}

ostream & operator << (ostream & os, const Employee &employee) {
    os  << "Nome: " << employee.name
        << "\nIdade: " << employee.age
        << "\nGenero: " << employee.gender << endl;
    return os;
}

#endif //PROJECT_AED_EMPLOYEE_CPP