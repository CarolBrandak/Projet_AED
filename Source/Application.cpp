#include "Company.h"
#include "Menu.h"

void Application() {

    Company company = Company("AirED");
    company.presentation();

    Plane newPlane = Plane (to_string(company.getNextPlaneID()), "ABC-1234", "KDFMW", 89334, 234);
    company.addPlane(newPlane);

    for (Plane *plane : company.getAllPlanes()) {
        cout << *plane;
    }

    company.save();

    /**
    int choice = mainMenu();
    switch (choice) {
        case 1:
            choice = employeeMenu();
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