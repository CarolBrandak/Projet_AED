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

        // CompanyMenu
        void planeDataMenu();
        void flightDataMenu();
        void passengerDataMenu();
        void luggageDataMenu();
        void employeeDataMenu();
        void transportDataMenu();

        // PassengerMenu


        // Listagens
        void listPlanes();
        void listFlights();
        void listPassengers();
        void listLuggages();
        void listServices();
        void listTransports();


    public:
        Menu();
        void mainMenu();
};

#endif //PROJECT_AED_MENU_H
