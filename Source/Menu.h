#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#define MAIN_MENU 0
#define COMPANY_MENU 1
#define PASSENGER_MENU 2
#define PLANE_DATA_MENU 3
#define FLIGHT_DATA_MENU 4
#define PASSENGER_DATA_MENU 5
#define LUGGAGE_DATA_MENU 6
#define EMPLOYEE_DATA_MENU 7
#define TRANSPORT_DATA_MENU 8
#define BUY_TICKET_MENU 9
#define CANCEL_TICKET_MENU 10

#include <algorithm>
#include "Utilities.h"
#include "Company.h"

class Menu {

    private:

        /**
         * @var company - object used to manage the an company´s operations and data
         * */
        Company *company;

        /**
         * @var menuState - stack used to navigate through the menu
         * */
        std::stack<short int> menuState;

        /**
         * Function that calls the top of the menuState stack
         * */
        void getMenu();

        /**
         * Menu for the company manager
         * */
        void companyMenu();

        /**
         * Menu for the passenger
         * */
        void passengerMenu();

        /**
         * Menu for all lists
         */
        void allLists();

        /**
         * A function that return if user wants partial or total list of objects
         * @return a char, containing the answer
         */
        char totalOrPartial();

        /**
         * Menu for managing planes
         * */
        void planeDataMenu();

        /**
         * Menu for managing flights
         * */
        void flightDataMenu();

        /**
         * Menu for managing passengers
         * */
        void passengerDataMenu();

        /**
         * Menu for managing luggages
         * */
        void luggageDataMenu();

        /**
         * Menu for managing employees
         * */
        void employeeDataMenu();

        /**
         * Menu for managing transports
         * */
        void transportDataMenu();

        /**
         * function that allows the passenger to buy a ticket
         * by asking all the data necessary to make a purchase
         * */
        void buyTicket();

        /**
         * function that allows the passenger to cancel
         * a ticket by the inputing the data related to
         * the ticket
         * */
        void cancelTicket();

        /**
         * Menu to list all Planes of the system
         */
        void listPlanes();

        /**
        * Menu to list all Flights of the system
        */
        void listFlights();

        /**
        * Menu to list all Passengers of the system
        */
        void listPassengers();

        /**
        * Menu to list all Luggages of the system
        */
        void listLuggages();

        /**
        * Menu to list all Services of the system
        */
        void listServices();

        /**
        * Menu to list all Employees of the system
        */
        void listEmployees();

        /**
        * Menu to list all Transports of the system
        */
        void listTransports();

        /**
         * Function used to receive as input the data necessary
         * to create a Plane type object.
         * @param id - a string containing the id of plane according to its order
         * @return Plane type object filled with data
         */
        Plane fillPlaneData(const string &id);

        /**
         * Function used to receive as input the data necessary
         * to create a Flight type object.
         * @param id - the id to be applied to the flight according to its plane and order
         * @return Flight type object filled with data
         */
        Flight fillFlightData(const string &id);

        /**
         * Function used to receive as input the data necessary
         * to create a Passenger type object.
         * @param id - the id to be applied to the passenger according to its order in the flight
         * @return Passenger type object filled with data
         */
        Passenger fillPassengerData(const string &id);

        /**
         * Function used to receive as input the data necessary
         * to create a Luggage type object.
         * @param id - the id to be applied to the luggage according to its owner (the passenger)
         * @return Luggage type object filled with data
         */
        Luggage fillLuggageData(const string &id);

        /**
         * Function used to receive as input the data necessary
         * to create an Employee type object.
         * @return Employee type object filled with data
         */
        Employee fillEmployeeData();

        /**
         * Function used to receive as input the data necessary
         * to create a Transport type object.
         * @param id - the id to be applied to the transport according to its flight
         * @return Transport type object filled with data
         */
        Transport fillTransportData(const string &id);

        /**
         * Function used to receive as input the data necessary
         * to create a Date type object.
         * @return Date type object filled with data
         */
        Date fillDateData();

    public:

        /**
         * Construtor para a classe menu
         * */
        Menu();

        /**
         * Main menu that allows the user to choose
         * between the passenger menu or the company
         * manager menu
         * */
        void mainMenu();
};

#endif // PROJECT_AED_MENU_H