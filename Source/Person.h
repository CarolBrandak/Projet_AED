#ifndef Person_H
#define Person_H

/**
 * An abstract class to serve as a base for Employees and Passengers
 */
class Person {

    private string name;
    private short int age;
    private char gender;

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
        string getName();

        /**
         * Returns Person's age
         * @return a short int, containing person's age
         */
        short int getAge();

        /**
         * Returns Person's gender
         * @return a char, containing person's gender
         */
        char getGender();

        /**
         * Boolean virtual function that compares two objects of this class
         * @param person another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        virtual bool operator == (const Person &person) const = 0;

        /**
        * Boolean virtual function that compares two objects of this class
        * @param person another object that will be compared
        * @return if the current object is less than object passed by reference
        */
        virtual bool operator < (const Person &person) const = 0;
};

/**
 * Function that returns all characteristics of the Object being manipulated
 * @param os ostream object, passed by reference
 * @param person Person object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Person &person);

#endif // Person_H