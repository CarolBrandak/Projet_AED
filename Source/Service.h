#ifndef PROJECT_AED_SERVICE_H
#define PROJECT_AED_SERVICE_H

#include <string>
#include "Date.h"
#include "Employee.h"

class Service {

    private:

        /**
         * @var ID - a constant string type attribute that contains the service's id
         */
        const string ID;
        /**
         * @var TYPE - a constant string type attribute that contains the type of service
         */
        const string TYPE;
        /**
         * @var DATE - a constant Date object that contains the date of the service
         */
        const Date DATE;
        /**
         * @var responsible - Employee type attribute that contains the information of the responsible for the service
         */
        Employee* responsible;

    public:

        /**
         * A default constructor
         */
        Service();

        /**
         * A default destructor
         */
        ~Service();

        /**
         * Constructor that creates an service
         * @param id - a string, containing service's id
         * @param type - a string, containing the service type
         * @param date - a Date type object containing the Date of the service
         * @param responsible - a Employee type object, containing the Employee responsible for the service
         */
        Service(string id, string type, Date date, Employee* responsible);

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
        Employee* getResponsible() const;

        /**
         * Sets the responsible of the service
         * @param employee an Employee object, containing the new employee responsible for the service
         */
        void setResponsible(Employee &employee);

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param service another object that will be compared
         * @return if the current object is the same object passed by reference
         */
        bool operator == (const Service &service) const;

        /**
         * @overload
         * Boolean function that compares two objects of this class
         * @param service another object that will be compared
         * @return if the current object is less than the object passed by reference
         */
        bool operator < (const Service &service) const;

        /**
        * @overload
        * Function that returns all characteristics of the Service being manipulated
        * @param ostream object, passed by reference
        * @param service object, passed by reference
        * @return ostream object
        */
        friend ostream & operator << (ostream & os, const Service &service);
};

#endif // PROJECT_AED_SERVICE_H