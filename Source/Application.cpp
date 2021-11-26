#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Person.h"
#include "Passenger.h"
#include "Employee.h"
#include "Luggage.h"
#include "Date.h"

using namespace std;

/**
 * Uma função muito simples que chama as classes
 */
void Application() {

    cout << "Test:\n" << endl;
    cout << "cmake-build-debug is ignored now!" << endl;

    vector<Luggage> myLuggage = {};
    Volume v1;

    v1.width = 1 ; v1.height = 2; v1.depth = 3;
    Luggage l1 = Luggage(23, v1, false); myLuggage.push_back(l1);
    v1.width = 4 ; v1.height = 5; v1.depth = 6;
    Luggage l2 = Luggage(5, v1, true); myLuggage.push_back(l2);
    v1.width = 7 ; v1.height = 8; v1.depth = 9;
    Luggage l3 = Luggage(9283, v1, true); myLuggage.push_back(l3);
     v1.width = 10 ; v1.height = 11; v1.depth = 12;
    Luggage l4 = Luggage(312, v1, false); myLuggage.push_back(l4);

    cout << "Print all luggages:" << endl;
    for (auto luggage : myLuggage) {
        cout << luggage ;
    }

    cout << "\nPessoas: " << endl;
    Passenger p1 = Passenger("Fabio", 19, 'M', "UP2021", myLuggage);
    cout << p1 ;
    Passenger p2 = Passenger("Carolina", 20, 'F', "UP2022", myLuggage);
    cout << p2 ;

    cout << "Compare: ";
    string maisVelho = p1 < p2 ? p2.getName() : p1.getName();
    cout << "O mais velho --> " << maisVelho << endl;

    cout << "\nTeste de um funcionario: " << endl;
    Employee p3 = Employee("Ana Paula", 45, 'F', "PROF292");
    cout << p3;

    cout << "\nTeste de datas: " << endl;
    vector<Date> dates = {};
    Date d1 = Date(26, 11, 2021); dates.push_back(d1);
    Date d2 = Date(24, 11, 2021); dates.push_back(d2);
    Date d3 = Date(11, 12, 2021); dates.push_back(d3);

    sort(dates.begin(), dates.end());
    cout << "Datas por ordem crescente, usando o overload do operador < e << :" << endl;
    for (auto date : dates) {
        cout << date;
    }

    cout << "Exit" << endl;
}