#ifndef PROJECT_AED_CART_H
#define PROJECT_AED_CART_H

#define STACK_SIZE 4
#define QUEUE_SIZE 3

#include <list>
#include <queue>
#include <stack>
#include "Luggage.h"

/**
 * A class to manage Luggage Cart
 */
class Cart {

    private:

        /**
         * @var transport - a list of queues of stacks that represent the main organization of current Cart
         */
        list<queue<stack<Luggage*>>> transport;

    public:

        /**
         * A default constructor of the class. No arguments needed.
         */
        Cart();

        /**
         * A default destructor of the class
         */
        ~Cart();

        /**
         * A function that adds luggage in current cart
         * @param treadmill - a queue based on Luggage pointer objects that contains all Luggage in order of arrival
         */
        void addLuggage(queue<Luggage *> treadmill);

        /**
         * A function that adds luggage in current flight
         * @param luggage - a vector with Luggage pointer objects that will be filled by Cart's luggage too
         */
        void putLuggage(vector<Luggage*> &luggage);
};

#endif // PROJECT_AED_CART_H
