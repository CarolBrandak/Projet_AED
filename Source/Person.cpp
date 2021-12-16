#ifndef PROJECT_AED_PERSON_CPP
#define PROJECT_AED_PERSON_CPP

#include "Person.h" 

Person::Person() {}

Person::~Person() {}

Person::Person(string name, short int age, char gender) : name(name), age(age), gender(toupper(gender)) {}

void Person::setName(const string &name){
    this->name = name;
}

void Person::setAge(const short int &age) {
    this->age = age;
}

void Person::setGender(const char &gender) {
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

#endif // PROJECT_AED_PERSON_CPP