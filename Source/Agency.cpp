#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Agency.h"

Agency::Agency() : name("") {}

Agency::~Agency() {
    airports.clear();
}

Agency::Agency(string name) : name(name) {
    this->airports = getData();
}

string Agency::getName() const {
    return name;
}

Airport* Agency::getAirportInCity(const string &city) {
    for (Airport *airport : airports) {
        if (airport->getCity() == city) return airport;
    }
    return new Airport("", "", "");
}

void Agency::addAirport(Airport &airport) {
    airports.push_back(&airport);
}

void Agency::checkAirports() {
    for (Airport *airport : airports) {
        cout << *airport << endl;
    }
}

vector<Airport*> Agency::getAirports() {
    return airports;
}

vector<Service*> Agency::getAllServices(string directory = "../Source/Files/Services.txt") {

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

vector<Passenger*> Agency::getAllPassengers(string directory = "../Source/Files/Passengers.txt") {

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

vector<Luggage*> Agency::getAllLuggages(string directory = "../Source/Files/Luggages.txt") {

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

vector<Flight*> Agency::getAllFlights(string directory = "../Source/Files/Flights.txt") {

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

vector<Plane*> Agency::getAllPlanes(string directory = "../Source/Files/Planes.txt") {

    vector<Plane*> planes = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, licencePlate, type, weightCapacity, passengerCapacity;

            getline(file, id, ';');
            getline(file, licencePlate, ';');
            getline(file, type, ';');
            getline(file, weightCapacity, ';');
            getline(file, passengerCapacity);

            planes.push_back(new Plane(id, licencePlate, type, stoi(weightCapacity), stoi(passengerCapacity)));
        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return planes;
}

vector<Airport*> Agency::getAllAirports(string directory = "../Source/Files/Airports.txt") {

    vector<Airport*> airports = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, name, city;

            getline(file, id, ';');
            getline(file, name, ';');
            getline(file, city);

            airports.push_back(new Airport(id, name, city));
        }
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return airports;
}

void Agency::printData() {

    // Aeroporto -> Aviões -> Voos -> ((Passageiros -> Bagagem) && Bagagem)

    for (Airport *airport : airports) {
        cout << *airport << endl;
        for (Plane *plane : airport->getPlanes()) {
            cout << *plane << endl;
            for (Flight *flight : plane->getFlights()) {
                cout << *flight << endl;
                for (Passenger *passenger : flight->getPassengers()) {
                    cout << *passenger << endl;
                    for (Luggage *luggage : passenger->getLuggage()) {
                        cout << *luggage << endl;
                    }
                }
                for (Luggage *luggage : flight->getLuggage()) {
                    cout << *luggage << endl;
                }
            }
        }
    }
}

vector<Airport*> Agency::getData() {

    // Carega as bagagens e os passageiros, coloca as bagagens nos passageiros
    vector<Luggage*> luggage = getAllLuggages();
    vector<Passenger*> passengers = getAllPassengers();
    for (Passenger *passenger : passengers) {
        for (Luggage *l : luggage) {
            passenger->addLuggage(*l);
        }
    }

    // Carrega os voos, coloca os passageiros nos voos
    vector<Flight*> flights = getAllFlights();
    for (Flight *flight : flights) {
        for (Passenger *passenger : passengers) {
            flight->addPassenger(*passenger);
        }
    }

    // Carrega os aviões e os serviços, coloca os voos e os serviços nos aviões
    vector<Service*> services = getAllServices();
    vector<Plane*> planes = getAllPlanes();
    for (Plane *plane : planes) {
        for (Service *service : services) {
            plane->addService(*service);
        }
        for (Flight *flight : flights) {
            plane->addFlight(*flight);
        }
    }

    // Carrega os aeroportos, coloca os aviões nos aeroportos
    vector<Airport*> allAirports = getAllAirports();
    for (Airport *airport : allAirports) {
        for (Plane *plane : planes) {
            airport->addPlane(*plane);
        }
    }

    // Liberta a memória gasta no processo -> mais eficiente
    luggage.clear();
    passengers.clear();
    services.clear();
    flights.clear();
    planes.clear();

    // A agência passa a conhecer TODA a informação carregada
    return allAirports;

}

void saveLuggage(vector<Luggage*> luggage, string directory = "../Source/Files/Luggages.txt") {

    ofstream file(directory);
    if (file.is_open()) {
        for (int i = 0 ; i < luggage.size() - 1; i++) {
            file << luggage[i]->getID() << ";" << luggage[i]->getWeight() << ";" << luggage[i]->getVolume().width
                 << ";" << luggage[i]->getVolume().height << ";" << luggage[i]->getVolume().depth
                 << ";" << luggage[i]->getPlaneHold() << endl;
        }
        Luggage * l = luggage[luggage.size()-1];
        file << l->getID() << ";" << l->getWeight() << ";" << l->getVolume().width
             << ";" << l->getVolume().height << ";" << l->getVolume().depth
             << ";" << l->getPlaneHold();
    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void Agency::saveData() {

    vector<Luggage*> allLuggage = {};
    vector<Passenger*> allPassengers = {};
    vector<Flight*> allFlights = {};
    vector<Service*> allServices = {};
    vector<Plane*> allPlanes = {};
    vector<Airport*> allAirports = {};

    // Carrega os vectores com os dados alterados pelo utilizador
    for (Airport *airport : airports) {
        allAirports.push_back(airport);
        for (Plane *plane : airport->getPlanes()) {
            allPlanes.push_back(plane);
            for (Flight *flight : plane->getFlights()) {
                allFlights.push_back(flight);
                for (Passenger *passenger : flight->getPassengers()) {
                    allPassengers.push_back(passenger);
                }
                for (Luggage *luggage : flight->getLuggage()) {
                    allLuggage.push_back(luggage);
                }
            }
            for (Service *service : plane->getServices()) {
                allServices.push_back(service);
            }
        }
    }

    // Reescreve os ficheiros com base na informação de cada vetor
    saveLuggage(allLuggage);

}

#endif // PROJECT_AED_AGENCY_CPP