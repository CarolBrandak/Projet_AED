#ifndef PROJECT_AED_CART_CPP
#define PROJECT_AED_CART_CPP

#include "Cart.h"

Cart::Cart() {}

void Cart::addLuggage(queue<Luggage *> treadmill) {

    queue<stack<Luggage*>> currentQueue = {};
    stack<Luggage*> currentStack = {};

    while (!treadmill.empty()) {

        Luggage* currentLuggage = treadmill.front();
        treadmill.pop();

        if (currentStack.size() < STACK_SIZE) {
            currentStack.push(currentLuggage);
        } else {

            if (currentQueue.size() < QUEUE_SIZE) {
                currentQueue.push(currentStack);
                while (!currentStack.empty()) currentStack.pop();
            } else {

                transport.push_back(currentQueue);
                while (!currentStack.empty()) currentStack.pop();
                while (!currentQueue.empty()) currentQueue.pop();
            }
        }
    }
    currentQueue.push(currentStack);
    transport.push_back(currentQueue);
}

void Cart::putLuggage(Flight* flight) {

    for (queue<stack<Luggage*>> currentCarriage : transport) {
        stack<Luggage*> currentStack = currentCarriage.front();
        while (!currentStack.empty()) {
            flight->luggage.push_back(currentStack.top());
            currentStack.pop();
        }
        currentCarriage.pop();
    }
    transport.clear();
}

#endif // PROJECT_AED_CART_CPP