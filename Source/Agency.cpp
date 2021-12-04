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

vector<Service> getServices(string directory = "../Source/Files/Services.txt") {

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

vector<Passenger*> getPassengers(string directory = "../Source/Files/Passengers.txt") {

    vector<Passenger*> passengers = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, name, age, gender, passportNumber;

            getline(file, id, ';');
            getline(file, name, ';');
            getline(file, age, ';');
            getline(file, gender, ';');
            getline(file, passportNumber);

            passengers.push_back(new Passenger(id, name, stoi(age), gender[0], passportNumber));
        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return passengers;
}

vector<Luggage*> getLuggage(string directory = "../Source/Files/Luggages.txt") {

    vector<Luggage*> luggage = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, weight, width, height, depth, planeHold;

            getline(file, id, ';');
            getline(file, weight, ';');
            getline(file, width, ';');
            getline(file, height, ';');
            getline(file, depth, ';');
            getline(file, planeHold);

            Volume v;
            v.width = stoi(width);
            v.height = stoi(height);
            v.depth = stoi(depth);

            luggage.push_back(new Luggage(id, stoi(weight), v, planeHold == "1"));
        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return luggage;
}

void Agency::getData() {

    vector<Service> services = getServices();
    vector<Passenger*> passengers = getPassengers();
    vector<Luggage*> luggage = getLuggage();

    for (Passenger *passenger : passengers) {
        cout << *passenger << endl;
    }

    for (Passenger *passenger : passengers) {
        for (Luggage *l : luggage) {
            passenger->addLuggage(*l);
        }
    }

    for (Passenger *passenger : passengers) {
        cout << *passenger << endl;
    }
}

#endif // PROJECT_AED_AGENCY_CPP