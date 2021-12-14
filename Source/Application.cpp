#include "Company.h"
#include "Menu.h"

void simpleTest(Company &company) {

    Plane newPlane = Plane (to_string(company.getNextPlaneID()), "ABC-1234", "KDFMW", 89334, 234);
    Flight newFlight = Flight (newPlane.getID() + "-" + to_string(newPlane.getNextFlightID()), Date(2023, 12, 15, 9, 7), 180, "FEUP", Airport("Cristiano Ronaldo", "Madeira"));
    Passenger newPassenger1 = Passenger (newFlight.getID() + "-" + to_string(newFlight.getNextPassengerID()), "Novo Passageiro 1", 45, 'F', "KSOWMDMS233K");

    Volume v1 = {2, 3, 4};
    Luggage newLuggage1 = Luggage(newPassenger1.getID(), 34, v1, true);
    v1 = {34, 23, 5};
    Luggage newLuggage2 = Luggage(newPassenger1.getID(), 382, v1, false);

    newPassenger1.addLuggage(newLuggage1);
    newPassenger1.addLuggage(newLuggage2);

    newFlight.addPassenger(newPassenger1);

    newPlane.addFlight(newFlight);
    company.addPlane(newPlane);

    company.save(); // ao retornar, destroi a company
}

void Application() {

    Menu menu;
    menu.mainMenu();

    Company company = Company("AirED");
    company.presentation();

    cout << "Primeira inserção" << endl;
    simpleTest(company);

    cout << "Segunda inserção" << endl;
    simpleTest(company);

    cout << "Agora vai salvar" << endl;

    company.save();

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