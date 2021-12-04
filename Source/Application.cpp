#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Agency.h"

using namespace std;

void Application() {

    Agency agency = Agency("Maravilhosa agência de viagens!");

    /**
    Airport* a = new Airport("4", "Aeroporto Internacional de Pequim", "Pequim");
    agency.addAirport(*a);
    */

    //cout << "Size of airports: " << agency.getAirports().size() << endl;

    //agency.printData();
    agency.saveData();

}