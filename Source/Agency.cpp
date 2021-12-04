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

vector<Service*> getServices(string directory = "../Source/Files/Services.txt") {

    vector<Service*> services = {};
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

            services.push_back(new Service(id, type, Date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute)), Employee(name, stoi(age), gender[0])));
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

vector<Flight*> getFlights(string directory = "../Source/Files/Flights.txt") {

    vector<Flight*> flights = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, year, month, day, hour, minute, duration, origin, destination;

            getline(file, id, ';');
            getline(file, year, ';');
            getline(file, month, ';');
            getline(file, day, ';');
            getline(file, hour, ';');
            getline(file, minute, ';');
            getline(file, duration, ';');
            getline(file, origin, ';');
            getline(file, destination);

            flights.push_back(new Flight(id, Date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute)), stoi(duration), origin, destination));
        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return flights;
}

void Agency::getData() {

    vector<Passenger*> passengers = getPassengers();
    vector<Luggage*> luggage = getLuggage();

    /*
     * Antes dos passageiros serem carregados com a bagagem do sistema.
    for (Passenger *passenger : passengers) {
        cout << *passenger << endl;
    }
     */

    // Adicionando a carga ao passageiro
    for (Passenger *passenger : passengers) {
        for (Luggage *l : luggage) {
            passenger->addLuggage(*l);
        }
    }

    /**
     * Depois dos passageiros serem carregados com a bagagem do sistema
    for (Passenger *passenger : passengers) {
        cout << *passenger << endl;
    }
     */

    vector<Service*> services = getServices();
    vector<Flight*> flights = getFlights();

    // Antes de levar com os passageiros
    /**
     * for (Flight *flight : flights) {
        cout << *flight << endl;
    }
     */

    for (Flight *flight : flights) {
        for (Passenger *passenger : passengers) {
            flight->addPassenger(*passenger);
        }
    }

    cout << "Depois:" << endl;
    // Depois de levar com os passageiros
    for (Flight *flight : flights) {
        cout << *flight << endl;
    }
}

#endif // PROJECT_AED_AGENCY_CPP