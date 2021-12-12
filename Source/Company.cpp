#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Company.h"

Company::Company() : name("") {}

Company::~Company() {
    planes.clear();
}

Company::Company(string name) : name(name), planes(this->getData()) {
    nextPlaneID = planes.size();
}

string Company::getName() const {
    return name;
}

vector<Plane*> Company::getPlanes() const {
    return planes;
}

void Company::addPlane(Plane *plane) {
    if (stoi(plane->getID()) > nextPlaneID) nextPlaneID++;
    cout << planes.size() << endl;
    planes.push_back(plane);
    cout << planes.size() << endl;
}

int Company::getNextPlaneID() {
    nextPlaneID++;
    return nextPlaneID--;
}

vector<Service*> Company::getAllServices(const string directory = "../Source/Files/Services.txt") {

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

vector<Passenger*> Company::getAllPassengers(string directory = "../Source/Files/Passengers.txt") {

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

vector<Luggage*> Company::getAllLuggages(string directory = "../Source/Files/Luggages.txt") {

    vector<Luggage*> luggage = {};
    ifstream file(directory);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, weight, widtht, height, depth, planeHold;

            getline(file, id, ';');
            getline(file, weight, ';');
            getline(file, widtht, ';');
            getline(file, height, ';');
            getline(file, depth, ';');
            getline(file, planeHold);

            Volume v;
            v.width = stoi(widtht);
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

vector<Flight*> Company::getAllFlights(string directory = "../Source/Files/Flights.txt") {

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

vector<Plane*> Company::getAllPlanes(string directory = "../Source/Files/Planes.txt") {

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

void Company::printData() {

    // Aviões -> Voos -> ((Passageiros -> Bagagem) && Bagagem)

    for (Plane *plane : planes) {
        cout << "Características do avião: " << endl;
        cout << *plane << endl;
        cout << "Caracterização de cada voo implementado: " << endl;
        for (Flight *flight : plane->getFlights()) {
            cout << *flight << endl;
            for (Passenger *passenger : flight->getPassengers()) {
                cout << *passenger << endl;
                cout << "Bagagem do passageiro, planeHold = 1" << endl;
                for (Luggage *luggage : passenger->getLuggage()) {
                    cout << *luggage << endl;
                }
            }
            cout << "Bagagem do porão, planeHold = 0" << endl;
            for (Luggage *luggage : flight->getLuggage()) {
                cout << *luggage << endl;
            }
        }
    }
}

vector<Plane*> Company::getData() {

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
    vector<Plane*> allPlanes = getAllPlanes();
    for (Plane *plane : planes) {
        for (Service *service : services) {
            plane->addService(*service);
        }
        for (Flight *flight : flights) {
            plane->addFlight(*flight);
        }
    }

    // Liberta a memória gasta no processo -> mais eficiente
    luggage.clear();
    passengers.clear();
    services.clear();
    flights.clear();

    // A agência passa a conhecer TODA a informação carregada
    return allPlanes;
}

void saveLuggage(vector<Luggage*> luggage, const string &directory) {

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

void savePassengers(vector<Passenger*> passengers, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < passengers.size() - 1 ; i++) {
            Passenger *p = passengers[i];
            file << p->getID() << ";" << p->getName() << ";" << p->getAge() << ";" << p->getGender() << ";" << p->getPassportNumber() << endl;
        }
        Passenger *p = passengers[passengers.size()-1];
        file << p->getID() << ";" << p->getName() << ";" << p->getAge() << ";" << p->getGender() << ";" << p->getPassportNumber();

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void saveFlights(vector<Flight*> flights, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < flights.size()-1 ; i++) {
            Flight* f = flights[i];
            file << f->getID() << ";" << f->getFlightDate().getYear() << ";" << f->getFlightDate().getMonth() << ";" << f->getFlightDate().getDay()
                 << ";" << f->getFlightDate().getHour() << ";" << f->getFlightDate().getMinute() << ";" << f->getFlightDuration()
                 << ";" << f->getFlightOrigin() << ";" << f->getFlightDestination() << endl;
        }
        Flight* f = flights[flights.size()-1];
        file << f->getID() << ";" << f->getFlightDate().getYear() << ";" << f->getFlightDate().getMonth() << ";" << f->getFlightDate().getDay()
             << ";" << f->getFlightDate().getHour() << ";" << f->getFlightDate().getMinute() << ";" << f->getFlightDuration()
             << ";" << f->getFlightOrigin() << ";" << f->getFlightDestination();

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void saveServices(vector<Service*> services, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < services.size()-1 ; i++) {
            Service* s = services[i];
            file << s->getID() << ";" << s->getServiceType() << ";" << s->getServiceDate().getYear() << ";" << s->getServiceDate().getMonth()
                 << ";" << s->getServiceDate().getDay() << ";" << s->getServiceDate().getHour() << ";" << s->getServiceDate().getMinute()
                 << ";" << s->getResponsible().getName() << ";" << s->getResponsible().getAge() << ";" << s->getResponsible().getGender() << endl;
        }
        Service* s = services[services.size()-1];
        file << s->getID() << ";" << s->getServiceType() << ";" << s->getServiceDate().getYear() << ";" << s->getServiceDate().getMonth()
             << ";" << s->getServiceDate().getDay() << ";" << s->getServiceDate().getHour() << ";" << s->getServiceDate().getMinute()
             << ";" << s->getResponsible().getName() << ";" << s->getResponsible().getAge() << ";" << s->getResponsible().getGender();

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void savePlanes(vector<Plane*> planes, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < planes.size()-1 ; i++) {
            Plane* p = planes[i];
            file << p->getID() << ";" << p->getLicensePlate() << ";" << p->getType() << ";" << p->getMaxWeightCapacity()
                 << ";" << p->getMaxPassengersCapacity() << endl;
        }
        Plane* p = planes[planes.size()-1];
        file << p->getID() << ";" << p->getLicensePlate() << ";" << p->getType() << ";" << p->getMaxWeightCapacity()
             << ";" << p->getMaxPassengersCapacity();

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void Company::saveData(const string &folder) {

    //vector<Luggage*> allLuggage = {};
    //vector<Passenger*> allPassengers = {};
    //vector<Flight*> allFlights = {};
    //vector<Service*> allServices = {};

    /**
    for (Plane *plane : planes) {
        for (Flight *flight : plane->getFlights()) {
            allFlights.push_back(flight);
            for (Passenger *passenger : flight->getPassengers()) {
                allPassengers.push_back(passenger);
                for (Luggage *luggage : passenger->getLuggage()) {
                    allLuggage.push_back(luggage);
                }
            }
            for (Luggage *luggage : flight->getLuggage()) {
                allLuggage.push_back(luggage);
            }
        }
        for (Service *service : plane->getServices()) {
            allServices.push_back(service);
        }
    }
     */

    savePlanes(planes, folder + "Planes.txt");

    /**
    savePassengers(allPassengers, folder + "Passengers.txt");
    saveFlights(allFlights, folder + "Flights.txt");
    saveServices(allServices, folder + "Services.txt");
    saveLuggage(allLuggage, folder + "Luggages.txt");

    allLuggage.clear();
    allPassengers.clear();
    allFlights.clear();
    allServices.clear();
     */
}

Flight* Company::findFlight(const string &origin, const string &destination) {
    for (Plane *plane : planes) {
        Flight* wanted = (*plane).findFlight(origin, destination);
        if (wanted) return wanted;
    }
    return nullptr;
}

#endif // PROJECT_AED_AGENCY_CPP