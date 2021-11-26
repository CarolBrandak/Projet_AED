#ifndef Employee_H
#define Employee_H

#include "Person.h"

/**
 * Person's derived class
 */
class Employee : public Person {

    private string employeeID;

    public:

        /**
         * A default constructor of class Employee. No arguments needed.
         */
        Employee();

        /**
         * Main constructor
         * @param name Employee's name, a string passed by value
         * @param age Employee's age, a short integer passed by value
         * @param gender Employee's gender, a char passed by value
         * @param employeeID Employee's id, a string passed by value
         */
        Employee(string name, short int age, char gender, string employeeID);

        /**
         * Set Employee Id
         * @param employeeID Employee's new id, a string passed by value
         */
        void setEmployeeID(string employeeID);

        /**
         * Returns Employee's id
         * @return a string, containing employee's id
         */
        string getEmployeeID();

        /**
         * Boolean function that compares two objects of this class
         * @param employee another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Employee &employee) const;

        /**
        * Boolean function that compares two objects of this class
        * @param employee another object that will be compared
        * @return if the current object is less than object passed by reference
        */
        bool operator < (const Employee &employee) const;
    };

/**
* Function that returns all characteristics of the Object being manipulated
* @param os ostream object, passed by reference
* @param Employee Employee object, passed by reference
* @return ostream object
*/
ostream & operator << (ostream & os, const Employee &employee);

#endif // Employee_H