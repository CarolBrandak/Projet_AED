#ifndef PROJECT_AED_AIRPORT_H
#define PROJECT_AED_AIRPORT_H

#include "BST.h"
#include "Transport.h"
#include "Exceptions.h"

/**
 * A class to manage an Airport and its transports
 */
class Airport {

    private:

        /**
         * @var city, a const string containing Airport's city
         */
        const string city;

        /**
         * @var name, const string containing Airport's name
         */
        const string name;

        /**
         * @var transports, a BST data structure constituted by Transport objects to
         *                  group Airport transports
         */
        BST<Transport*> transports;

    public:

        /**
         * A default constructor of the class
         */
        Airport();

        /**
         * A default destructor of the class
         */
        ~Airport();

        /**
         * Main constructor
         * @param name - a string containing Airport's name
         * @param city - a string containing Airport's city
         */
        Airport(string name, string city);

        /**
         * A function to get a current city
         * @return a string containing Airport's city
         */
        string getCity() const;

        /**
         * A function to get a current name
         * @return a string containing Airport's name
         */
        string getName() const;

        /**
         * A function to get all Transports
         * @return a BST data structure that groups all Transport objects
         */
        BST<Transport*> getTransports() const;

        /**
         * A function to get all Transports
         * @return a vector that groups all Transport objects
         */
        vector<Transport*> getAllTransports() const;

        /**
         * A function that adds a new transport to the BST data structure
         * @param transport - a Transport object passed by pointer that will eventually be added
         */
        void addTransport(Transport *transport);

        /**
         * A function that removes a transport from the BST data structure
         * @param transport - a Transport object passed by pointer that will eventually be removed
         */
        void removeTransport(Transport *transport);

        /**
         * @overload
         * A function that returns all Transport objects that has the same type
         * @param type - a string passed by reference that contains the wanted type of Transport
         * @return a vector with Transport objects that has the same type
         */
        vector<Transport*> searchTransport(const string &type) const;

        /**
         * @overload
         * A function that returns the Transport which has the sought distance
         * @param distance - an integer passed by reference that contains the wanted distance
         * @return a Transport object that has the same distance
         */
        Transport* searchTransport(const int &distance) const;

        /**
         * @overload
         * A function that returns the Transport which leaves at the researched time
         * @param hour - an integer value passed by reference that contains the wanted hour
         * @param minute - an integer value passed by reference that contains the wanted minute
         * @return a Transport object that has the same time
         */
        Transport* searchTransport(const int &hour, const int &minute) const;

        /**
         * A function that prints all information of Transports in BST data structure
         */
        void showTransports() const;

        /**
        * @overload
        * Function that returns all characteristics of the Airport being manipulated
        * @param os - ostream object, passed by reference
        * @param airport - Airport object, passed by reference
        * @return ostream object
        */
        friend ostream & operator << (ostream &os, const Airport &airport);
};

#endif // PROJECT_AED_AIRPORT_H