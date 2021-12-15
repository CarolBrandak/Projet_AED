//
// Created by Fábio Sá on 15/12/2021.
//

#ifndef PROJET_AED_CART_H
#define PROJET_AED_CART_H

#include "Luggage.h"
#include "Flight.h"

class Cart {

private:
    const int STACK_SIZE; // n de malas em cada pilha
    const int QUEUE_SIZE; // n de pilhas em cada carruagem
    list<queue<stack<Luggage*>>> transport;
public:
    Cart();
    void addLuggage(queue<Luggage *> treadmill);
    void putLuggage(Flight* flight);
};

#endif //PROJET_AED_CART_H
