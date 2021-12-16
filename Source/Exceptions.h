#ifndef PROJECT_AED_EXCEPTIONS_H
#define PROJECT_AED_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>
#include "Transport.h"
#include "Date.h"
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
         *
         */
        Transport *transport;
    public:
        InvalidTransport(Transport *transport);
        Transport getTransport() const;
        void showError() const;
};

/**
 * A class to manage invalid Dates
 */
class InvalidDate : public exception {
    Date date;
public:
    InvalidDate(Date date);
    Date getInvalidDate() const;
    void showError() const;
};




#endif // PROJECT_AED_EXCEPTIONS_H
