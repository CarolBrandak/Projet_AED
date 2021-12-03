#ifndef PROJECT_AED_EMPLOYEE_H
#define PROJECT_AED_EMPLOYEE_H

#include "Person.h"

/**
 * Person's derived class
 */
class Employee : public Person {

    private:

        /**
         * @var Employee's id, a integer value
         */
        int id;

    public:

        /**
         * A default constructor of class Employee. No arguments needed.
         */
        Employee();

        /**
         * Main constructor
         * @param id Employee's ID, an integer passed by value
         * @param name Employee's name, a string passed by value
         * @param age Employee's age, a short integer passed by value
         * @param gender Employee's gender, a char passed by value
         */
        Employee(int id, string name, short int age, char gender);

        /**
         * Returns Employee's ID
         * @return a integer, containing employee's ID
         */
        int getID() const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param employee another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Employee &employee) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param employee another object that will be compared
         * @return if the current object is less than object passed by reference
        */
        bool operator < (const Employee &employee) const;
};

/**
* @overload
* Function that returns all characteristics of the Employee being manipulated
* @param os ostream object, passed by reference
* @param Employee Employee object, passed by reference
* @return ostream object
*/
ostream & operator << (ostream & os, const Employee &employee);

#endif // PROJECT_AED_EMPLOYEE_H