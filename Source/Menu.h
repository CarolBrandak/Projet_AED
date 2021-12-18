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

        void allLists();
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

        // Listagens

        void listPlanes();
        void listFlights();
        void listPassengers();
        void listLuggages();
        void listServices();
        void listEmployees();
        void listTransports();

        // Inputs
        Plane fillPlaneData(const string &id);
        Flight fillFlightData(const string &id);
        Passenger fillPassengerData(const string &id);
        Luggage fillLuggageData(const string &id);
        Employee fillEmployeeData();
        Transport fillTransportData(const string &id);

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