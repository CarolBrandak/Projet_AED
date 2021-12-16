#ifndef PROJECT_AED_LUGGAGE_H
#define PROJECT_AED_LUGGAGE_H

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
     * @var ID, luggage's id, a constant string
     */
    const string ID;

    /**
     * @var WEIGHT, luggage's weight, a short integer constant value
     */
    short int WEIGHT;

    /**
     * @var VOLUME, luggage's volume, a constant struct
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
         * A default destructor of class Luggage
         */
         ~Luggage();

        /**
         * Main constructor
         * @param ID Luggage's id, a string passed by value
         * @param WEIGHT Luggage's weight, a short int passed by value
         * @param VOLUME Luggage's volume, a struct
         * @param planeHold Luggage's planeHold, a boolean passed by value
         */
        Luggage(string ID, short int WEIGHT, Volume VOLUME, bool planeHold);

        /**
         * Set Luggage plane hold
         * @param planeHold Luggage's new plane hold, a boolean passed by reference
         */
        void setPlaneHold(const bool &planeHold);

        /**
         * Returns luggage's id
         * @return a string, containing luggage's id
         */
        string getID() const;

        /**
         * Returns Luggage's weight
         * @return a short int, containing luggage's weight
         */
        short int getWeight() const;

        /**
         * Returns Luggage's volume
         * @return an integer, representing luggage's volume
         */
        int getTotalVolume() const;

        /**
         * Returns Luggage's volume
         * @return an struct, representing luggage's volume
         */
        Volume getVolume() const;

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

        /**
         * @overload
         * Function that returns all characteristics of the Luggage being manipulated
         * @param ostream object, passed by reference
         * @param luggage Luggage object, passed by reference
         * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Luggage &luggage);
};

#endif //PROJECT_AED_LUGGAGE_H