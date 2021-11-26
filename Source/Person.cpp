#ifndef Person_CPP
#define Person_CPP

#include "Person.h"

Person::Person() {}

Person::Person(string name, short int age, char gender) {
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void setName(string name) {
    this->name = name;
}

void setAge(short int age) {
    this->age = age;
}

void setGender(char gender) {
    this->gender = gender;
}

string getName() {
    return this->name;
}

short int getAge() {
    return this->age;
}

char getGender() {
    return this->gender;
}

#endif // Person_CPP