#ifndef PROJECT_AED_COMPANY_CPP
#define PROJECT_AED_COMPANY_CPP

#include "Company.h"

Company::Company() : NAME(" "), nextPlaneID(0) {}

Company::~Company() {
    allPlanes.clear();
}

Company::Company(string name) : NAME(name) {
    readPlanes();
    this->nextPlaneID = allPlanes.size();
}

void Company::presentation() {
    cout << "=======================================" << endl;
    cout << "== Bem-vindo a companhia aerea " << NAME << " ==" << endl;
    cout << "=======================================" << endl;
}

string Company::getName() const {
    return NAME;
}

vector<Plane*> Company::getAllPlanes() const {
    return allPlanes;
}

vector<Luggage*> Company::getAllLuggages() const {
    return allLuggage;
}

vector<Passenger*> Company::getAllPassengers() const {
    return allPassengers;
}

vector<Service*> Company::getAllServices() const {
    return allServices;
}

vector<Transport*> Company::getAllTransports() const {
    return allTransports;
}

vector<Flight*> Company::getAllFlights() const {
    return allFlights;
}

string Company::getNextPlaneID() {
    nextPlaneID++;
    return to_string(nextPlaneID);
}

void Company::readLuggage() {

    vector<Luggage*> luggage = {};
    ifstream file(LUGGAGE_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, weight, width, height, depth, planeHold;

            getline(file, id, ';');
            if (id.empty()) {
                this->allLuggage = luggage;
                return;
            }
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
        throw FileNotFound(LUGGAGE_FILE);
    }
    file.close();
    this->allLuggage = luggage;
    luggage.clear();
}

void Company::readPassengers() {

    vector<Passenger*> passengers = {};
    ifstream file(PASSENGER_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, name, age, gender, passportNumber;

            getline(file, id, ';');
            if (id.empty()) {
                this->allPassengers = passengers;
                return;
            }
            getline(file, name, ';');
            getline(file, age, ';');
            getline(file, gender, ';');
            getline(file, passportNumber);

            passengers.push_back(new Passenger(id, name, stoi(age), gender[0], passportNumber));
        }
    } else {
        throw FileNotFound(PASSENGER_FILE);
    }
    file.close();

    readLuggage();
    for (Passenger *passenger : passengers)
        for (Luggage *luggage : allLuggage)
            passenger->addLuggage(*luggage);

    this->allPassengers = passengers;
    passengers.clear();
}

void Company::readServices() {

    vector<Service*> services = {};
    ifstream file(SERVICE_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, type, name, gender, age, year, month, day, hour, minute;

            getline(file, id, ';');
            if (id.empty()) {
                this->allServices = services;
                return;
            }
            getline(file, type, ';');
            getline(file, year, ';');
            getline(file, month, ';');
            getline(file, day, ';');
            getline(file, hour, ';');
            getline(file, minute, ';');
            getline(file, name, ';');
            getline(file, age, ';');
            getline(file, gender);

            services.push_back(new Service(id, type, Date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute)), new Employee(name, stoi(age), gender[0])));
        }
    } else {
        throw FileNotFound(SERVICE_FILE);
    }
    file.close();
    this->allServices = services;
    services.clear();
}

void Company::readTransports() {

    vector<Transport*> transports = {};
    ifstream file(TRANSPORT_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, type, distance, hour, minute;

            getline(file, id, ';');
            if (id.empty()) {
                this->allTransports = transports;
                return;
            }
            getline(file, type, ';');
            getline(file, distance, ';');
            getline(file, hour, ';');
            getline(file, minute);

            transports.push_back(new Transport(id, type, stoi(distance), Date(stoi(hour), stoi(minute))));
        }
    } else {
        throw FileNotFound(TRANSPORT_FILE);
    }
    file.close();
    this->allTransports = transports;
    transports.clear();
}

void Company::readFlights() {

    vector<Flight*> flights = {};
    ifstream file(FLIGHT_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, year, month, day, hour, minute, duration, origin, destination, airportName;

            getline(file, id, ';');
            if (id.empty()) {
                this->allFlights = flights;
                return;
            }
            getline(file, year, ';');
            getline(file, month, ';');
            getline(file, day, ';');
            getline(file, hour, ';');
            getline(file, minute, ';');
            getline(file, duration, ';');
            getline(file, origin, ';');
            getline(file, destination, ';');
            getline(file, airportName);

            flights.push_back(new Flight(id, Date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute)), stoi(duration), origin, Airport(airportName, destination)));
        }
    } else {
        throw FileNotFound(FLIGHT_FILE);
    }
    file.close();

    readTransports();
    readPassengers();
    for (Flight *flight : flights) {
        for (Transport *transport : allTransports) flight->addTransport(transport);
        for (Passenger *passenger : allPassengers) flight->addPassenger(*passenger);
    }

    this->allFlights = flights;
    flights.clear();
}

