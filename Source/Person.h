#ifndef Person_H
#define Person_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * An abstract class to serve as a base for Employees and Passengers
 */
class Person {

    protected:

        /**
         * @var name, a Person's name
         */
        string name;

        /**
         * @var age, a Person's age
         */
        short int age;

        /**
         * @var gender, a Person's gender
         */
        char gender;

    public:

        /**
         * A default constructor of class Person. No arguments needed.
         */
        Person();

        /**
         * Main constructor
         * @param name Person's name, a string passed by value
         * @param age Person's age, a short integer passed by value
         * @param gender Person's gender, a char passed by value
         */
        Person(string name, short int age, char gender);

        /**
         * Set Person's name
         * @param name Person's new name, a string passed by value
         */
        void setName(string name);

        /**
         * Set Person's age
         * @param age Person's new age, a short integer passed by value
         */
        void setAge(short int age);

        /**
         * Set Person's gender
         * @param gender Person's new gender, a char passed by value
         */
        void setGender(char gender);

        /**
         * Returns Person's name
         * @return a string, containing person's name
         */
        string getName() const;

        /**
         * Returns Person's age
         * @return a short int, containing person's age
         */
        short int getAge() const;

        /**
         * Returns Person's gender
         * @return a char, containing person's gender
         */
        char getGender() const;
};

#endif // Person_H