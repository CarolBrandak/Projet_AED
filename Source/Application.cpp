#include "Company.h"
#include "Menu.h"

void Application() {


    Company company = Company("AirED");
    company.presentation();
    Menu menu(company);
    menu.mainMenu();




    /**
    int choice = mainMenu();
    switch (choice) {
        case 1:
            choice = companyMenu();
            break;
        case 2:
            choice = passengerMenu();
            break;
        default:
            return;
    }

    switch (choice) {
        case 1:
            // parte das listagens
            company.listing();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            return;
    }
     */

}