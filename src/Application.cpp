#include <iostream>
#include <exception>
#include <string>
#include "FirstClass.cpp"
using namespace std;

void Application() {

    string phrase = "Um pequeno teste";
    First test = First(phrase);
    try {
        test.show();
        cout << "Running successful" << endl;
    } catch (exception e) {
        cout << "Error" << endl;
    }

}