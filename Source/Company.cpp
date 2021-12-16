#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Company.h"

Company::Company() : name("") {}

Company::~Company() {
    planes.clear();
}

Company::Company(string name) : name(name), planes(this->getAllPlanes()) {
    this->nextPlaneID = planes.size();
}

void Company::presentation() {
    cout << "=====================================" << endl;
    cout << "==     Welcome to " << name << " Company!   ==" << endl;
    cout << "=====================================" << endl;
}

string Company::getName() const {
    return name;
}

string Company::getNextPlaneID() {
    nextPlaneID++;
    return to_string(nextPlaneID);
}

vector<Luggage*> Company::getAllLuggages() {

    vector<Luggage*> luggage = {};
    ifstream file(LUGGAGE_FILE);

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
        throw FileNotFound(LUGGAGE_FILE);
    }
    file.close();
    return luggage;
}

vector<Passenger*> Company::getAllPassengers() {

    vector<Passenger*> passengers = {};
    ifstream file(PASSENGER_FILE);

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
        throw FileNotFound(PASSENGER_FILE);
    }
    file.close();

    vector<Luggage*> allLuggages = getAllLuggages();
    for (Passenger *passenger : passengers)
        for (Luggage *luggage : allLuggages)
            passenger->addLuggage(*luggage);

    return passengers;
}

vector<Service*> Company::getAllServices() {

    vector<Service*> services = {};
    ifstream file(SERVICE_FILE);

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
        throw FileNotFound(SERVICE_FILE);
    }
    file.close();
    return services;
}

vector<Transport*> Company::getAllTransports() {

    vector<Transport*> transports = {};
    ifstream file(TRANSPORT_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, type, distance, hour, minute;

            getline(file, id, ';');
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
    return transports;
}

vector<Flight*> Company::getAllFlights() {

    vector<Flight*> flights = {};
    ifstream file(FLIGHT_FILE);

    if (file.is_open()) {
        while (!file.eof()) {

            string id, year, month, day, hour, minute, duration, origin, destination, airportName;

            getline(file, id, ';');
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

    vector<Transport*> allTransports = getAllTransports();
    vector<Passenger*> allPassengers = getAllPassengers();

    for (Flight *flight : flights) {
        for (Transport *transport : allTransports) flight->addTransport(transport);
        for (Passenger *passenger : allPassengers) flight->addPassenger(*passenger);
    }

    return flights;
}

vector<Plane*> Company::getAllPlanes() {

    vector<Plane*> allPlanes = {};
    ifstream file(PLANE_FILE);

    try {
        if (file.is_open()) {
            while (!file.eof()) {

                string id, licencePlate, type, weightCapacity, passengerCapacity;

                getline(file, id, ';');
                getline(file, licencePlate, ';');
                getline(file, type, ';');
                getline(file, weightCapacity, ';');
                getline(file, passengerCapacity);

                allPlanes.push_back(new Plane(id, licencePlate, type, stoi(weightCapacity), stoi(passengerCapacity)));
            }
        } else {
            throw FileNotFound(PLANE_FILE);
        }
        file.close();

            vector<Service*> allServices = getAllServices();
            vector<Flight*> allFlights = getAllFlights();
            for (Plane *plane : allPlanes) {
                for (Service *service: allServices) plane->addService(*service);
                for (Flight *flight: allFlights) plane->addFlight(*flight);
            }

            this->planes = allPlanes;
            return allPlanes;

    } catch (FileNotFound error) {
        error.showError();
        exit(1);
    }
}

void Company::saveLuggage(vector<Luggage*> luggage) {

    ofstream file(LUGGAGE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < luggage.size(); i++) {
            file << luggage[i]->getID() << ";" << luggage[i]->getWeight() << ";" << luggage[i]->getVolume().width
                 << ";" << luggage[i]->getVolume().height << ";" << luggage[i]->getVolume().depth
                 << ";" << luggage[i]->getPlaneHold();
            if (i + 1 != luggage.size()) file << endl;
        }

    } else {
        throw FileNotFound(LUGGAGE_FILE);
    }
    file.close();
}

void Company::savePassengers(vector<Passenger*> passengers) {

    ofstream file(PASSENGER_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < passengers.size(); i++) {
            Passenger *p = passengers[i];
            file << p->getID() << ";" << p->getName() << ";" << p->getAge() << ";" << p->getGender() << ";" << p->getPassportNumber();
            if (i + 1 != passengers.size()) file << endl;
        }

    } else {
        throw FileNotFound(PASSENGER_FILE);
    }
    file.close();
}

void Company::saveFlights(vector<Flight*> flights) {

    ofstream file(FLIGHT_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < flights.size(); i++) {
            Flight* f = flights[i];
            file << f->getID() << ";" << f->getFlightDate().getYear() << ";" << f->getFlightDate().getMonth() << ";" << f->getFlightDate().getDay()
                 << ";" << f->getFlightDate().getHour() << ";" << f->getFlightDate().getMinute() << ";" << f->getFlightDuration()
                 << ";" << f->getFlightOrigin() << ";" << f->getFlightDestination() << ";" << f->getAirport().getName();
            if (i + 1 != flights.size()) file << endl;
        }

    } else {
        throw FileNotFound(FLIGHT_FILE);
    }
    file.close();
}

