#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

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
        const short int MAIN_MENU = 0;
        const short int COMPANY_MENU = 1;
        const short int PASSENGER_MENU = 2;

        // CompanyMenu
        void planeDataMenu();
        void flightDataMenu();
        void passengerDataMenu();
        void luggageDataMenu();
        void employeeDataMenu();
        void transportDataMenu();
        const short int PLANE_DATA_MENU = 3;
        const short int FLIGHT_DATA_MENU = 4;
        const short int PASSENGER_DATA_MENU = 5;
        const short int LUGGAGE_DATA_MENU = 6;
        const short int EMPLOYEE_DATA_MENU = 7;
        const short int TRANSPORT_DATA_MENU = 8;


        // PassengerMenu
        void buyTicket();
        const short int BUY_TICKET_MENU = 9;
        void cancelTicket();
        const short int CANCEL_TICKET_MENU = 10;

        // Listagens
        void listPlanes();
        void listFlights();
        void listPassengers();
        void listLuggages();
        void listServices();
        void listEmployees();
        void listTransports();

        // Inputs
        // Empty... for now
        /**
         * Funções que vão servir essencialmente para limpar o código de repetições
         * Em vez de estar sempre a pedir para dar um voo (destino, origem)
         * ter um método que faz isso. Pensar e debater sobre isto.
         * Por exemplo o "passengerDataMenu" tem muita repetição, isto aliviava
         */


    public:
        Menu();
        void mainMenu();
};

#endif //PROJECT_AED_MENU_H
