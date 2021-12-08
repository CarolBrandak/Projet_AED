#ifndef PROJECT_AED_SERVICE_CPP
#define PROJECT_AED_SERVICE_CPP

#include "Service.h"

Service::Service() {}

Service::Service(string id, string serviceType, Date serviceDate, Employee responsible) :
    id(id),
    serviceType(serviceType),
    serviceDate(serviceDate) {
    this->responsible = responsible;
}

Service::~Service() {}

string Service::getID() const {
    return id;
}

string Service::getServiceType() const {
    return serviceType;
}

Employee Service::getResponsible() const {
    return responsible;
}

Date Service::getServiceDate() const {
    return serviceDate;
}

void Service::setResponsible(const Employee &employee) {
    this->responsible = employee;
}

ostream & operator << (ostream & os, const Service &service) {
    os << "Type: " << service.getServiceType() <<
        "\nDate: " << service.getServiceDate() <<
        "Responsible: " << service.getResponsible();
    return os;
}

#endif // PROJECT_AED_SERVICE_CPP