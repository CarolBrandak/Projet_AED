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

#include "Company.h"

class Menu {

    private:
        // na company sempre que é modificada, dar company->save();
        Company *company;

        std::stack<short int> menuState;

        //Menu Caller
        void getMenu();

        // Principais
        void companyMenu();
        void passengerMenu();
        void allLists();


        // CompanyMenu
        void planeDataMenu();
        void flightDataMenu();
        void passengerDataMenu();
        void luggageDataMenu();
        void employeeDataMenu();
        void transportDataMenu();


        // PassengerMenu
        void buyTicket();
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
        Passenger fillPassengerData();

    public:
        Menu();
        void mainMenu();
};

#endif // PROJECT_AED_MENU_H
