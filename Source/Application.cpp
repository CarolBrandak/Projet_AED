#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Person.h"
#include "Agency.h"
#include "Passenger.h"
#include "Employee.h"
#include "Luggage.h"
#include "Date.h"
#include "Menu.h"

using namespace std;

void Application() {

    Agency agency = Agency("Maravilhosa agência de viagens!");
    cout << endl << agency.getName() << endl << endl;
    agency.getData();
    agency.printData();

}