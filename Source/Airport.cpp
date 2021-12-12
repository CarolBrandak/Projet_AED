#ifndef PROJECT_AED_AIRPORT_CPP
#define PROJECT_AED_AIRPORT_CPP

#include "Airport.h"

Airport::Airport() : city(""), name(""), transports(Transport("", 0, Date(0, 0))) {}

Airport::Airport(string name, string city) : name(name), city(city), transports(Transport("", 0, Date(0, 0))) {}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

BST<Transport> Airport::getTransports() const {
    return transports;
}

void Airport::addTransport(const Transport &transport) {

    Transport found = transports.find(transport);
    if (found == Transport("", 0, Date(0, 0))) {
        transports.insert(transport);
    }
}

void Airport::removeTransport(const Transport &transport) {

    Transport found = transports.find(transport);
    if (!(found == Transport("", 0, Date(0, 0)))) {
        transports.remove(transport);
    }
}

void Airport::showTransports() const {

    BSTItrIn<Transport> itr(transports);
    while (!itr.isAtEnd()) {
        cout << itr.retrieve() << endl;
        itr.advance();
    }
}

Transport Airport::searchTransport(const string &type) const {
    BSTItrIn<Transport> itr(transports);
    while (!itr.isAtEnd()) {
        if (itr.retrieve().getType() == type) {
            return itr.retrieve();
        }
        itr.advance();
    }
    return Transport("", 0, Date(0, 0));
}

Transport Airport::searchTransport(const int &distance) const {
    BSTItrIn<Transport> itr(transports);
    while (!itr.isAtEnd()) {
        if (itr.retrieve().getDistance() == distance) {
            return itr.retrieve();
        }
        itr.advance();
    }
    return Transport("", 0, Date(0, 0));
}

ostream& operator << (ostream &os, const Airport &airport) {
    os << airport.getCity() << " " << airport.getName() << endl;
    return os;
}

#endif // PROJECT_AED_AIRPORT_CPP