#ifndef PROJET_AED_AIRPORT_H
#define PROJET_AED_AIRPORT_H

#include <iostream>
#include <vector>
#include <string>

#include "Flight.h"
#include "Passenger.h"
#include "Plane.h"

class Airport {

    private:
        const string name;
        const string city;
        vector<Plane> planes;

    public:
        Airport();
        Airport(string name, string city, vector<Plane> planes);
        string getName() const;
        string getCity() const;
        vector<Plane> getPlanes() const;
        vector<Flight> getPossibleFlights(const string &city, const Date &date) const;
        void checkPlanes();
        void addPlane(const Plane &plane);
        void removePlane(const Plane &plane);
        void showPossibleFlights(const vector<Flight> &possibleFlights);
        bool buyTicket(Flight flight, const vector<Passenger> &passengers);
        bool operator == (const Airport &airport) const;
        bool operator < (const Airport &airport) const;
        friend bool byName(const Airport &a1, const Airport&a2);
        friend bool byQuantityOfPlanes(const Airport &a1, const Airport&a2);
};

ostream & operator << (ostream & os, const Airport &airport);

#endif //PROJET_AED_AIRPORT_H
