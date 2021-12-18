#ifndef PROJECT_AED_EMPLOYEE_CPP
#define PROJECT_AED_EMPLOYEE_CPP

#include "Employee.h"

Employee::Employee() : Person() {}

Employee::~Employee() {}

Employee::Employee(string name, short int age, char gender) : Person (name, age, gender) {}

bool Employee::operator == (const Employee &employee) const {
    return NAME == employee.NAME && AGE == employee.AGE && GENDER == employee.GENDER;
}

bool Employee::operator < (const Employee &employee) const {
    if (AGE == employee.AGE) return NAME < employee.NAME;
    return AGE < employee.AGE;
}

Employee& Employee::operator = (const Employee &employee) {
    return *this;
}

ostream & operator << (ostream & os, const Employee &employee) {
    os  << "Nome: " << employee.NAME
        << "\nIdade: " << employee.NAME
        << "\nGenero: " << employee.GENDER << endl;
    return os;
}



#endif //PROJECT_AED_EMPLOYEE_CPP