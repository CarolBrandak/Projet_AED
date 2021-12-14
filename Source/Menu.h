#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include "Company.h"

class Menu {

    private:

        // na company sempre que é modificada, dar company->save();
        Company *company;

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
