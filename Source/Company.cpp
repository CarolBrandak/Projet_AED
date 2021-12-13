#ifndef PROJECT_AED_AGENCY_CPP
#define PROJECT_AED_AGENCY_CPP

#include "Company.h"

Company::Company() : name("") {}

Company::~Company() {
    planes.clear();
}

Company::Company(string name) : name(name), planes(this->getAllPlanes("../Source/Files/PLanes.txt")) {
    nextPlaneID = planes.size();
}

string Company::getName() const {
    return name;
}

void Company::presentation() {
    cout << "=====================================" << endl;
    cout << "==     Welcome to " << name << " Company!   ==" << endl;
    cout << "=====================================" << endl;
}

void Company::addPlane(Plane &plane) {
    if (stoi(plane.getID()) > nextPlaneID) nextPlaneID++;
    planes.push_back(&plane);
}

int Company::getNextPlaneID() {
    nextPlaneID++;
    return nextPlaneID;
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

    vector<Luggage*> allLuggages = getAllLuggages();
    for (Passenger *passenger : passengers)
        for (Luggage *luggage : allLuggages)
            passenger->addLuggage(*luggage);

    return passengers;
}

vector<Service*> Company::getAllServices(string directory = "../Source/Files/Services.txt") {

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

vector<Transport*> Company::getAllTransports(string directory = "../Source/Files/Transports.txt") {

    vector<Transport*> transports = {};
    ifstream file(directory);

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
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
    return transports;
}

vector<Flight*> Company::getAllFlights(string directory = "../Source/Files/Flights.txt") {

    vector<Flight*> flights = {};
    ifstream file(directory);

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
        cerr << "File " << directory << " not found" << endl;
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

    vector<Service*> allServices = getAllServices();
    vector<Flight*> allFlights = getAllFlights();
    for (Plane *plane : planes) {
        for (Service *service: allServices) plane->addService(*service);
        for (Flight *flight: allFlights) plane->addFlight(*flight);
    }
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
            cout << "Todos os transportes do aeroporto de Destino:" << endl;
            (*flight).getAirport().showTransports();
        }
    }
}

void saveLuggage(vector<Luggage*> luggage, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < luggage.size(); i++) {
            file << luggage[i]->getID() << ";" << luggage[i]->getWeight() << ";" << luggage[i]->getVolume().width
                 << ";" << luggage[i]->getVolume().height << ";" << luggage[i]->getVolume().depth
                 << ";" << luggage[i]->getPlaneHold();
            if (i + 1 != luggage.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void savePassengers(vector<Passenger*> passengers, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < passengers.size(); i++) {
            Passenger *p = passengers[i];
            file << p->getID() << ";" << p->getName() << ";" << p->getAge() << ";" << p->getGender() << ";" << p->getPassportNumber();
            if (i + 1 != passengers.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void saveFlights(vector<Flight*> flights, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < flights.size(); i++) {
            Flight* f = flights[i];
            file << f->getID() << ";" << f->getFlightDate().getYear() << ";" << f->getFlightDate().getMonth() << ";" << f->getFlightDate().getDay()
                 << ";" << f->getFlightDate().getHour() << ";" << f->getFlightDate().getMinute() << ";" << f->getFlightDuration()
                 << ";" << f->getFlightOrigin() << ";" << f->getFlightDestination() << ";" << f->getAirport().getName();
            if (i + 1 != flights.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void saveServices(vector<Service*> services, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < services.size(); i++) {
            Service* s = services[i];
            file << s->getID() << ";" << s->getServiceType() << ";" << s->getServiceDate().getYear() << ";" << s->getServiceDate().getMonth()
                 << ";" << s->getServiceDate().getDay() << ";" << s->getServiceDate().getHour() << ";" << s->getServiceDate().getMinute()
                 << ";" << s->getResponsible().getName() << ";" << s->getResponsible().getAge() << ";" << s->getResponsible().getGender();
            if (i + 1 != services.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void savePlanes(vector<Plane*> planes, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < planes.size(); i++) {
            Plane* p = planes[i];
            file << p->getID() << ";" << p->getLicensePlate() << ";" << p->getType() << ";" << p->getMaxWeightCapacity()
                 << ";" << p->getMaxPassengersCapacity();
            if (i + 1 != planes.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void saveTransports(vector<Transport*> transports, const string &directory) {

    ofstream file(directory);
    if (file.is_open()) {

        for (int i = 0 ; i < transports.size(); i++) {
            Transport* t = transports[i];
            file << t->getID() << ";" << t->getType() << ";" << t->getDistance() << ";" << t->getDate().getHour() << ";" << t->getDate().getMinute();
            if (i + 1 != transports.size()) file << endl;
        }

    } else {
        cerr << "File " << directory << " not found" << endl;
    }
    file.close();
}

void Company::save() {

    vector<Luggage*> allLuggage = {};
    vector<Passenger*> allPassengers = {};
    vector<Flight*> allFlights = {};
    vector<Service*> allServices = {};
    //vector<Transport> allTransports = {};

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

    string folder = "../Source/Files/";
    savePlanes(planes, folder + "Planes.txt");
    savePassengers(allPassengers, folder + "Passengers.txt");
    saveFlights(allFlights, folder + "Flights.txt");
    saveServices(allServices, folder + "Services.txt");
    saveLuggage(allLuggage, folder + "Luggages.txt");
    //saveTransports(allTransports, folder + "Transports.txt");

    allLuggage.clear();
    allPassengers.clear();
    allFlights.clear();
    allServices.clear();
    //allTransports.clear();
}

Flight* Company::findFlight(const string &origin, const string &destination) {
    for (Plane *plane : planes) {
        Flight* wanted = (*plane).findFlight(origin, destination);
        if (wanted) return wanted;
    }
    return nullptr;
}

void Company::listing() {


}

#endif // PROJECT_AED_AGENCY_CPP