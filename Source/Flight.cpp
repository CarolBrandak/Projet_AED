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

void Flight::checkPassengers() {
    for (auto *passenger : passengers) {
        cout << *passenger << endl;
    }
}







bool Flight::operator == (const Flight &flight) const {
    return id == flight.getID();
}

bool Flight::operator < (const Flight &flight) const {
    return id < flight.getID();
}

bool byNumberOfPassengers(const Flight &f1, const Flight &f2) {
    return f1.quantityOfPassengers < f2.quantityOfPassengers;
}

bool byTotalWeight(const Flight &f1, const Flight &f2) {
    return f1.quantityOfWeight < f2.quantityOfWeight;
}

bool byDate(const Flight &f1, const Flight &f2) {
    return f1.flightDate < f2.flightDate;
}

bool byDuration(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DURATION < f2.FLIGHT_DURATION;
}

void Flight::addTransport(Transport *transport) {
    if (ID == transport->getID()) airport.addTransport(transport);
    else cout << "O transporte não pertence a este voo" << endl;
}

void Flight::removeTransport(Transport *transport) {
    if (ID == transport->getID()) airport.removeTransport(transport);
    else cout << "O transporte não pertence a este voo" << endl;
}

void Flight::addPassengers(const vector<Passenger*> &toPush) {

    Cart cart = Cart();
    queue<Luggage *> treadmill = {};

    for (Passenger *passenger: toPush) {

        string passengerId = passenger->getID();
        string idToEnter = passengerId.substr(0, passengerId.find_last_of('-'));
        string singleId = passengerId.substr(passengerId.find_last_of('-') + 1);

        if (id == idToEnter) {  // Se a pessoa for realmente deste voo

            if (stoi(singleId) > nextID) nextID++;                       // atualiza o próximo id automático
            this->quantityOfPassengers++;                                // aumenta o número de passageiros no voo
            this->quantityOfWeight += passenger->getTotalWeight();       // aumenta a carga levada com base na bagagem levada pelo passageiro

            vector<Luggage *> passengerLuggage = passenger->getLuggage();

            for (vector<Luggage *>::iterator it = passengerLuggage.begin(); it != passengerLuggage.end(); it++) {
                if (!((*it)->getPlaneHold())) {              // Se planeHold == 0, significa que vai para o porão
                    passenger->removeLuggage(*it);         // Removida da pessoa e colocada no carrinho
                    treadmill.push(*it);
                }
            }
            passengers.push_back(passenger);
        }

        if (!treadmill.empty()) {                   // se o tapete rolante tiver alguma mala
            cart.addLuggage(treadmill);             // essa mala passa para o carrinho
            cart.putLuggage(this);                  // e o carrinho deposita-a no voo
        }
    }
}

void Flight::addPassenger(Passenger& passenger) {

    string passengerId = passenger.getID();
    string idToEnter = passengerId.substr(0, passengerId.find_last_of('-'));
    string singleId = passengerId.substr(passengerId.find_last_of('-') + 1);

    if (id == idToEnter) {  // Se a pessoa for realmente deste voo

        Cart cart = Cart();
        queue<Luggage *> treadmill = {};

        if (stoi(singleId) > nextID) nextID++;                       // atualiza o próximo id automático
        this->quantityOfPassengers++;                                // aumenta o número de passageiros no voo
        this->quantityOfWeight += passenger.getTotalWeight();       // aumenta a carga levada com base na bagagem levada pelo passageiro

        vector<Luggage*> passengerLuggage = passenger.getLuggage();

        for (vector<Luggage*>::iterator it = passengerLuggage.begin() ; it != passengerLuggage.end() ; it++) {
            if (!((*it)->getPlaneHold())) {              // Se planeHold == 0, significa que vai para o porão
                passenger.removeLuggage(*it);         // Removida da pessoa e colocada no carrinho
                treadmill.push(*it);
            }
        }
        passengers.push_back(&passenger);

        if (!treadmill.empty()) {                   // se o tapete rolante tiver alguma mala
            cart.addLuggage(treadmill);             // essa mala passa para o carrinho
            cart.putLuggage(this);                  // e o carrinho deposita-a no voo
        }

    } else return;
}

void Flight::removePassenger(Passenger &passenger) {

    // Remover um passageiro do voo é também remover a sua bagagem:

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



std::ostream & operator << (std::ostream & os, const Flight &flight) {
    os  << "Flight ID: " << flight.getID()
        << "\nFlight Date: " << flight.getFlightDate()
        << "Flight Duration: " << flight.getFlightDuration()
        << " minutes\nOrigin: " << flight.getFlightOrigin()
        << "\nDestination: "<< flight.getFlightDestination()
        << "\nQuantity of Weight: " << flight.getWeightQuantity()
        << " Kgs\nQuantity Of Passengers: " << flight.getPassengersQuantity() << endl;
    return os;
}

#endif // PROJECT_AED_FLIGHT_CPP