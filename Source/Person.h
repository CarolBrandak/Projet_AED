#ifndef PROJECT_AED_PERSON_H
#define PROJECT_AED_PERSON_H

#include <string>
using namespace std;

/**
 * An class to serve as a base for Employees and Passengers
 */
class Person {

    protected:

        /**
         * @var NAME, a Person's name
         */
         const string NAME;

        /**
         * @var AGE, a Person's age
         */
        const short int AGE;

        /**
         * @var GENDER, a Person's gender
         */
        const char GENDER;

    public:

        /**
         * A default constructor of class Person. No arguments needed.
         */
        Person();

        /**
         * A default destructor of class Person
         */
        ~Person();

        /**
         * Main constructor
         * @param name Person's name, a string passed by value
         * @param age Person's age, a short integer passed by value
         * @param gender Person's gender, a char passed by value
         */
        Person(string name, short int age, char gender);

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

#endif // PROJECT_AED_PERSON_H