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
        void buyFlight(Flight flight, const vector<Passenger> &passengers);
        bool operator == (const Airport &airport) const;
        bool operator < (const Airport &airport) const;
};

ostream & operator << (ostream & os, const Airport &airport);

#endif //PROJET_AED_AIRPORT_H