void Company::readPlanes() {

    vector<Plane*> planes = {};
    ifstream file(PLANE_FILE);

    try {
        if (file.is_open()) {
            while (!file.eof()) {

                string id, licencePlate, type, weightCapacity, passengerCapacity;

                getline(file, id, ';');
                if (id.empty()) {
                    this->allPlanes = planes;
                    return;
                }
                getline(file, licencePlate, ';');
                getline(file, type, ';');
                getline(file, weightCapacity, ';');
                getline(file, passengerCapacity);

                planes.push_back(new Plane(id, licencePlate, type, stoi(weightCapacity), stoi(passengerCapacity)));
            }
        } else {
            throw FileNotFound(PLANE_FILE);
        }
        file.close();

            readServices();
            readFlights();

            for (Plane *plane : planes) {
                for (Service *service: allServices) plane->addService(*service);
                for (Flight *flight: allFlights) plane->addFlight(*flight);
            }

            this->allPlanes = planes;
            planes.clear();

    } catch (FileNotFound &error) {
        error.showError();
        exit(1);
    }
}

void Company::saveLuggage() {

    ofstream file(LUGGAGE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allLuggage.size(); i++) {
            file << allLuggage[i]->getID() << ";" << allLuggage[i]->getWeight() << ";" << allLuggage[i]->getVolume().width
                 << ";" << allLuggage[i]->getVolume().height << ";" << allLuggage[i]->getVolume().depth
                 << ";" << allLuggage[i]->getPlaneHold();
            if (i + 1 != allLuggage.size()) file << endl;
        }

    } else {
        throw FileNotFound(LUGGAGE_FILE);
    }
    file.close();
}

void Company::savePassengers() {

    ofstream file(PASSENGER_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allPassengers.size(); i++) {
            Passenger *p = allPassengers[i];
            file << p->getID() << ";" << p->getName() << ";" << p->getAge() << ";" << p->getGender() << ";" << p->getPassportNumber();
            if (i + 1 != allPassengers.size()) file << endl;
        }

    } else {
        throw FileNotFound(PASSENGER_FILE);
    }
    file.close();
}

void Company::saveFlights() {

    ofstream file(FLIGHT_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allFlights.size(); i++) {
            Flight* f = allFlights[i];
            file << f->getID() << ";" << f->getFlightDate().getYear() << ";" << f->getFlightDate().getMonth() << ";" << f->getFlightDate().getDay()
                 << ";" << f->getFlightDate().getHour() << ";" << f->getFlightDate().getMinute() << ";" << f->getFlightDuration()
                 << ";" << f->getFlightOrigin() << ";" << f->getFlightDestination() << ";" << f->getAirport().getName();
            if (i + 1 != allFlights.size()) file << endl;
        }

    } else {
        throw FileNotFound(FLIGHT_FILE);
    }
    file.close();
}

void Company::saveServices() {

    ofstream file(SERVICE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allServices.size(); i++) {
            Service* s = allServices[i];
            file << s->getID() << ";" << s->getServiceType() << ";" << s->getServiceDate().getYear() << ";" << s->getServiceDate().getMonth()
                 << ";" << s->getServiceDate().getDay() << ";" << s->getServiceDate().getHour() << ";" << s->getServiceDate().getMinute()
                 << ";" << s->getResponsible()->getName() << ";" << s->getResponsible()->getAge() << ";" << s->getResponsible()->getGender();
            if (i + 1 != allServices.size()) file << endl;
        }

    } else {
        throw FileNotFound(SERVICE_FILE);
    }
    file.close();
}

void Company::savePlanes() {

    ofstream file(PLANE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allPlanes.size(); i++) {
            Plane* p = allPlanes[i];
            file << p->getID() << ";" << p->getLicensePlate() << ";" << p->getType() << ";" << p->getMaxWeightCapacity()
                 << ";" << p->getMaxPassengersCapacity();
            if (i + 1 != allPlanes.size()) file << endl;
        }

    } else {
        throw FileNotFound(PLANE_FILE);
    }
    file.close();
}

void Company::saveTransports() {

    ofstream file(TRANSPORT_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < allTransports.size(); i++) {
            Transport* t = allTransports[i];
            file << t->getID() << ";" << t->getType() << ";" << t->getDistance() << ";" << t->getDate().getHour() << ";" << t->getDate().getMinute();
            if (i + 1 != allTransports.size()) file << endl;
        }

    } else {
        throw FileNotFound(TRANSPORT_FILE);
    }
    file.close();
}

void Company::addPlane(Plane &plane) {
    if (stoi(plane.getID()) > nextPlaneID) nextPlaneID++;
    allPlanes.push_back(&plane);
}

void Company::addFlight(Flight &flight) {
    allFlights.push_back(&flight);
}

void Company::addLuggage(Luggage &l) {
    allLuggage.push_back(&l);
}

void Company::addPassenger(Passenger &passenger) {
    allPassengers.push_back(&passenger);
}

