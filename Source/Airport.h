#ifndef PROJECT_AED_AIRPORT_H
#define PROJECT_AED_AIRPORT_H

#include <string>
#include "BST.h"
#include "Transport.h"

class Airport {

    private:
        string city;
        string name;
        BST<Transport> transports;

    public:
        Airport();
        Airport(string name, string city);
        string getCity() const;
        string getName() const;
        BST<Transport> getTransports() const;
        void addTransport(const Transport &transport);
        void removeTransport(const Transport &transport);
        void showTransports() const;
        Transport searchTransport(const string &type) const;
        Transport searchTransport(const int &distance) const;
};

ostream & operator << (ostream &os, const Airport &airport);

#endif // PROJECT_AED_AIRPORT_H
