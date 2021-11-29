#ifndef PROJET_AED_SERVICE_CPP
#define PROJET_AED_SERVICE_CPP

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

ostream & operator << (ostream & os, const Service &service) {
    os << "Type: " << service.getServiceType() <<
        "\nDate: " << service.getServiceDate() <<
        "\nResponsible: " << service.getResponsible() << std::endl;
    return os;
}

#endif //PROJET_AED_SERVICE_CPP