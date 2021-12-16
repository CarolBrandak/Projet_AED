#ifndef PROJECT_AED_PLANE_CPP
#define PROJECT_AED_PLANE_CPP

#include "Plane.h"

Plane::Plane() : MAX_WEIGHT_CAPACITY(0), MAX_PASSENGERS_CAPACITY(0),
                        LICENSE_PLATE(""), TYPE("") {}

Plane::~Plane() {
    flights.clear();
    while (!servicesToBeMade.empty()) servicesToBeMade.pop();
    while (!madeServices.empty()) madeServices.pop_back();
}

Plane::Plane(string ID,
             string LICENSE_PLATE,
             string TYPE,
             unsigned int MAX_WEIGHT_CAPACITY,
             unsigned int MAX_PASSENGERS_CAPACITY) :

             ID(ID),
             LICENSE_PLATE(LICENSE_PLATE),
             TYPE(TYPE),
             MAX_WEIGHT_CAPACITY(MAX_WEIGHT_CAPACITY),
             MAX_PASSENGERS_CAPACITY(MAX_PASSENGERS_CAPACITY) {

             this->flights = {};
             this->madeServices = {};
             this->servicesToBeMade = {};
             nextFlightID = 0;
}

string Plane::getID() const {
    return ID;
}

std::string Plane::getLicensePlate() const {
    return LICENSE_PLATE;
}

std::string Plane::getType() const {
    return TYPE;
}

list<Flight*> Plane::getFlights() const {
    return flights;
}

vector<Flight*> Plane::getVectorFlights() const {
    vector<Flight*> result = {};
    for (auto i = flights.begin() ; i != flights.end() ; i++) {
        result.push_back(*i);
    }
    return result;
}

vector<Service*> Plane::getServices() const {
    vector<Service*> services = {};
    queue<Service*> copy = this->servicesToBeMade;
    while (!copy.empty()) {
        Service* s = copy.front();
        services.push_back(s);
        copy.pop();
    }
    return services;
}

unsigned int Plane::getMaxWeightCapacity() const {
    return MAX_WEIGHT_CAPACITY;
}

unsigned int Plane::getMaxPassengersCapacity() const {
    return MAX_PASSENGERS_CAPACITY;
}

unsigned int Plane::getQuantityOfFlights() const {
    return flights.size();
}

unsigned int Plane::getQuantityOfServicesToBeMade() const {
    return servicesToBeMade.size();
}

unsigned int Plane::getQuantityOfMadeServices() const {
    return madeServices.size();
}

string Plane::getNextFlightID() {
    nextFlightID++;
    return this->ID + "-" + to_string(nextFlightID);
}

void Plane::setNextServiceAsDone() {
    if (!servicesToBeMade.empty()) {
        madeServices.push_back(servicesToBeMade.front());
        cout << "Realizado o serviço " << servicesToBeMade.front() << endl;
        servicesToBeMade.pop();
    } else {
        cout << "Não há mais serviços para efetuar" << endl;
    }
}

void Plane::checkServicesToBeMade() {
    queue<Service*> copy = servicesToBeMade;
    while (!copy.empty()) {
        cout << copy.front();
        copy.pop();
    }
}

void Plane::checkMadeServices() {
    for (auto const *service : madeServices)
        cout << *service;
}

void Plane::checkFlights() {
    for (auto *flight : flights) {
        cout << *flight << endl;
    }
}

void Plane::addFlight(Flight &flight) {
    if (ID == flight.getID().substr(0, flight.getID().find('-'))) flights.push_back(&flight);
    if (stoi(flight.getID().substr(flight.getID().find('-') + 1)) > nextFlightID) nextFlightID++;
}

void Plane::removeFlight(const string &id) {
    for (auto it = flights.begin() ; it != flights.end() ; it++) {
        if((*it)->getID() == id) {
            flights.erase(it);
            cout << "Voo removido com sucesso" << endl;
            return;
        }
    }
    cout << "Voo não encontrado" << endl;
}

Flight* Plane::findFlight(const string &origin, const string &destination) {
    for (Flight *f : flights) {
        if ((*f).getFlightOrigin() == origin && (*f).getFlightDestination() == destination) return f;
    }
    return nullptr;
}

void Plane::addService(Service &service) {
    if (ID == service.getID().substr(0, service.getID().find('-'))) servicesToBeMade.push(&service);
}

Service* Plane::findService(Date &date) {
    queue<Service*> copy = this->servicesToBeMade;
    while (!copy.empty()) {
        if (copy.front()->getServiceDate() == date) return copy.front();
        copy.pop();
    }
    return nullptr;
}

Employee* Plane::findEmployee(const string &name) {
    queue<Service*> copy = this->servicesToBeMade;
    while (!copy.empty()) {
        if (copy.front()->getResponsible().getName() == name) {
            Employee *employee = new Employee();
            *employee = copy.front()->getResponsible();
            return employee;
        }
        copy.pop();
    }
    return nullptr;
}

vector<Employee*> Plane::getEmployees() {
    vector<Employee*> allEmployees = {};
    queue<Service*> copy = this->servicesToBeMade;
    while(!copy.empty()) {
        Employee currentEmployee = copy.front()->getResponsible();
        Employee* reference = &currentEmployee;
        allEmployees.push_back(reference);
        copy.pop();
    }
    return allEmployees;
}

bool Plane::operator == (const Plane &plane) const {
    return this->ID == plane.ID && this->LICENSE_PLATE == plane.LICENSE_PLATE && this->TYPE == plane.TYPE &&
                this->MAX_PASSENGERS_CAPACITY == plane.MAX_PASSENGERS_CAPACITY && this->MAX_WEIGHT_CAPACITY == plane.MAX_PASSENGERS_CAPACITY;
}

bool Plane::operator < (const Plane &plane) const {
    if (MAX_PASSENGERS_CAPACITY == plane.MAX_PASSENGERS_CAPACITY) return MAX_WEIGHT_CAPACITY < plane.MAX_WEIGHT_CAPACITY;
    return MAX_PASSENGERS_CAPACITY < plane.MAX_PASSENGERS_CAPACITY;
}

ostream & operator << (ostream & os, const Plane &plane) {
    os << "ID: " << plane.ID <<
        "\nLicense Plate: " << plane.LICENSE_PLATE <<
        "\nType: " << plane.TYPE <<
        "\nMax Weight Capacity: "  << plane.MAX_WEIGHT_CAPACITY <<
        "\nMax Passengers Capacity: " << plane.MAX_PASSENGERS_CAPACITY <<
        "\nQuantity of flights: " << plane.getQuantityOfFlights() <<
        "\nQuantity of services to be made: " << plane.getQuantityOfServicesToBeMade() <<
        "\nQuantity of made services: " << plane.getQuantityOfMadeServices() << endl;
    return os;
}

#endif // PROJECT_AED_PLANE_CPP