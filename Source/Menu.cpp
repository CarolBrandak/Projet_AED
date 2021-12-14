#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"

void Menu::mainMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Menu gestor da companhia" << endl;
        cout << "2 - Menu passageiro" << endl;
        cout << "3 - Sair" << endl;
        cout << "A sua escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        switch(option) {
            case 1: companyMenu(); break;
            case 2: passengerMenu(); break;
            case 3: exit(0);
            default: break;
        }
    } while (option < 1 || option > 3);

}

void Menu::companyMenu() {
    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Menu dos Vôos" << endl;
        cout << "2 - Menu dos Passageiros" << endl;
        cout << "3 - Menu dos Funcionários" << endl;
        cout << "4 - Listagem de Transportes" << endl;
        cout << "5 - Voltar para o menu principal" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        switch (option) {
            case 1: flightsDataMenu();
            case 2: passengerDataMenu();
            case 3: employeeDataMenu();
            case 4: company.getAllTransports();
            case 5: mainMenu();
            default: break;
        }
    } while (option < 1 || option > 5);
}

void Menu::flightsDataMenu() {
    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listagem de Voos" << endl;
        cout << "2 - Adicionar Voo(s)" << endl;
        cout << "3 - Remover Voo(s)" << endl;
        cout << "4 - Procurar Voo" << endl;
        cout << "5 - Voltar para o menu da companhia" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        switch(option) {
            case 1: company.getAllFlights(); break;
            case 2: break;
            case 3: break;
            case 4: {
                std::string origin,destination;
                cout << "Por favor introduza o país de origem" << endl;
                cin >> origin;
                cout << "Por favor introduza o país de destino" << endl;
                cin >> destination;
                Flight* flight = company.findFlight(origin,destination);
                cout << flight;
            }
            case 5: companyMenu();
            default: break;
        }
    } while (option < 1 || option > 5);
}

void Menu::passengerDataMenu() {
    int option;
    std::string origin,destination;
    string id,name,passportNumber;
    short int age;
    char gender;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listagem de Passageiros" << endl;
        cout << "2 - Listagem de Passageiros de um voo" << endl;
        cout << "3 - Adicionar Passageiro(s) a um voo" << endl;
        cout << "4 - Procurar Passageiro" << endl;
        cout << "5 - Remover Passageiros" << endl;
        cout << "6 - Voltar para o menu da companhia" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 6) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        switch(option) {
            case 1: company.getAllPassengers(); break;
            case 2: {
                cout << "Por favor introduza o país de origem" << endl;
                cin >> origin;
                cout << "Por favor introduza o país de destino" << endl;
                cin >> destination;
                Flight* flight = company.findFlight(origin,destination);
                flight->checkPassengers();
            }break;
            case 3: {
                cout << "Por favor introduza o país de origem" << endl;
                cin >> origin;
                cout << "Por favor introduza o país de destino" << endl;
                cin >> destination;
                Flight* flight = company.findFlight(origin,destination);
                cout << "Enter the passenger's ID" << endl;
                cin >> id;
                cout << "Enter the passenger's name" << endl;
                cin >> name;
                cout << "Enter the passenger's age" << endl;
                cin >> age;
                cout << "Enter the passenger's gender (M ou F)" << endl;
                cin >> gender;
                cout << "Introduza o número do passaporte do passageiro" << endl;
                cin >> passportNumber;
                Passenger passenger(id,name,age,gender,passportNumber);
                flight->addPassenger(passenger);
            }break;
            case 4: break;
            case 5: {
                cout << "Por favor introduza o país de origem" << endl;
                cin >> origin;
                cout << "Por favor introduza o país de destino" << endl;
                cin >> destination;
                Flight *flight = company.findFlight(origin, destination);
                cout << "Enter the passenger's ID" << endl;
                cin >> id;
                cout << "Enter the passenger's name" << endl;
                cin >> name;
                cout << "Enter the passenger's age" << endl;
                cin >> age;
                cout << "Enter the passenger's gender (M ou F)" << endl;
                cin >> gender;
                cout << "Introduza o número do passaporte do passageiro" << endl;
                cin >> passportNumber;
                Passenger passenger(id, name, age, gender, passportNumber);
                flight->removePassenger(passenger);
            }break;
            case 6: companyMenu(); break;
            default: break;
        }
    } while (option < 1 || option > 6);
}

void Menu::employeeDataMenu() {
    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listagem de Trabalhadores" << endl;
        cout << "2 - Listagem de Serviços" << endl;
        cout << "3 - Adicionar Trabalhador" << endl;
        cout << "4 - Adicionar Serviço" << endl;
        cout << "5 - Remover Trabalhador" << endl;
        cout << "6 - Remover Serviço" << endl;
        cout << "7 - Procurar Trabalhador" << endl;
        cout << "8 - Procurar Serviço" << endl;
        cout << "9 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        switch(option) {
            case 1: company.getAllPassengers(); break;
            case 2: company.getAllServices(); break;
            case 3: {
                //company.addWorker()
            } break;
            case 4: {
                //flight.addService()
            } break;
            case 5: {
                //company.removeWorker()
            } break;
            case 6: {
                //flight.removeService()
            } break;
            case 7: {
                //company.findWorker()
            } break;
            case 8: {
                //flight.findService()
            } break;
            case 9: companyMenu(); break;
            default: break;
        }
    } while (option < 1 || option > 9);
}

void Menu::passengerMenu() {
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
        if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (option < 1 || option > 4);
}

#endif // PROJECT_AED_MENU_CPP

