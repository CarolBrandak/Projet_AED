#include <iostream>
#include <exception>
#include <string>
#include "FirstClass.cpp"
using namespace std;

void Application() {

    string phrase = "Um pequeno teste";

    try {
        First test = First(phrase);
        test.show();
        cout << "Running successful" << endl;
    } catch (exception e) {
        cout << "Error" << endl;
    }

}