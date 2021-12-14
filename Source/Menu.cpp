#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"

Menu::Menu() {
    this->company = new Company("AirED");
    company->presentation();
    mainMenu();
}

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

    } while (option < 1 || option > 3);

    switch (option) {
        case 1: companyMenu(); break;
        //case 2: passengerMenu(); break;
        case 3: exit(0);
    }
}

void Menu::companyMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Planes" << endl;
        cout << "2 - Voos" << endl;
        cout << "3 - Passageiros" << endl;
        cout << "4 - Bagagem" << endl;
        cout << "5 - Transportes" << endl;
        cout << "6 - Funcionarios / Serviços" << endl;
        cout << "7 - Voltar para o menu principal" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 7) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 7);

    switch (option) {
        case 1: planeDataMenu(); break;
        case 2: flightDataMenu(); break;
        case 3: passengerDataMenu(); break;
        case 4: luggageDataMenu(); break;
        case 5: employeeDataMenu(); break;
        case 6: transportDataMenu(); break;
        case 7: mainMenu(); break;
    }
}

void Menu::planeDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar planes" << endl;
        cout << "2 - Remover planes" << endl;
        cout << "3 - Listar planes" << endl;
        cout << "4 - Voltar para trás" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 4) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 4);

    switch (option) {
        case 1: { // E sim, em casos em que se declara variáveis temos de colocar o case com chavetas :(

            // Adiciona um plane --> Perguntar e meter inputs
            Plane newPlane = Plane(to_string(company->getNextPlaneID()), "mkmokim", "kmokmo", 98237, 23);
            company->addPlane(newPlane);
            company->save();

            cout << "Adicionou o aviao " << newPlane << " com sucesso ou algo do tipo" << endl; // mensagem só para teste
            planeDataMenu();
            break;
        }

        case 2:

            // Remove um plane --> fazer método para a Company, depois coloco-o aqui
            cout << "Supostamente removeu o aviao tal" << endl;
            planeDataMenu();
            break;

        case 3: /**listPlanes()*/ break;
        case 4: companyMenu(); break;
    }
}

void Menu::flightDataMenu() {

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

void Menu::luggageDataMenu() {

    cout << "Something" << endl;
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

void Menu::listPlanes() {
    cout << "List Planes" << endl;
}

/**
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
*/

#endif // PROJECT_AED_MENU_CPP

