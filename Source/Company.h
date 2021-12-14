#ifndef PROJECT_AED_AGENCY_H
#define PROJECT_AED_AGENCY_H

#define FOLDER "../Source/Files/"
#define FLIGHT_FILE "../Source/Files/Flights.txt"
#define LUGGAGE_FILE "../Source/Files/Luggages.txt"
#define PASSENGER_FILE "../Source/Files/Passengers.txt"
#define PLANE_FILE "../Source/Files/Planes.txt"
#define SERVICE_FILE "../Source/Files/Services.txt"
#define TRANSPORT_FILE "../Source/Files/Transports.txt"

#include <vector>
#include <fstream>
#include <algorithm>
#include "Plane.h"

/**
 A class to manage an Company
 */
class Company {

    private:

        const string name;
        vector<Plane*> planes;
        int nextPlaneID;

    public:

        // Construtores
        Company();
        Company(string name);
        ~Company();

        // Init
        void presentation();

        // Getters
        string getName() const;
        int getNextPlaneID();
        vector<Luggage*> getAllLuggages();
        vector<Passenger*> getAllPassengers();
        vector<Service*> getAllServices();
        vector<Transport*> getAllTransports();
        vector<Flight*> getAllFlights();
        vector<Plane*> getAllPlanes();

        // Add
        void addPlane(Plane &plane);


        // Remove


        // Search
        Flight* findFlight(const string &origin, const string &destination);

        // Save
        void refreshData();
        void save();
};

#endif // PROJECT_AED_AGENCY_H
