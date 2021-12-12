#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"

int mainMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Employee" << endl;
        cout << "2 - Passenger" << endl;
        cout << "3 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 3) cout << "Error, please try again!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (option < 1 || option > 3);

    return option;
}

int employeeMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listagem de coisas" << endl;
        cout << "2 - Adicionar coisas" << endl;
        cout << "3 - Remover coisas" << endl;
        cout << "4 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Error, please try again!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (option < 1 || option > 5);

    return option;
}

int passengerMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listagem de coisas" << endl;
        cout << "2 - Comprar bilhete" << endl;
        cout << "3 - Cancelar bilhete" << endl;
        cout << "4 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 4) cout << "Error, please try again!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (option < 1 || option > 4);

    return option;
}

#endif // PROJECT_AED_MENU_CPP

