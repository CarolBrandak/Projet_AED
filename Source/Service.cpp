#ifndef PROJECT_AED_SERVICE_CPP
#define PROJECT_AED_SERVICE_CPP

#include "Service.h"

Service::Service() : ID(""), TYPE(""), DATE(0, 0) {}

Service::~Service() {}

Service::Service(string id, string serviceType, Date serviceDate, Employee responsible) :
    responsible(responsible),
    ID(id),
    TYPE(serviceType),
    DATE(serviceDate) {
}

string Service::getID() const {
    return ID;
}

string Service::getServiceType() const {
    return TYPE;
}

Employee Service::getResponsible() const {
    return responsible;
}

Date Service::getServiceDate() const {
    return DATE;
}

void Service::setResponsible(const Employee &employee) {
    this->responsible = employee;
}

bool Service::operator == (const Service &service) const {
    return ID == service.ID && TYPE == service.TYPE && DATE == service.DATE &&
            responsible == service.responsible;
}

bool Service::operator < (const Service &service) const {
    if (DATE == service.DATE) {
        return TYPE < service.TYPE;
    } return DATE < service.DATE;
}

ostream & operator << (ostream & os, const Service &service) {
    os << "Type: " << service.TYPE <<
        "\nDate: " << service.DATE <<
        "Responsible: " << service.responsible;
    return os;
}

#endif // PROJECT_AED_SERVICE_CPP