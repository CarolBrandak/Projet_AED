#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"


Flight::~Flight() {
    luggage.clear();
    passengers.clear();
}

Flight::Flight(string id, Date flightDate, short int flightDuration, string origin, Airport airport) :
                    id(id),
                    flightDate(flightDate),
                    FLIGHT_DURATION(flightDuration),
                    origin(origin),
                    airport(airport),
                    quantityOfPassengers(0),
                    quantityOfWeight(0) {
                    this->luggage = {};
                    this->passengers = {};
                    nextID = 0;
}

int Flight::getNextPassengerID() {
    nextID++;
    return nextID--;
}

string Flight::getID() const {
    return id;
}

Date Flight::getFlightDate() const {
    return flightDate;
}

void Flight::setFlightDate(const Date &newDate) {
    this->flightDate = newDate;
}

short int Flight::getFlightDuration() const {
    return FLIGHT_DURATION;
}

string Flight::getFlightOrigin() const {
    return origin;
}

string Flight::getFlightDestination() const {
    return airport.getCity();
}

unsigned int Flight::getPassengersQuantity() const {
    return quantityOfPassengers;
}

unsigned int Flight::getWeightQuantity() const {
    return quantityOfWeight;
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

Airport Flight::getAirport() {
    return airport;
}

void Flight::addTransport(Transport *transport) {
    if (id == transport->getID()) airport.addTransport(transport);
}

void Flight::addPassengers(const vector<Passenger*> &toPush) {

    Cart cart = Cart();
    queue<Luggage *> treadmill = {};

    for (Passenger *passenger: toPush) {

        string passengerId = passenger->getID();
        string idToEnter = passengerId.substr(0, passengerId.size() - passengerId.find_last_of('-') + 1);
        string singleId = passengerId.substr(passengerId.find_last_of('-'),
                                             passengerId.size() - passengerId.find_last_of('-'));

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

    // passengerId.size() - passengerId.find_last_of('-') - 1
    string passengerId = passenger.getID();
    string idToEnter = passengerId.substr(0, passengerId.size() - passengerId.find_last_of('-') + 1);
    string singleId = passengerId.substr(passengerId.find_last_of('-') + 1, passengerId.size() - passengerId.find_last_of('-'));

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

void Flight::checkPassengers() {
    for (auto *passenger : passengers) {
        cout << *passenger << endl;
    }
}

vector<Passenger*> Flight::getPassengers() const {
    return passengers;
}

vector<Luggage*> Flight::getLuggage() const {
    return luggage;
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

Cart::Cart() : STACK_SIZE(4), QUEUE_SIZE(3) {
    this->transport = {};
}

void Cart::addLuggage(queue<Luggage *> treadmill) {

    queue<stack<Luggage*>> currentQueue = {};
    stack<Luggage*> currentStack = {};

    while (!treadmill.empty()) {

        Luggage* currentLuggage = treadmill.front();
        treadmill.pop();

        // Se tiver espaço na pilha, coloca na pilha
        if (currentStack.size() < STACK_SIZE) {
            currentStack.push(currentLuggage);
        } else {
            // Se tiver ainda espaço na fila, coloca na fila e esvazia a stack para a próxima iteração
            if (currentQueue.size() < QUEUE_SIZE) {
                currentQueue.push(currentStack);
                while (!currentStack.empty()) currentStack.pop();
            } else {
                // Senão, coloca no transporte o carrinho, esvazia a stack e a fila para a próxima iteração
                transport.push_back(currentQueue);
                while (!currentStack.empty()) currentStack.pop();
                while (!currentQueue.empty()) currentQueue.pop();
            }
        }
    }
    // No final, o restante que sobra também é adicionado
    currentQueue.push(currentStack);
    transport.push_back(currentQueue);
}

void Cart::putLuggage(Flight* flight) {

    for (queue<stack<Luggage*>> currentCarriage : transport) {
        stack<Luggage*> currentStack = currentCarriage.front();
        while (!currentStack.empty()) {
            flight->luggage.push_back(currentStack.top());
            currentStack.pop();
        }
        currentCarriage.pop();
    }
    transport.clear();
}

#endif // PROJECT_AED_FLIGHT_CPP