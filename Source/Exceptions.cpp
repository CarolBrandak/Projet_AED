#ifndef PROJECT_AED_EXCEPTIONS_CPP
#define PROJECT_AED_EXCEPTIONS_CPP

#include "Exceptions.h"

// Transportes

TransportAlreadyExist::TransportAlreadyExist (Transport *transport) {}

Transport TransportAlreadyExist::getTransport() const {
    return transport;
}

void TransportAlreadyExist::showError() const {
    cout << "O transporte " << this->transport << " já existe no aeroporto" << endl;
}

TransportDoesNotExist::TransportDoesNotExist(Transport *transport) {}

Transport TransportDoesNotExist::getTransport() const {
    return transport;
}

void TransportDoesNotExist::showError() const {
    cout << "O transporte " << this->transport << " não existe no aeroporto" << endl;
}

#endif // PROJECT_AED_EXCEPTIONS_CPP