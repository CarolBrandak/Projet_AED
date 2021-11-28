//
// Created by gabrieltmjr on 11/28/2021.
//

#ifndef PROJET_AED_SERVICE_H
#define PROJET_AED_SERVICE_H

#include "Date.h"
#include "Employee.h"

class Service {
protected:
    /**
     * @var serviceDate - Date type attribute that holds the date of the service
     */
    const Date serviceDate;
    /**
     * @var responsible - Employee type attribute that holds the information of the responsible for the service
     */
    const Employee responsible;
public:
    /**
     * Returns the date of the service
     * @return a Date object, containing the date of the service
     */
    virtual Date getServiceDate() = 0;
    /**
     * Returns the responsible of the service
     * @return an Employee object, containing the employee responsible for the service
     */
    virtual Employee getResponsible() = 0;
};

#endif //PROJET_AED_SERVICE_H
