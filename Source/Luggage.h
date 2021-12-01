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
         * @param planeHold Luggage's new plane hold, a boolean passed by reference
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

        /**
         * Boolean function thar compares to objects of this class, based on their weight
         * @param l1 first luggage that will be compared
         * @param l2 second luggage object that will be compared
         * @return if l1 has less weight than l2
         */
        friend bool byWeight(const Luggage &l1, const Luggage &l2);

        /**
         * Boolean function thar compares to objects of this class, based on their volume
         * @param l1 first luggage that will be compared
         * @param l2 second luggage object that will be compared
         * @return if l1 has less volume than l2
         */
        friend bool byVolume(const Luggage &l1, const Luggage &l2);
};

/**
 * @overload
 * Function that returns all characteristics of the Luggage being manipulated
 * @param ostream object, passed by reference
 * @param luggage Luggage object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Luggage &luggage);

#endif //PROJECT_AED_LUGGAGE_H