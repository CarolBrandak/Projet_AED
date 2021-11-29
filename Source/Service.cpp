#ifndef PROJECT_AED_SERVICE_CPP
#define PROJECT_AED_SERVICE_CPP

#include "Service.h"

Service::Service(string serviceType, Date serviceDate, Employee responsible) :
    serviceType(serviceType),
    serviceDate(serviceDate),
    responsible(responsible) {}

std::string Service::getServiceType() const {
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
        "\nResponsible: " << service.getResponsible() << std::endl;
    return os;
}

#endif // PROJECT_AED_SERVICE_CPP