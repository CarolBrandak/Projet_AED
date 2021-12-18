#ifndef PROJECT_AED_PERSON_CPP
#define PROJECT_AED_PERSON_CPP

#include "Person.h"

Person::Person() : NAME(""), AGE(0), GENDER('?') {}

Person::~Person() {}

Person::Person(string name, short int age, char gender) : NAME(name), AGE(age), GENDER(toupper(gender)) {}

string Person::getName() const {
    return this->NAME;
}

short int Person::getAge() const {
    return this->AGE;
}

char Person::getGender() const {
    return this->GENDER;
}

#endif // PROJECT_AED_PERSON_CPP