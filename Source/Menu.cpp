#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"

Menu::Menu() {
    this->company = new Company("AirED");
    company->presentation();
    menuState.push(MAIN_MENU);
    getMenu();
}

void Menu::getMenu() {
    switch(menuState.top()) {
        case 0: mainMenu(); break;
        case 1: companyMenu(); break;
        case 2: passengerMenu(); break;
        case 3: planeDataMenu(); break;
        case 4: flightDataMenu(); break;
        case 5: passengerDataMenu(); break;
        case 6: luggageDataMenu(); break;
        case 7: employeeDataMenu(); break;
        case 8: transportDataMenu(); break;
        case 9: buyTicket(); break;
        case 10: cancelTicket(); break;
    }
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
        case 1: {
            menuState.push(COMPANY_MENU);
        } break;
        case 2: menuState.push(PASSENGER_MENU); break;
        case 3:exit(0); break;
    }
    getMenu();
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
        case 1: menuState.push(PLANE_DATA_MENU); break;
        case 2: menuState.push(FLIGHT_DATA_MENU); break;
        case 3: menuState.push(PASSENGER_DATA_MENU); break;
        case 4: menuState.push(LUGGAGE_DATA_MENU); break;
        case 5: menuState.push(TRANSPORT_DATA_MENU); break;
        case 6: menuState.push(EMPLOYEE_DATA_MENU); break;
        case 7: menuState.pop(); break;
    }

    getMenu();
}

void Menu::planeDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar plane" << endl;
        cout << "2 - Remover plane" << endl;
        cout << "3 - Listar plane" << endl;
        cout << "4 - Procurar plane" << endl;
        cout << "5 - Voltar para trás" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch (option) {
        case 1: { // E sim, em casos em que se declara variáveis temos de colocar o case com chavetas :(

            // Adiciona um plane --> Perguntar e meter inputs
            Plane newPlane = Plane(to_string(company->getNextPlaneID()), "mkmokim", "kmokmo", 98237, 23);
            company->addPlane(newPlane);
            company->save();

            cout << "Adicionou o aviao " << newPlane << " com sucesso ou algo do tipo" << endl; // mensagem só para teste
            getMenu();
            break;
        }
        case 2: {
            // Remove um plane --> fazer método para a Company, depois coloco-o aqui
            cout << "Supostamente removeu o aviao tal ou n" << endl;
            getMenu();
            break;
        }
        case 3: listPlanes(); break;
        case 4: {
            // Procurar e fazer cout de toda a informação do avião.
            // A company terá uma função para fazer isso. Retornará NULL se não encontrar nada, ou retornará um avião. Depois coloco aqui.
            // if (found) mostra, else mensagem de erro
            getMenu();
        }
        case 5: menuState.pop(); getMenu(); break;
    }
}

void Menu::flightDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar voo" << endl;
        cout << "2 - Remover voo" << endl;
        cout << "3 - Listar voos" << endl;
        cout << "4 - Procurar voo" << endl;
        cout << "5 - Voltar para trás" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch(option) {
        case 1: {

            // 1ª passo -> em que Plane é que vai ser colocado o novo voo: inputs e depois:
            // Plane *plane = company->findPlane(id)
            // if (plane) // se o avião existir, então inputs para a construção do voo
            // else cout << Não há esse plane;

            break;
        }
        case 2: {

            // inputs do voo, por exemplo por id
            // se existir, remove

            break;
        }
        case 3: listFlights(); break;

        case 4: {
            std::string origin,destination;
            cout << "Por favor introduza o país de origem: ";
            cin >> origin;
            cout << "Por favor introduza o país de destino: ";
            cin >> destination;
            Flight* flight = company->findFlight(origin,destination); // não esquecer que isto retorna null se não encontrar
            if (flight) cout << *flight;                                 // verificação se é null
            else cout << "Não encontrado ou alguma mensagem assim" << endl;
            getMenu();
            break;
        }
        case 5: menuState.pop(); getMenu(); break;
    }
}

void Menu::passengerDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar Passageiro" << endl;
        cout << "2 - Remover Passageiro" << endl;
        cout << "3 - Listar Passageiros" << endl;
        cout << "4 - Procurar passageiro" << endl;
        cout << "5 - Voltar para trás" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch(option) {
        case 1: {

            // Procurar o voo onde inserir o passageiro (inicio, destino)
            // se existir, criar o passageiro com inputs e colocar
            // else mensagem de erro

            cout << "Por favor introduza o país de origem" << endl;
            cin >> origin;
            cout << "Por favor introduza o país de destino" << endl;
            cin >> destination;
            Flight* flight = company->findFlight(origin,destination);
            if (flight) {
                cout << "Enter the passenger's ID" << endl;                 // o id do passageiro é automático, basta chamar flight->getNextID ou algo do tipo
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
            } else cout << "Mensagem de erro a dizer que o voo procurado não existe" << endl;
            getMenu();
            break;
        }
        case 2: {
            cout << "Por favor introduza o país de origem" << endl;
            cin >> origin;
            cout << "Por favor introduza o país de destino" << endl;
            cin >> destination;
            Flight* flight = company->findFlight(origin,destination);
            if (flight) {
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
                // primeiro procurar e se depois existir, remover, senão mensagem de erro
                flight->removePassenger(passenger);
            } else cout << "Mensagem de erro a dizer que esse voo não existe" << endl;
            getMenu();
            break;
        }
        case 3: listPassengers(); break;
        case 4: {
            cout << "Por favor introduza o país de origem" << endl;
            cin >> origin;
            cout << "Por favor introduza o país de destino" << endl;
            cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            // se existir, ok, senão mensagem a dizer que não existe.
            getMenu();
            break;
        }
        case 6: menuState.pop(); getMenu(); break;
    }
}

