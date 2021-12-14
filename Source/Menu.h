#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <iostream>
#include "Company.h"
class Menu {

private:
    Company *company;
    void companyMenu();
    void passengerMenu();
    void employeeDataMenu();
    void passengerDataMenu();
    void servicesDataMenu();
    void flightsDateMenu();

public:
    Menu();
    void mainMenu();
    void simpleTest();
    void showPlanes();
};
#endif //PROJECT_AED_MENU_H
