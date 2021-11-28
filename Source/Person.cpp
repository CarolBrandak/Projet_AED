#ifndef Person_CPP
#define Person_CPP

#include "Person.h"

Person::Person() {}

Person::Person(string name, short int age, char gender) {
    this->name = name;
    this->age = age;
    this->gender = toupper(gender);
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(short int age) {
    this->age = age;
}

void Person::setGender(char gender) {
    this->gender = gender;
}

string Person::getName() const {
    return this->name;
}

short int Person::getAge() const {
    return this->age;
}

char Person::getGender() const {
    return this->gender;
}

#endif // Person_CPP