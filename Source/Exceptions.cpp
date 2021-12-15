#ifndef PROJECT_AED_EXCEPTIONS_CPP
#define PROJECT_AED_EXCEPTIONS_CPP

#include "Exceptions.h"

// Transportes

TransportAlreadyExist::TransportAlreadyExist (Transport *transport) {
    this->transport = transport;
}

Transport TransportAlreadyExist::getTransport() const {
    return *transport;
}

void TransportAlreadyExist::showError() const {
    cout << "O transporte " << this->transport << " já existe no aeroporto" << endl;
}

TransportDoesNotExist::TransportDoesNotExist(Transport *transport) {
    this->transport = transport;
}

Transport TransportDoesNotExist::getTransport() const {
    return *transport;
}

void TransportDoesNotExist::showError() const {
    cout << "O transporte " << this->transport << " não existe no aeroporto" << endl;
}

// Datas

InvalidDate::InvalidDate(Date date) {
    this->date = date;
}

Date InvalidDate::getInvalidDate() const {
    return this->date;
}

void InvalidDate::showError() const {
    cout << "A data " << date << " é inválida" << endl;
}




#endif // PROJECT_AED_EXCEPTIONS_CPP