void Company::saveServices(vector<Service*> services) {

    ofstream file(SERVICE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < services.size(); i++) {
            Service* s = services[i];
            file << s->getID() << ";" << s->getServiceType() << ";" << s->getServiceDate().getYear() << ";" << s->getServiceDate().getMonth()
                 << ";" << s->getServiceDate().getDay() << ";" << s->getServiceDate().getHour() << ";" << s->getServiceDate().getMinute()
                 << ";" << s->getResponsible().getName() << ";" << s->getResponsible().getAge() << ";" << s->getResponsible().getGender();
            if (i + 1 != services.size()) file << endl;
        }

    } else {
        throw FileNotFound(SERVICE_FILE);
    }
    file.close();
}

void Company::savePlanes(vector<Plane*> planes) {

    ofstream file(PLANE_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < planes.size(); i++) {
            Plane* p = planes[i];
            file << p->getID() << ";" << p->getLicensePlate() << ";" << p->getType() << ";" << p->getMaxWeightCapacity()
                 << ";" << p->getMaxPassengersCapacity();
            if (i + 1 != planes.size()) file << endl;
        }

    } else {
        throw FileNotFound(PLANE_FILE);
    }
    file.close();
}

void Company::saveTransports(vector<Transport*> transports) {

    ofstream file(TRANSPORT_FILE);
    if (file.is_open()) {

        for (int i = 0 ; i < transports.size(); i++) {
            Transport* t = transports[i];
            file << t->getID() << ";" << t->getType() << ";" << t->getDistance() << ";" << t->getDate().getHour() << ";" << t->getDate().getMinute();
            if (i + 1 != transports.size()) file << endl;
        }

    } else {
        throw FileNotFound(TRANSPORT_FILE);
    }
    file.close();
}

void Company::addPlane(Plane &plane) {
    if (stoi(plane.getID()) > nextPlaneID) nextPlaneID++;
    planes.push_back(&plane);
}

void Company::removePlane(const string &id) {
    for (vector<Plane*>::iterator it = planes.begin() ; it != planes.end() ; it++) {
        if ((*it)->getID() == id) planes.erase(it);
    }
    cout << "Não existe avião com id = " << id << " nesta companhia aérea" << endl;
}

Flight* Company::findFlight(const string &origin, const string &destination) {
    for (Plane *plane : planes) {
        Flight* wanted = (*plane).findFlight(origin, destination);
        if (wanted) return wanted;
    }
    return nullptr;
}



void Company::refreshData() {
    this->planes = getAllPlanes();
}

void Company::save() {

    vector<Luggage*> allLuggage = {};
    vector<Passenger*> allPassengers = {};
    vector<Flight*> allFlights = {};
    vector<Service*> allServices = {};
    vector<Transport*> allTransports = {};

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
            for (Transport *transport : flight->getAirport().getAllTransports()) {
                allTransports.push_back(transport);
            }
        }
        for (Service *service : plane->getServices()) {
            allServices.push_back(service);
        }
    }

    try {
        savePlanes(planes);
        savePassengers(allPassengers);
        saveFlights(allFlights);
        saveServices(allServices);
        saveLuggage(allLuggage);
        saveTransports(allTransports);

        this->refreshData();

    } catch (FileNotFound error) {
        error.showError();
        exit(1);
    }

    allLuggage.clear();
    allPassengers.clear();
    allFlights.clear();
    allServices.clear();
    allTransports.clear();
}

#endif // PROJECT_AED_AGENCY_CPP