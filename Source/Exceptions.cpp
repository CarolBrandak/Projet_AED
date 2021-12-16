#ifndef PROJECT_AED_EXCEPTIONS_CPP
#define PROJECT_AED_EXCEPTIONS_CPP

#include "Exceptions.h"

// Files

FileNotFound::FileNotFound(const string &directory) {
    this->directory = directory;
}

string FileNotFound::getDirectory() const {
    return this->directory;
}

void FileNotFound::showError() const {
    cerr << "File " << directory << " not found" << endl;
}

// Transportes

TransportAlreadyExist::TransportAlreadyExist (Transport *transport) {
    this->transport = transport;
}

Transport TransportAlreadyExist::getTransport() const {
    return *transport;
}

void TransportAlreadyExist::showError() const {
    cerr << "O transporte " << this->transport << " já existe no aeroporto" << endl;
}

TransportDoesNotExist::TransportDoesNotExist(Transport *transport) {
    this->transport = transport;
}

Transport TransportDoesNotExist::getTransport() const {
    return *transport;
}

void TransportDoesNotExist::showError() const {
    cerr << "O transporte " << this->transport << " não existe no aeroporto" << endl;
}

// Datas

InvalidDate::InvalidDate(Date date) {
    this->date = date;
}

Date InvalidDate::getInvalidDate() const {
    return this->date;
}

void InvalidDate::showError() const {
    cerr << "A data " << date << " é inválida" << endl;
}




#endif // PROJECT_AED_EXCEPTIONS_CPP