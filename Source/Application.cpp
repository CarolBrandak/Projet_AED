#include "Company.h"

void Application() {

    Company company = Company("AirED");
    cout << "Welcome to " << company.getName() << " Company!" << endl;
    char op;

    do {
        string origin, destination;
        cout << "Origin: " << endl; origin = "Porto"; //cin >> origin;
        cout << "Destination: " << endl; destination = "Galiza" ; //cin >> destination;
        Flight* wanted = company.findFlight(origin, destination);

        if (wanted != nullptr) {

            cout << "\nShow flight information: " << endl << endl;
            cout << *wanted << endl;

            // TODO - perguntar os dados do passageiro
            string newID = wanted->getID() + "-" + to_string(wanted->getNextPassengerID());     // repare-se que o ID atribuido ao passageiro
                                                                                                // e às bagagens é automático
            Passenger* me = new Passenger(newID, "Jorge Santos", 23, 'M', "LJSNFW82");

            // TODO - perguntar os dados das bagagens e inserir no passageiro

            // No final:
            wanted->addPassenger(*me);

        } else {
            cout << "Not found :(" << endl;
        }
        cout << "Continue? S/N: " << endl;  op = 'n'; //cin >> op;

    } while (toupper(op) != 'N');

    // Curiosamente escreve duas vezes o passageiro Jorge Santos. Algo a investigar.
    company.saveData("../Source/Files/");

}