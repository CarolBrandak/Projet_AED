#ifndef PROJECT_AED_EXCEPTIONS_H
#define PROJECT_AED_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>
#include "Transport.h"
#include "Date.h"
using namespace std;

// Transportes

class TransportDoesNotExist : public exception {
    Transport *transport;
public:
    TransportDoesNotExist(Transport *transport);
    Transport getTransport() const;
    void showError() const;
};

class TransportAlreadyExist : public exception {
    Transport *transport;
public:
    TransportAlreadyExist(Transport *transport);
    Transport getTransport() const;
    void showError() const;
};

// Datas

class InvalidDate : public exception {
    Date date;
public:
    InvalidDate(Date date);
    Date getInvalidDate() const;
    void showError() const;
};




#endif // PROJECT_AED_EXCEPTIONS_H
