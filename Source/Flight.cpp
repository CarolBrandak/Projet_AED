#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"

Flight::Flight() : FLIGHT_DATE(Date(0, 0)), FLIGHT_DURATION(-1), ORIGIN("") {}

Flight::~Flight() {
    luggage.clear();
    passengers.clear();
}

Flight::Flight(string id, Date flightDate, short int flightDuration, string origin, Airport airport) :
                    ID(id),
                    FLIGHT_DATE(flightDate),
                    FLIGHT_DURATION(flightDuration),
                    ORIGIN(origin),
                    airport(airport),
                    quantityOfPassengers(0),
                    quantityOfWeight(0) {
                    this->luggage = {};
                    this->passengers = {};
                    nextID = 0;
}

string Flight::getID() const {
    return ID;
}

Date Flight::getFlightDate() const {
    return FLIGHT_DATE;
}

short int Flight::getFlightDuration() const {
    return FLIGHT_DURATION;
}

string Flight::getFlightOrigin() const {
    return ORIGIN;
}

string Flight::getFlightDestination() const {
    return airport.getCity();
}

Airport Flight::getAirport() {
    return airport;
}

unsigned int Flight::getPassengersQuantity() const {
    return quantityOfPassengers;
}

unsigned int Flight::getWeightQuantity() const {
    return quantityOfWeight;
}

vector<Passenger*> Flight::getPassengers() const {
    return passengers;
}

vector<Luggage*> Flight::getLuggage() const {
    return luggage;
}

string Flight::getNextPassengerID() {
    nextID++;
    return this->getID() + "-" + to_string(nextID);
}

vector<Transport*> Flight::getAllTransports() {
    return airport.getAllTransports();
}

void Flight::checkPassengers() {
    for (auto *passenger : passengers) {
        cout << *passenger << endl;
    }
}

void Flight::addTransport(Transport *transport) {
    if (ID == transport->getID()) airport.addTransport(transport);
}

void Flight::removeTransport(Transport *transport) {
    if (ID == transport->getID()) airport.removeTransport(transport);
    else cout << "O transporte nao existe neste voo" << endl;
}

Transport* Flight::searchTransport(const int &hour, const int &minute) {
    return airport.searchTransport(hour, minute);
}

vector<Transport*> Flight::searchTransport(const string &type) {
    return airport.searchTransport(type);
}

Transport* Flight::searchTransport(const int &distance) {
    return airport.searchTransport(distance);
}

void Flight::addPassenger(Passenger& passenger) {

    string passengerId = passenger.getID();
    string idToEnter = passengerId.substr(0, passengerId.find_last_of('-'));
    string singleId = passengerId.substr(passengerId.find_last_of('-') + 1);

    if (ID == idToEnter) {

        queue<Luggage *> treadmill = {};

        if (stoi(singleId) > nextID) nextID++;
        this->quantityOfPassengers++;
        this->quantityOfWeight += passenger.getTotalWeight();

        vector<Luggage*> passengerLuggage = passenger.getLuggage();

        for (vector<Luggage*>::iterator it = passengerLuggage.begin() ; it != passengerLuggage.end() ; it++) {

            if ((*it)->getPlaneHold())
                if ((*it)->getTotalVolume() > MAX_HAND_LUGGAGE_VOLUME || (*it)->getWeight() > MAX_HAND_LUGGAGE_HEIGHT)
                    (*it)->setPlaneHold(false);

            if (!((*it)->getPlaneHold())) {
                passenger.removeLuggage(*it);
                treadmill.push(*it);
            }
        }
        passengers.push_back(&passenger);

        if (!treadmill.empty()) {
            Cart cart = Cart();
            cart.addLuggage(treadmill);
            cart.putLuggage(this->luggage);
        }

    } else return;
}

void Flight::removePassenger(Passenger &passenger) {

    for (Luggage *l : passenger.getLuggage()) {
        for (auto it = luggage.begin() ; it != luggage.end() ; it++) {
            if (l == *it) {
                luggage.erase(it);
                it--;
            }
        }
    }

    for (auto it = passengers.begin() ; it != passengers.end() ; it++) {
        if (&passenger == *it) {
            this->quantityOfPassengers--;
            this->quantityOfWeight -= passenger.getTotalWeight();
            passengers.erase(it);
            break;
        }
    }
}

Passenger* Flight::findPassenger(const string &passport) {

    for (Passenger *p : passengers) {
        if (p->getPassportNumber() == passport) return p;
    }
    return nullptr;
}

void Flight::addLuggage(Luggage *l) {
    if (ID == l->getID().substr(0, l->getID().find_last_of('-'))) {
        luggage.push_back(l);
        quantityOfWeight += l->getWeight();
        return;
    }
}

void Flight::removeLuggage(const string &id) {
    for (vector<Luggage*>::iterator it = luggage.begin() ; it != luggage.end() ; it++) {
        if ((*it)->getID() == id) {
            luggage.erase(it);
            quantityOfWeight -= (*it)->getWeight();
            return;
        }
    }
}

Luggage* Flight::findLuggage(const string &id) {
    for (Luggage* l : luggage) {
        if (l->getID().substr(0, l->getID().find_last_of('-')) == ID) return l;
    }
    return nullptr;
}

bool Flight::operator == (const Flight &flight) const {
    return ID == flight.ID && FLIGHT_DURATION == flight.FLIGHT_DURATION && FLIGHT_DATE == flight.FLIGHT_DATE &&
            ORIGIN == flight.ORIGIN;
}

bool Flight::operator < (const Flight &flight) const {
    if (FLIGHT_DATE == flight.FLIGHT_DATE) {
        return ID < flight.ID;
    } return FLIGHT_DATE < flight.FLIGHT_DATE;
}

ostream & operator << (ostream & os, const Flight &flight) {
    os  << "ID: " << flight.ID
        << "\nData: " << flight.FLIGHT_DATE
        << "Duracao: " << flight.FLIGHT_DURATION
        << " minutos\nOrigem: " << flight.ORIGIN
        << "\nDestino: "<< flight.airport.getCity()
        << "\nQuantidade de carga que leva: " << flight.quantityOfWeight
        << " Kgs\nQuantidade de passageiros que leva: " << flight.quantityOfPassengers << endl;
    return os;
}

#endif // PROJECT_AED_FLIGHT_CPP