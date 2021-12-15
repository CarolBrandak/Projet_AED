//
// Created by Fábio Sá on 15/12/2021.
//

#include "Cart.h"

Cart::Cart() : STACK_SIZE(4), QUEUE_SIZE(3) {
    this->transport = {};
}

void Cart::addLuggage(queue<Luggage *> treadmill) {

    queue<stack<Luggage*>> currentQueue = {};
    stack<Luggage*> currentStack = {};

    while (!treadmill.empty()) {

        Luggage* currentLuggage = treadmill.front();
        treadmill.pop();

        // Se tiver espaço na pilha, coloca na pilha
        if (currentStack.size() < STACK_SIZE) {
            currentStack.push(currentLuggage);
        } else {
            // Se tiver ainda espaço na fila, coloca na fila e esvazia a stack para a próxima iteração
            if (currentQueue.size() < QUEUE_SIZE) {
                currentQueue.push(currentStack);
                while (!currentStack.empty()) currentStack.pop();
            } else {
                // Senão, coloca no transporte o carrinho, esvazia a stack e a fila para a próxima iteração
                transport.push_back(currentQueue);
                while (!currentStack.empty()) currentStack.pop();
                while (!currentQueue.empty()) currentQueue.pop();
            }
        }
    }
    // No final, o restante que sobra também é adicionado
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

#include "Cart.h"
