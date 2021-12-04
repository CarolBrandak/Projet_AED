#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Agency.h"
#include <filesystem>

Agency::Agency() : name("") {}

Agency::Agency(string name) : name(name) {
    this->airports = {};
}

string Agency::getName() const {
    return name;
}

Airport Agency::getAirportByName(const string &airportName) {
    for (Airport airport : airports) {
        if (airport.getName() == airportName) return airport;
    }
    return Airport("", "", "");
}

void Agency::addAirport(const Airport &airport) {
    airports.push_back(airport);
}

vector<Service> getServices (string directory = "../Source/Files/Services.txt") {

    vector<Service> services = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, type, name, gender, age, year, month, day, hour, minute;

            getline(file, id, ';');
            getline(file, type, ';');
            getline(file, year, ';');
            getline(file, month, ';');
            getline(file, day, ';');
            getline(file, hour, ';');
            getline(file, minute, ';');
            getline(file, name, ';');
            getline(file, age, ';');
            getline(file, gender);

            services.push_back(Service(id, type, Date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute)), Employee(name, stoi(age), gender[0])));

        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();

    return services;
}

void Agency::getData() {

    vector<Service> services = getServices();

    for (Service service : services) {
        cout << service << endl;
    }
}

#endif // PROJECT_AED_AGENCY_CPP