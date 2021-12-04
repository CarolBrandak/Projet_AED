#ifndef PROJECT_AED_SERVICE_H
#define PROJECT_AED_SERVICE_H

#include <string>
#include "Date.h"
#include "Employee.h"

class Service {

    private:

        /**
         * @var id - string type attribute that contains the service's id
         */
        string id;
        /**
         * @var serviceType - string type attribute that contains the type of service
         */
        string serviceType;
        /**
         * @var serviceDate - Date type attribute that contains the date of the service
         */
        Date serviceDate;
        /**
         * @var responsible - Employee type attribute that contains the information of the responsible for the service
         */
        Employee responsible;

    public:
        /**
         * Constructor that creates an service
         * @param id - a string, containing service's id
         * @param serviceType - a string, containing the service type
         * @param serviceDate - a Date type object containing the Date of the service
         * @param responsible - a Employee type object, containing the Employee responsible for the service
         */
        Service(string id, string serviceType, Date serviceDate, Employee responsible);

        /**
         * Returns Service's id
         * @return a string, containing service's id
         */
        string getID() const;

        /**
         * Returns the type of service
         * @return a string, containing the service type
         */
        string getServiceType() const;
        /**
         * Returns the date of the service
         * @return a Date object, containing the date of the service
         */
        Date getServiceDate() const;
        /**
         * Returns the responsible of the service
         * @return an Employee object, containing the employee responsible for the service
         */
        Employee getResponsible() const;
};

/**
 * @overload
 * Function that returns all characteristics of the Service being manipulated
 * @param ostream object, passed by reference
 * @param service object, passed by reference
 * @return ostream object
 */
ostream & operator << (ostream & os, const Service &service);

#endif // PROJECT_AED_SERVICE_H