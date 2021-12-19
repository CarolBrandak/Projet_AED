#ifndef PROJECT_AED_AIRPORT_CPP
#define PROJECT_AED_AIRPORT_CPP

#include "Airport.h"

Airport::Airport() : CITY(""), NAME(""), transports(new Transport("","", 0, Date(0, 0))) {}

Airport::~Airport() {
    transports.makeEmpty();
}

Airport::Airport(string name, string city) : NAME(name), CITY(city), transports(new Transport("", "", 0, Date(0, 0))) {}

string Airport::getName() const {
    return NAME;
}

string Airport::getCity() const {
    return CITY;
}

BST<Transport*> Airport::getTransports() const {
    return transports;
}

vector<Transport*> Airport::getAllTransports() const {

    vector<Transport*> allTransports = {};
    BSTItrIn<Transport*> itr(this->transports);
    while (!itr.isAtEnd()) {
        allTransports.push_back(itr.retrieve());
        itr.advance();
    }
    return allTransports;
}

void Airport::addTransport(Transport *transport) {

    Transport* found = transports.find(transport);
    if (*found == Transport("", "", 0, Date(0, 0))) {
        transports.insert(transport);
    } else throw TransportAlreadyExist(transport);
}

void Airport::removeTransport(Transport *transport) {

    Transport* found = transports.find(transport);
    if (!(found == new Transport("", "", 0, Date(0, 0)))) {
        transports.remove(transport);
    } else throw TransportDoesNotExist(transport);
}

void Airport::showTransports() const {

    BSTItrIn<Transport*> itr(transports);
    while (!itr.isAtEnd()) {
        cout << *itr.retrieve() << endl;
        itr.advance();
    }
}

vector<Transport*> Airport::searchTransport(const string &type) const {

    vector<Transport*> result = {};
    BSTItrIn<Transport*> itr(transports);
    while (!itr.isAtEnd()) {
        if (itr.retrieve()->getType() == type) {
            result.push_back(itr.retrieve());
        }
        itr.advance();
    }
    return result;
}

Transport* Airport::searchTransport(const int &distance) const {

    BSTItrIn<Transport*> itr(transports);
    while (!itr.isAtEnd()) {
        if (itr.retrieve()->getDistance() == distance) {
            return itr.retrieve();
        }
        itr.advance();
    }
    return nullptr;
}

Transport* Airport::searchTransport(const int &hour, const int &minute) const {

    BSTItrIn<Transport*> itr(transports);
    while (!itr.isAtEnd()) {
        if (itr.retrieve()->getDate().getHour() == hour && itr.retrieve()->getDate().getMinute() == minute) {
            return itr.retrieve();
        }
        itr.advance();
    }
    return nullptr;
}

ostream & operator << (ostream &os, const Airport &airport) {
    os << "Nome do aeroporto: " << airport.NAME <<
        "\nCidade do aeroporto: " << airport.CITY << endl;
    return os;
}

#endif // PROJECT_AED_AIRPORT_CPP