void Menu::luggageDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar Luggage" << endl;
        cout << "2 - Remover Bagagem" << endl;
        cout << "3 - Listar Bagagem" << endl;
        cout << "4 - Procurar Bagagem" << endl;
        cout << "5 - Voltar para trás" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch (option) {
        case 1: {
            // perguntar para que voo
            // se o voo existir, passar para a parte seguinte, senão mensagem a dizer que esse voo n existe ou algo do genero
            // inputs para fazer a luggage nova
            // inserir no voo
            getMenu();
            break;
        }
        case 2: {
            // perguntar para que voo
            // se o voo existir, passar para a parte seguinte, senão mensagem a dizer que esse voo n existe ou algo do genero
            // input para determinar o id da luggage
            // remover se existir
            getMenu();
            break;
        }
        case 3: listLuggages(); break;
        case 4: {
            // perguntar qual é o voo. Se o voo existir, procurar bagagem com base no id
            // se existir essa bagagem nesse voo, remover, senão mensagem a dizer que ela n está lá
            getMenu();
            break;
        }
        case 5: menuState.pop(); getMenu(); break;
    }
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
        if (option < 1 || option > 9) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 9);

    switch(option) {
        case 1: listEmployees(); getMenu(); break;
        case 2: listServices(); getMenu(); break;
        case 3: {
            //company.addWorker()
            getMenu();
            break;
        }
        case 4: {
            //flight.addService()
            getMenu();
            break;
        }
        case 5: {
            //company.removeWorker()
            getMenu();
            break;
        }
        case 6: {
            //flight.removeService()
            getMenu();
            break;
        }
        case 7: {
            //company.findWorker()
            getMenu();
            break;
        }
        case 8: {
            //flight.findService()
            getMenu();
            break;
        }
        case 9: menuState.pop(); getMenu(); break;
    }
}

void Menu::transportDataMenu() {
    
    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar transporte" << endl;
        cout << "2 - Remover transporte" << endl;
        cout << "3 - Listar transportes" << endl;
        cout << "4 - Find transporte" << endl;
        cout << "5 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch (option) {
        case 1: {
            // perguntar qual é o flight, se existir, adicionar o transporte
            getMenu();
            break;
        }
        case 2: {
            // perguntar qual é o flight, se existir, remover o transporte
            getMenu();
            break;
        }
        case 3: listTransports(); getMenu(); break;
        case 4: {
            // perguntar qual é o flight, se existir, mostrar o transporte
            getMenu();
            break;
        }
        case 5: menuState.pop(); getMenu(); break;
    }
}

void Menu::passengerMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Os meus bilhetes" << endl;
        cout << "2 - Comprar bilhete" << endl;
        cout << "3 - Cancelar bilhete" << endl;
        cout << "4 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 4) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 4);

    switch (option) {
        case 1:
            allLists();
            break;
        case 2:
            menuState.push(BUY_TICKET_MENU);
            getMenu();
            break;
        case 3:
            menuState.push(CANCEL_TICKET_MENU);
            getMenu();
            break;
        case 4:
            menuState.pop(); getMenu();
    }
}

Passenger Menu::fillPassengerData() {

    string origin,destination,id,name,passportNumber;
    short int age;
    char gender;
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
    return {id, name, age, gender, passportNumber};

}

void Menu::buyTicket() {
    short int quantityOfPassengers;
    string origin, destinantion;
    Flight* flight;
    while(true) {
        cout << "Where do you want to travel from?" << endl;
        cin >> origin;
        cout << "Where do you want to travel to?" << endl;
        cin >> destinantion;
        flight = company->findFlight(origin,destinantion);
        if(!nullptr) {
            
        }
    }
}

void Menu::cancelTicket() {


}

void Menu::allLists() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listar Avioes" << endl;
        cout << "2 - Listar Voos" << endl;
        cout << "3 - Listar Passengers" << endl;
        cout << "4 - Listar Luggages" << endl;
        cout << "5 - Listar Services" << endl;
        cout << "6 - Listar Employessss" << endl;
        cout << "7 - Listar Transportes" << endl;
        cout << "8 - Quit" << endl;
        cout << "Your choice: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 8) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 8);

    switch (option) {
        case 1: listPlanes(); break;
        case 2: listFlights(); break;
        case 3: listPassengers(); break;
        case 4: listLuggages(); break;
        case 5: listServices(); break;
        case 6: listEmployees(); break;
        case 7: listTransports(); break;
        case 8: menuState.pop(); getMenu(); break;
    }
}

void Menu::listPlanes() {

    char option;
    int numMax;
    vector<Plane*> planes;
    cout << "Lista total ou parcial? T/P: "; cin >> option;
    if (toupper(option) == 'T') {
        planes = company->getAllPlanes();
        cout << &planes;
    } else {
        // se é parcial, saber qual é o número máximo de aviões a listar
        cout << "Number maximum of planes to show: "; cin >> numMax;
    }


}

void Menu::listFlights() {


}

void Menu::listPassengers() {


}

void Menu::listLuggages() {


}

void Menu::listServices() {


}

void Menu::listEmployees() {


}

void Menu::listTransports() {


}

#endif // PROJECT_AED_MENU_CPP