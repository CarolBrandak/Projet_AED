#ifndef PROJECT_AED_EXCEPTIONS_H
#define PROJECT_AED_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>
#include "Service.h"
#include "Transport.h"
#include "Date.h"
#include "Passenger.h"
#include "Employee.h"
#include "Luggage.h"
using namespace std;

/**
 * A class to manage missing files
 */
class FileNotFound : public exception {

    private:

        /**
         * @var directory - a string containing the missing directory
         */
        string directory;

    public:

        /**
         * A main constructor of the class
         * @param directory - a string containing the missing directory
         */
        FileNotFound(const string &directory);

        /**
         * A function that gets the current missing directory
         * @return a string that contains the directory
         */
        string getDirectory() const;

        /**
         * A void function that shows more details about the exception
         */
        void showError() const;
};

/**
 * A class to manage missing transports
 */
class TransportDoesNotExist : public exception {

    private:

        /**
         * @var transport - a Transport object that not exist in current Flight
         */
        Transport *transport;

    public:

        /**
         * Constructor of class
         * @param transport - a Transport object that not exist in current Flight
         */
        TransportDoesNotExist(Transport *transport);

        /**
         * Gets the Transport that not exists in current files
         * @return a Transport object
         */
        Transport getTransport() const;

        /**
         * A void function that shows more details about the exception
         */
        void showError() const;
};

/**
 * A class to manage repeated transports
 */
class TransportAlreadyExist : public exception {

    private:

        /**
         * @var transport - a Transport object that already exists in current Airport's Flight
         */
        Transport *transport;

    public:

        /**
         * Constructor of class
         * @param transport - a Transport object that already exists in current Flight
         */
        TransportAlreadyExist(Transport *transport);

        /**
         * Gets the Transport that already exists in current files
         * @return a Transport object
         */
        Transport getTransport() const;

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Transports
 */
class InvalidTransport : public exception {

    private:

        /**
         * @var transport - a Transport object that is invalid in current Flight
         */
        Transport *transport;

    public:

        /**
         * Constructor of class
         * @param transport - a Transport object is invalid
         */
        InvalidTransport(Transport *transport);

        /**
         * Gets the invalid Transport
         * @return a Transport object
         */
        Transport getTransport() const;

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Dates
 */
class InvalidDate : public exception {

    private:

        /**
         * @var date - an invalid Date object
         */
        Date date;

    public:

        /**
         * Constructor of the class
         * @param date - an invalid Date object
         */
        InvalidDate(Date date);

        /**
         * Gets the invalid Date
         * @return a Date object
         */
        Date getInvalidDate() const;

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Employees
 */
class InvalidEmployee : public exception {

    private:

        /**
         * @var employee - an invalid employee object
         */
        Employee employee;

    public:

        /**
         * Constructor of the class
         * @param employee - an invalid employee object
         */
        InvalidEmployee(Employee employee);

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Luggage
 */
class InvalidLuggage : public exception {

    private:

        /**
         * @var luggage - an invalid Luggage object
         */
        Luggage *luggage;

    public:

        /**
         * Class constructor
         * @param luggage - an invalid Luggage object
         */
        InvalidLuggage(Luggage *luggage);

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Passengers
 */
class InvalidPassenger : public exception {

    private:

        /**
         * @var passenger - an invalid Passenger object
         */
        Passenger *passenger;

    public:

        /**
         * Class constructor
         * @param passenger - an invalid passenger object
         */
        InvalidPassenger(Passenger *passenger);

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

/**
 * A class to manage invalid Services
 */
class InvalidService : public exception {

    private:

        /**
         * @var service - an invalid Service object
         */
        Service *service;

    public:

        /**
         * Class constructor
         * @param service - an invalid Service object
         */
        InvalidService(Service *service);

        /**
        * A void function that shows more details about the exception
        */
        void showError() const;
};

#endif // PROJECT_AED_EXCEPTIONS_H