void Company::addService(Service &service) {
    allServices.push_back(&service);
}

void Company::addTransport(Transport &transport) {
    allTransports.push_back(&transport);
}

bool Company::removePlane(const string &id) {
    for (auto it = allPlanes.begin() ; it != allPlanes.end() ; it++) {
        if ((*it)->getID() == id) {
            removeFlight(id);
            removeService(id);
            allPlanes.erase(it);
            return true;
        }
    }
    return false;
}

void Company::removeFlight(Flight &flight) {
    for (auto it = allFlights.begin() ; it != allFlights.end() ; it++) {
        if ((*it) == &flight) {
            allFlights.erase(it);
            removePassenger(flight.getID());
            removeTransport(flight.getID());
            it--;
        }
    }
}

void Company::removeFlight (const string &id) {

    for (auto it = allFlights.begin() ; it != allFlights.end() ; it++) {
        if (id.size() <= 2) {
            if ((*it)->getID().substr(0, (*it)->getID().find('-')) == id) {
                removePassenger((*it)->getID());
                removeLuggage((*it)->getID());
                removeTransport((*it)->getID());
                allFlights.erase(it);
                it--;
            }
        } else {
            if ((*it)->getID() == id) {
                removePassenger((*it)->getID());
                removeLuggage((*it)->getID());// 1-1
                removeTransport((*it)->getID());
                allFlights.erase(it);
                it--;
            }
        }
    }
}

void Company::removeLuggage(const string &id) {
    for (auto it = allLuggage.begin() ; it != allLuggage.end() ; it++ ) {
        if ((*it)->getID() == id) {
            allLuggage.erase(it);
            it--;
        }
    }
}

void Company::removeLuggage(Luggage &l) {
    for (auto it = allLuggage.begin() ; it != allLuggage.end() ; it++ ) {
        if ((*it) == &l) {
            allLuggage.erase(it);
            it--;
        }
    }
}

void Company::removePassenger(Passenger &passenger) {
    for (auto it = allPassengers.begin() ; it != allPassengers.end() ; it++) {
        if ((*it)->getID() == passenger.getID()) {
            removeLuggage((*it)->getID());
            allPassengers.erase(it);
            return;
        }
    }
}

void Company::removePassenger(const string &id) {
    for (auto it = allPassengers.begin() ; it != allPassengers.end() ; it++) {
        if ((*it)->getID().find('-') == (*it)->getID().find_last_of('-')) {
            if ((*it)->getID() == id) {
                removeLuggage((*it)->getID());
                allPassengers.erase(it);
                it--;
            }
        } else {
            if ((*it)->getID().substr(0, (*it)->getID().find_last_of('-')) == id) {
                removeLuggage((*it)->getID());
                allPassengers.erase(it);
                it--;
            }
        }
    }
}

void Company::removeService(const string &id) {
    for (auto it = allServices.begin() ; it != allServices.end() ; it++) {
        if (id.size() <= 2) {
            if ((*it)->getID().substr(0, (*it)->getID().find_last_of('-')) == id) {
                allServices.erase(it);
                it--;
            }
        } else {
            if ((*it)->getID() == id) {
                allServices.erase(it);
                it--;
            }
        }
    }
}

void Company::removeService(Service &service) {
    for (auto it = allServices.begin() ; it != allServices.end() ; it++) {
        if ((*it) == &service) {
            allServices.erase(it);
            it--;
        }
    }
}

void Company::setServiceResponsible(Service &s, Employee &employee) {
    for (auto *service : allServices) if (*service == s) service->setResponsible(employee);
}

void Company::removeTransport(const string &id) {
    for (auto it = allTransports.begin() ; it != allTransports.end() ; it++) {
        if ((*it)->getID() == id) {
            allTransports.erase(it);
            it--;
        }
    }
}

void Company::removeTransport(Transport &transport) {
    for (auto it = allTransports.begin() ; it != allTransports.end() ; it++) {
        if ((*it)->getID() == transport.getID() && (*it)->getType() == (*it)->getType()
                    && (*it)->getDistance() == transport.getDistance()) {
            allTransports.erase(it);
            it--;
        }
    }
}

Plane* Company::findPlane(const string &id) {
    for (Plane *plane : allPlanes) {
        if (plane->getID() == id) return plane;
    }
    return nullptr;
}

Flight* Company::findFlight(const string &origin, const string &destination) {
    for (Plane *plane : allPlanes) {
        Flight* wanted = (*plane).findFlight(origin, destination);
        if (wanted) return wanted;
    }
    return nullptr;
}

void Company::refreshData() {
    readPlanes();
}

void Company::save() {

    try {
        savePlanes();
        savePassengers();
        saveFlights();
        saveServices();
        saveLuggage();
        saveTransports();
        this->refreshData();

    } catch (FileNotFound &error) {
        error.showError();
        exit(1);
    }
}

#endif // PROJECT_AED_COMPANY_CPP