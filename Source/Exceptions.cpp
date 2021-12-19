#ifndef PROJECT_AED_EXCEPTIONS_CPP
#define PROJECT_AED_EXCEPTIONS_CPP

#include "Exceptions.h"

FileNotFound::FileNotFound(const string &directory) {
    this->directory = directory;
}

string FileNotFound::getDirectory() const {
    return this->directory;
}

void FileNotFound::showError() const {
    cerr << "O ficheiro " << directory << " nao foi encontrado" << endl;
}

TransportAlreadyExist::TransportAlreadyExist (Transport *transport) {
    this->transport = transport;
}

Transport TransportAlreadyExist::getTransport() const {
    return *transport;
}

void TransportAlreadyExist::showError() const {
    cerr << "O transporte " << this->transport << " ja existe no aeroporto" << endl;
}

TransportDoesNotExist::TransportDoesNotExist(Transport *transport) {
    this->transport = transport;
}

Transport TransportDoesNotExist::getTransport() const {
    return *transport;
}

void TransportDoesNotExist::showError() const {
    cerr << "O transporte " << *transport << " nao existe no aeroporto" << endl;
}

InvalidTransport::InvalidTransport(Transport *transport) {
    this->transport = transport;
}

Transport InvalidTransport::getTransport() const {
    return *transport;
}

void InvalidTransport::showError() const {
    cerr << "O transporte " << *transport << " tem formato invalido" << endl;
}

InvalidDate::InvalidDate(Date date) {
    this->date = date;
}

Date InvalidDate::getInvalidDate() const {
    return this->date;
}

void InvalidDate::showError() const {
    cerr << "A data " << date << " tem formato invalido" << endl;
}

InvalidEmployee::InvalidEmployee(Employee employee) : employee(employee) {}

void InvalidEmployee::showError() const {
    cerr << "O funcionario " << employee << " tem formato invalido" << endl;
}

InvalidLuggage::InvalidLuggage(Luggage *luggage) {
    this->luggage = luggage;
}

void InvalidLuggage::showError() const {
    cerr << "A bagagem " << luggage << " tem formato invalido" << endl;
}

InvalidPassenger::InvalidPassenger(Passenger *passenger) {
    this->passenger = passenger;
}

void InvalidPassenger::showError() const {
    cerr << "O passageiro " << passenger << " tem formato invalido" << endl;
}

InvalidService::InvalidService(Service *service) {
    this->service = service;
}

void InvalidService::showError() const {
    cerr << "O servico " << service << " tem formato invalido" << endl;
}

#endif // PROJECT_AED_EXCEPTIONS_CPP