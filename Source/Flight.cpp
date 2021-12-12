#ifndef PROJECT_AED_FLIGHT_CPP
#define PROJECT_AED_FLIGHT_CPP

#include "Flight.h"

Flight::Flight() {}

Flight::~Flight() {
    luggage.clear();
    passengers.clear();
}

Flight::Flight(string id, Date flightDate, short int flightDuration, string origin, string destination) :
                    id(id),
                    flightDate(flightDate),
                    FLIGHT_DURATION(flightDuration),
                    origin(origin),
                    destination(destination),
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
    return destination;
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

void Flight::addPassengers(const vector<Passenger*> &toPush) {

    Cart cart = Cart();
    vector<Luggage *> toInsert = {};

    for (Passenger *passenger: toPush) {

        string passengerId = passenger->getID();
        string idToEnter = passengerId.substr(0, passengerId.size() - passengerId.find_last_of('-'));
        string singleId = passengerId.substr(passengerId.find_last_of('-') + 1,
                                             passengerId.size() - passengerId.find_last_of('-'));

        if (id == idToEnter) {  // Se a pessoa for realmente deste voo

            if (stoi(singleId) > nextID) nextID++;                       // atualiza o próximo id automático
            this->quantityOfPassengers++;                                // aumenta o número de passageiros no voo
            this->quantityOfWeight += passenger->getTotalWeight();       // aumenta a carga levada com base na bagagem levada pelo passageiro

            vector<Luggage *> passengerLuggage = passenger->getLuggage();

            for (vector<Luggage *>::iterator it = passengerLuggage.begin(); it != passengerLuggage.end(); it++) {
                if (!(*it)->getPlaneHold()) {              // Se planeHold == 0, significa que vai para o porão
                    passenger->removeLuggage(*it);         // Removida da pessoa e colocada no carrinho
                    toInsert.push_back(*it);
                }
            }
            passengers.push_back(passenger);
        }

        cart.addLuggage(toInsert);
        cart.putLuggage(this);
    }
}

void Flight::addPassenger(Passenger& passenger) {

    string passengerId = passenger.getID();
    string idToEnter = passengerId.substr(0, passengerId.size() - passengerId.find_last_of('-'));
    string singleId = passengerId.substr(passengerId.find_last_of('-') + 1, passengerId.size() - passengerId.find_last_of('-'));

    if (id == idToEnter) {  // Se a pessoa for realmente deste voo

        Cart cart = Cart();
        vector<Luggage *> toInsert = {};

        if (stoi(singleId) > nextID) nextID++;                       // atualiza o próximo id automático
        this->quantityOfPassengers++;                                // aumenta o número de passageiros no voo
        this->quantityOfWeight += passenger.getTotalWeight();       // aumenta a carga levada com base na bagagem levada pelo passageiro

        vector<Luggage*> passengerLuggage = passenger.getLuggage();

        for (vector<Luggage*>::iterator it = passengerLuggage.begin() ; it != passengerLuggage.end() ; it++) {
            if (!(*it)->getPlaneHold()) {              // Se planeHold == 0, significa que vai para o porão
                passenger.removeLuggage(*it);         // Removida da pessoa e colocada no carrinho
                toInsert.push_back(*it);
            }
        }
        passengers.push_back(&passenger);

        cout << passenger << endl;
        cout << "neste momento o passageiro tem luggagesize = " << passenger.getLuggage().size() << endl;
        cout << "neste momento, o cart tem luggagesize = " << toInsert.size() << endl;

        cart.addLuggage(toInsert);
        cart.putLuggage(this);

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

void Cart::addLuggage(const vector<Luggage *> &luggages) {

    queue<stack<Luggage*>> currentQueue = {};
    stack<Luggage*> currentStack = {};

    cout << "Passou para colocar bagagem" << endl;

    for (Luggage* currentLuggage : luggages) {

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
    // No final, o restante também é adicionado
    transport.push_back(currentQueue);
}

void Cart::putLuggage(Flight* flight) {

    cout << "Passou para meter a bagagem no voo " << endl;

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