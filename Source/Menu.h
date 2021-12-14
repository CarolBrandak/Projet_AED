#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

#include <iostream>
#include "Company.h"
class Menu {

private:
    Company company;
    void companyMenu();
    // 1 - Listagem dos aeroportos
    // 2 - Adicionar coisas
    // 3 - Remover coisas
    // 4 - Quit

    void passengerMenu();
    // 1 - Comprar bilhete
    // 2 - Quit

    void employeeDataMenu();

    void passengerDataMenu();

    void servicesDataMenu();

    void flightsDataMenu();

public:
    Menu();
    Menu(Company company);
    void mainMenu();
    void simpleTest();
    // 1 - Employee Menu
    // 2 - Passenger Menu
    // 3 - Quit
};
#endif //PROJECT_AED_MENU_H
