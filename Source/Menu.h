#ifndef PROJECT_AED_MENU_H
#define PROJECT_AED_MENU_H

class Menu {
public:
    void mainMenu();
    // 1 - Employee Menu
    // 2 - Passenger Menu
    // 3 - Quit

    void employeeMenu();
    // 1 - Listagem dos aeroportos
    // 2 - Adicionar coisas
    // 3 - Remover coisas
    // 4 - Quit

    void passengerMenu();
    // 1 - Comprar bilhete
    // 2 - Quit

    void airportMenu();
    // 1. Get planes
    // 2. Quit

    void quit();
};

#endif //PROJECT_AED_MENU_H
