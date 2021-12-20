#ifndef PROJECT_AED_EMPLOYEE_H
#define PROJECT_AED_EMPLOYEE_H

#include "Person.h"
#include <iostream>
using namespace std;

/**
 * Person's derived class
 */
class Employee : public Person {

    public:

        /**
         * A default constructor of class Employee. No arguments needed.
         */
        Employee();

        /**
         * A default destructor of class Employee
         */
        ~Employee();

        /**
         * Main constructor
         * @param name Employee's name, a string passed by value
         * @param age Employee's age, a short integer passed by value
         * @param gender Employee's gender, a char passed by value
         */
        Employee(string name, short int age, char gender);

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param employee another object that will be compared passed by reference
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Employee &employee) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param employee another object that will be compared passed by reference
         * @return if the current object is less than object passed by reference
        */
        bool operator < (const Employee &employee) const;

        /**
         * @overload
         * Function that returns all characteristics of the Employee being manipulated
         * @param os ostream object, passed by reference
         * @param Employee Employee object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Employee &employee);
};

#endif // PROJECT_AED_EMPLOYEE_H