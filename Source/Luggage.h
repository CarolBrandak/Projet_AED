#ifndef Luggage_H
#define Luggage_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Struct that groups the three dimensions of the luggage
 */
struct Volume {

    /**
     * @var width, luggage's width, an integer value
     */
    int width;

    /**
     * height, luggage's height, an integer value
     */
    int height;

    /**
     * depth, luggage's width, an integer value
     */
    int depth;
};


/**
 * A class that represents a Passenger's luggage
 */
class Luggage {

    /**
     * @var WEIGHT, luggage's weight, a short integer value
     */
    short int WEIGHT;

    /**
     * @var VOLUME, luggage's volume, a struct
     */
    Volume VOLUME;

    /**
     * @var planeHold, luggage's planeHold, a boolean value
     */
    bool planeHold;

    public:

        /**
         * A default constructor of class Luggage. No arguments needed.
         */
         Luggage();

        /**
         * Main constructor
         * @param weight Luggage's weight, a short int passed by value
         * @param width Luggage's volume, a struct
         * @param planeHold Luggage's planeHold, a boolean passed by value
         */
        Luggage(short int weight, Volume volume, bool planeHold);

        /**
         * Set Luggage plane hold
         * @param planeHold Luggage's new plane hold, a boolean passed by value
         */
        void setPlaneHold(const bool &planeHold);

        /**
         * Returns Luggage's weight
         * @return a short int, containing luggage's weight
         */
        short int getWeight() const;

        /**
         * Returns Luggage's volume
         * @return an integer, representing luggage's volume
         */
        int getVolume() const;

        /**
         * Returns Plane Hold
         * @return a boolean that check if this luggage it's hand luggage
         */
        bool getPlaneHold() const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param luggage another object that will be compared
         * @return if the current object is the same of object passed by reference
         */
        bool operator == (const Luggage &luggage) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param luggage another object that will be compared
         * @return if the current object is less than object passed by reference
         */
        bool operator < (const Luggage &luggage) const;
};

/**
 * @overload
 * Function that returns all characteristics of the Luggage being manipulated
 * @param ostream object, passed by reference
 * @param luggage Luggage object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Luggage &luggage);

#endif // Luggage_H