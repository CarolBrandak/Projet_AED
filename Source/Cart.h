#ifndef PROJECT_AED_CART_H
#define PROJECT_AED_CART_H

#define STACK_SIZE 4
#define QUEUE_SIZE 3

#include "Luggage.h"
#include "Flight.h"

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
         * A function that adds luggage in current cart
         * @param treadmill - a queue based on Luggage pointer objects that contains all Luggage in current Order
         */
        void addLuggage(queue<Luggage *> treadmill);

        /**
         * A function that adds luggage in current flight
         * @param flight - Flight object where the luggage will be dropped off
         */
        void putLuggage(Flight* flight);
};

#endif // PROJECT_AED_CART_H
