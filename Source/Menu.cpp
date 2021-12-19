#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"

Menu::Menu() {
    this->company = new Company("AirED");
    this->menuState.push(MAIN_MENU);
    company->presentation();
    getMenu();
}

void Menu::getMenu() {

    if (!menuState.empty()) {
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
    } else exit(0);
}

void Menu::mainMenu() {

    int option;
    do {
        cout << "=======================================" << endl;
        cout << "1 - Menu gestor da companhia" << endl;
        cout << "2 - Menu passageiro" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=======================================" << endl;
        if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 3);

    switch (option) {
        case 1: menuState.push(COMPANY_MENU); break;
        case 2: menuState.push(PASSENGER_MENU); break;
        case 3: menuState.pop();
    }
    getMenu();
}

void Menu::companyMenu() {

    int option;
    do {
        cout << "=======================================" << endl;
        cout << "1 - Avioes" << endl;
        cout << "2 - Voos" << endl;
        cout << "3 - Passageiros" << endl;
        cout << "4 - Bagagem" << endl;
        cout << "5 - Transportes" << endl;
        cout << "6 - Funcionarios / Servicos" << endl;
        cout << "7 - Voltar para o menu principal" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=======================================" << endl;
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
        cout << "1 - Adicionar aviao" << endl;
        cout << "2 - Remover aviao" << endl;
        cout << "3 - Listar avioes" << endl;
        cout << "4 - Procurar aviao" << endl;
        cout << "5 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch (option) {
        case 1: {
            Plane newPlane = fillPlaneData(company->getNextPlaneID());
            company->addPlane(newPlane);
            company->save();
            cout << "Adicionou o aviao:\n" << newPlane << endl;
            getMenu();
            break;
        }
        case 2: {
            string id;
            cout << "Id do aviao a remover: ";
            cin >> id;
            if (company->removePlane(id)) {
                company->save();
                cout << "O aviao com id " << id << " foi removido" << endl;
            }
            else
                cout << "O aviao com id " << id << " nao existe" << endl;
            getMenu();
            break;
        }
        case 3: listPlanes(); break;
        case 4: {
            string id;
            cout << "Id do aviao a procurar: ";
            cin >> id;
            Plane *plane = company->findPlane(id);
            if (plane) cout << *plane << endl;
            else cout << "O aviao com id " << id << " nao existe" << endl;
            getMenu();
            break;
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
        cout << "5 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    switch(option) {
        case 1: {
            string id;
            cout << "Id do aviao: ";
            cin >> id;
            Plane *plane = company->findPlane(id);
            if (plane) {
                Flight newFlight = fillFlightData(plane->getNextFlightID());
                plane->addFlight(newFlight);
                company->addFlight(newFlight);
                company->save();
            } else cout << "O aviao com id " << id << " nao existe" << endl;
            getMenu();
            break;
        }
        case 2: {
            string origin, destination;
            cout << "Por favor introduza a cidade de origem: ";
            cin >> origin;
            cout << "Por favor introduza a cidade de destino: ";
            cin >> destination;
            Flight* flight = company->findFlight(origin, destination);
            if (flight) {
                company->removeFlight(*flight);
                company->save();
            } else cout << "O voo com origem " << origin << " e destino " << destination << " nao existe" << endl;
            getMenu();
            break;
        }
        case 3: listFlights(); break;

        case 4: {
            string origin, destination;
            cout << "Por favor introduza a cidade de origem: ";
            cin >> origin;
            cout << "Por favor introduza a cidade de destino: ";
            cin >> destination;
            Flight* flight = company->findFlight(origin, destination);
            if (flight) cout << *flight;
            else cout << "Voo nao encontrado na base de dados" << endl;
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
        cout << "5 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);


    string origin, destination, passport;
    switch (option) {
        case 1: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight* flight = company->findFlight(origin,destination);
            if (flight) {
                try {
                    Passenger newPassenger = fillPassengerData(flight->getNextPassengerID());
                    flight->addPassenger(newPassenger);
                    company->addPassenger(newPassenger);
                    company->save();
                } catch (InvalidPassenger &error) {
                    error.showError();
                }
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 2: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight* flight = company->findFlight(origin, destination);
            if (flight) {
                cout << "Passaporte do passageiro: "; cin >> passport;
                Passenger *p = flight->findPassenger(passport);
                if (p) {
                    flight->removePassenger(*p);
                    company->removePassenger(*p);
                    company->save();
                    cout << "O passageiro\n" << *p << "foi eliminado com sucesso" << endl;
                } else cout << "O passageiro de passaporte " << passport << " nao se encontra neste voo" << endl;

            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 3: listPassengers(); break;
        case 4: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                cout << "Passaporte do passageiro: "; cin >> passport;
                Passenger *p = flight->findPassenger(passport);
                if (p) {
                    cout << *p << endl;
                } else cout << "O passageiro de passaporte " << passport << " nao se encontra neste voo" << endl;
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 5: menuState.pop(); getMenu(); break;
    }
}

void Menu::luggageDataMenu() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Adicionar Bagagem" << endl;
        cout << "2 - Remover Bagagem" << endl;
        cout << "3 - Listar Bagagem" << endl;
        cout << "4 - Procurar Bagagem" << endl;
        cout << "5 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    string origin, destination, passport, id;
    switch (option) {
        case 1: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                cout << "Passaporte do passageiro: "; cin >> passport;
                Passenger *p = flight->findPassenger(passport);
                if (p) {
                    try {
                        Luggage l = fillLuggageData(p->getID());
                        p->addLuggage(l);
                        company->addLuggage(l);
                        company->save();
                    } catch (InvalidLuggage &error) {
                        error.showError();
                    }
                } else cout << "O passageiro de passaporte " << passport << " nao se encontra neste voo" << endl;
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 2: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                cout << "Id da barragem a remover: "; cin >> id;
                Luggage *luggage = flight->findLuggage(id);
                if (luggage) {
                    flight->removeLuggage(luggage->getID());
                    company->removeLuggage(*luggage);
                    company->save();
                } else cout << "A bagagem de id " << id << " nao existe neste voo" << endl;
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 3: listLuggages(); break;
        case 4: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                cout << "Id da barragem a remover: "; cin >> id;
                Luggage *luggage = flight->findLuggage(id);
                if (luggage) {
                    cout << *luggage << endl;
                } else cout << "A bagagem de id " << id << " nao existe neste voo" << endl;
            } else cout << "O voo nao existe na base de dados" << endl;
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
        cout << "2 - Listagem de Servicos" << endl;
        cout << "3 - Adicionar Servico" << endl;
        cout << "4 - Modificar Trabalhador" << endl;
        cout << "5 - Realizar Servico" << endl;
        cout << "6 - Procurar Trabalhador" << endl;
        cout << "7 - Procurar Servico" << endl;
        cout << "8 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 8) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 8);

    switch(option) {
        case 1: listEmployees(); getMenu(); break;
        case 2: listServices(); getMenu(); break;
        case 3: {
            string id;
            cout << "ID do aviao: "; cin >> id;
            Plane *p = company->findPlane(id);
            if (p) {
                try {
                    Service s = fillServiceData(p->getID());
                    p->addService(s);
                    company->addService(s);
                    company->save();
                } catch (InvalidService &error) {
                    error.showError();
                }
            } else cout << "Nao existe na base de dados um aviao com id = " << id << endl;
            getMenu();
            break;
        }
        case 4: {
            string id;
            int year, month, day, hour, minute;
            cout << "ID do aviao: "; cin >> id;
            Plane *p = company->findPlane(id);
            if (p) {
                Date d = fillDateData();
                Service *s = p->findService(d);
                if (s) {
                    try {
                        Employee e = fillEmployeeData();
                        s->setResponsible(e);
                        company->setServiceResponsible(*s, e);
                        company->save();
                    } catch (InvalidEmployee &error) {
                        error.showError();
                    }
                } else cout << "Nao existe nenhum servico nessa data" << endl;
            } else cout << "Nao existe na base de dados um aviao com id = " << id << endl;
            getMenu();
            break;
        }
        case 5: {
            string id;
            cout << "ID do aviao: "; cin >> id;
            Plane *p = company->findPlane(id);
            if (p) {
                p->setNextServiceAsDone();
            } else cout << "Nao existe na base de dados um aviao com id = " << id << endl;
            getMenu();
            break;
        }
        case 6: {
            string id;
            cout << "ID do aviao: "; cin >> id;
            Plane *p = company->findPlane(id);
            if (p) {
                try {
                    Date d = fillDateData();
                    Service *s = p->findService(d);
                    if (s) {
                        cout << *s << endl;
                    } else cout << "Nao existe qualquer servico nessa data" << endl;
                } catch (InvalidDate &dateError) {
                    dateError.showError();
                } catch (InvalidService &serviceError) {
                    serviceError.showError();
                }
            } else cout << "Nao existe na base de dados um aviao com id = " << id << endl;
            getMenu();
            break;
        }
        case 7: {
            string id;
            cout << "ID do aviao: "; cin >> id;
            Plane *p = company->findPlane(id);
            if (p) {
                string name;
                cin.clear(); cin.ignore(1000, '\n');
                cout << "Nome do funcionario: "; getline(cin, name);
                try {
                    Employee *e = p->findEmployee(name);
                    if (e) {
                        cout << *e << endl;
                    } else cout << "Nao existe qualquer funcionario a trabalhar nessa data" << endl;
                } catch (InvalidEmployee &error) {
                    error.showError();
                }
            } else cout << "Nao existe na base de dados um aviao com id = " << id << endl;
            getMenu();
            break;
        }
        case 8: menuState.pop(); getMenu(); break;
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
        cout << "5 - Voltar para tras" << endl;
        cout << "Escolha: ";
        cin >> option;
        cout << "=====================================" << endl;
        if (option < 1 || option > 5) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');

    } while (option < 1 || option > 5);

    string origin, destination;
    switch (option) {
        case 1: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                try {
                    Transport t = fillTransportData(flight->getID());
                    flight->addTransport(&t);
                    company->addTransport(t);
                    company->save();
                } catch (TransportAlreadyExist &error) {
                    error.showError();
                }
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 2: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                try {
                    Transport t = fillTransportData(flight->getID());
                    flight->getAirport().showTransports();
                    flight->removeTransport(&t);
                    company->removeTransport(t);
                    company->save();
                } catch (TransportDoesNotExist &error) {
                    error.showError();
                }
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
        }
        case 3: listTransports(); getMenu(); break;
        case 4: {
            cout << "Por favor introduza a cidade de origem: "; cin >> origin;
            cout << "Por favor introduza a cidade de destino: "; cin >> destination;
            Flight *flight = company->findFlight(origin, destination);
            if (flight) {
                try {
                    char op;
                    cout << "Pesquisar por horario, tipo ou distancia? H/T/D: "; cin >> op;
                    op = toupper(op);
                    if (op == 'H') {
                        int hour, minute;
                        cout << "Hora: "; cin >> hour;
                        cout << "Minute: "; cin >> minute;
                        Transport *t = flight->searchTransport(hour, minute);
                        if (t) cout << *t << endl;
                        else cout << "Nao existe transporte com essa carateristica" << endl;
                    } else if (op == 'T') {
                        string type;
                        cout << "Tipo: "; cin >> type;
                        vector<Transport*> t = flight->searchTransport(type);
                        for (Transport *transport : t) cout << *transport << endl;
                    } else {
                        int distance;
                        cout << "Distancia (em metros): "; cin >> distance;
                        Transport *t = flight->searchTransport(distance);
                        if (t) cout << *t << endl;
                        else cout << "Nao existe transporte com essa carateristica" << endl;
                    }
                } catch (InvalidTransport &error) {
                    error.showError();
                }
            } else cout << "O voo nao existe na base de dados" << endl;
            getMenu();
            break;
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
        cout << "1 - Listagens" << endl;
        cout << "2 - Comprar bilhete" << endl;
        cout << "3 - Cancelar bilhete" << endl;
        cout << "4 - Voltar ao menu principal" << endl;
        cout << "Escolha: ";
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

void Menu::buyTicket() {
    unsigned int quantityOfPassengers;

    string origin, destination;
    Flight* flight;
    cout << "De onde quer viajar?" << endl;
    cin >> origin;
    cout << "Para onde quer viajar?" << endl;
    cin >> destination;
    flight = company->findFlight(origin, destination);
    if(flight) {
        cout << "Quantas pessoas vao viajar?" << endl;
        cin >> quantityOfPassengers;
        unsigned int flightPassengersAfterAdd = flight->getPassengersQuantity()+quantityOfPassengers;
        Plane *plane = company->findPlane(flight->getID().substr(0,flight->getID().find('-')));
        if(flightPassengersAfterAdd <= plane->getMaxPassengersCapacity()) {
            short int cont = 1, quantityOfLuggage;
            vector<Passenger*> allPassengers;
            vector<Luggage*> allLuggage;
            short int totalWeight = 0;
            while(cont <= quantityOfPassengers) {
                cout << "Insira os dados o " << cont << "o passageiro" << endl;
                Passenger passenger = fillPassengerData(flight->getNextPassengerID());
                cout << "Quantas malas tem o " << passenger.getName() << "?" << endl;
                cin >> quantityOfLuggage;
                for(short int contLuggage = 1; contLuggage <= quantityOfLuggage; contLuggage++) {
                    cout << "Insira os dados da " << contLuggage << "a baggagem" << endl;
                    Luggage luggage = fillLuggageData(passenger.getID());
                    totalWeight += luggage.getWeight();
                    passenger.addLuggage(luggage);
                    allLuggage.push_back(&luggage);
                }
                allPassengers.push_back(&passenger);
                cont++;
            }
            if (plane->getMaxWeightCapacity() >= (totalWeight + flight->getWeightQuantity())) {
                for (Passenger *passenger : allPassengers) {
                    flight->addPassenger(*passenger);
                    company->addPassenger(*passenger);
                }
                for (Luggage *luggage : allLuggage) company->addLuggage(*luggage);
                company->save();
                cout << "O(s) passageiro(s) foram adicionados ao voo!" << endl;
            } else {
                cout << "Nao foi possivel adicionar o(s) passageiro(s) no voo porque o peso total do aviao apos a vossa"
                        "adicao, excede o limite" << endl;
            }
        }
        menuState.pop();
        getMenu();
    }
}

void Menu::cancelTicket() {

    string origin, destination, passport;
    char op;
    bool answer = true;
    bool respostaValida = false;
    do {
        cout << "De onde quer viajar?" << endl;
        cin >> origin;
        cout << "Para onde quer viajar?" << endl;
        cin >> destination;
        Flight *flight = company->findFlight(origin, destination);
        if (flight) {
            cout << "Numero de passaporte: ";
            cin >> passport;
            Passenger *p = flight->findPassenger(passport);
            if (p) {
                flight->removePassenger(*p);
                company->removePassenger(*p);
                company->save();
            }
        }

        do {
            cout << "Quer cancelar outro bilhete? S/N"; cin >> op;
            if(op == 'S' || op == 's') { respostaValida = true; }
            else if(op == 'N' || op == 'n') { answer = false; respostaValida = true;}

            if(!respostaValida) cout << "Por favor insira S ou N" << endl;

        } while (!respostaValida);

    } while (answer);
    menuState.pop();
    getMenu();
}

void Menu::allLists() {

    int option;
    do {
        cout << "=====================================" << endl;
        cout << "1 - Listar Avioes" << endl;
        cout << "2 - Listar Voos" << endl;
        cout << "3 - Listar Passageiros" << endl;
        cout << "4 - Listar Bagagens" << endl;
        cout << "5 - Listar Servicos" << endl;
        cout << "6 - Listar Funcionarios" << endl;
        cout << "7 - Listar Transportes" << endl;
        cout << "8 - Voltar para tras" << endl;
        cout << "Escolha: ";
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

Plane Menu::fillPlaneData(const string &id) {

    string licencePlate, type;
    int weightCapacity, passengerCapacity;
    cout << "Matricula: "; cin >> licencePlate;
    cout << "Tipo: "; cin >> type;
    cout << "Capacidade de carga: "; cin >> weightCapacity;
    cout << "Lotacao maxima: "; cin >> passengerCapacity;
    return Plane(id, licencePlate, type, weightCapacity, passengerCapacity);
}

Flight Menu::fillFlightData(const string &id) {

    string origin, destination, airportName;
    int year, month, day, hour, minute, duration;
    Date d = fillDateData();
    cout << "Duracao (em minutos): "; cin >> duration;
    cout << "Origem: "; cin >> origin; cin.clear(); cin.ignore(1000, '\n');
    cout << "Destino: "; cin >> destination;cin.clear(); cin.ignore(1000, '\n');
    cout << "Nome do aeroporto de destino: "; getline(cin, airportName);
    return Flight(id, d, duration, origin, Airport(airportName, destination));
}

Passenger Menu::fillPassengerData(const string &id) {

    string name, passport;
    short int age;
    char gender;
    cin.clear(); cin.ignore(1000, '\n');
    cout << "Nome: "; getline(cin, name);
    cout << "Idade: "; cin >> age;
    cout << "Genero M/F/?: "; cin >> gender;
    cout << "Passaporte: "; cin >> passport;
    if (name.empty() || passport.empty()) throw InvalidPassenger(new Passenger(id, name, age, gender, passport));
    return Passenger(id, name, age, gender, passport);
}

Luggage Menu::fillLuggageData(const string &id) {

    short int weight, width, height, depth;
    char planeHold;
    cout << "Peso (em Kgs): "; cin >> weight;
    cout << "Comprimento (em centimetros): "; cin >> width;
    cout << "Largura (em centimetros): "; cin >> height;
    cout << "Profundidade: (em centimetros)"; cin >> depth;
    cout << "Bagagem de mao? S/N"; cin >> planeHold;
    Volume v = {width, height, depth};
    if (weight*width*height*depth <= 0) throw InvalidLuggage(new Luggage(id, weight, v, toupper(planeHold) == 'S'));
    return Luggage(id, weight, v, toupper(planeHold) == 'S');
}

Employee Menu::fillEmployeeData() {

    string name;
    short int age;
    char gender;
    cin.clear(); cin.ignore(1000, '\n');
    cout << "Nome: "; getline(cin, name);
    cout << "Idade: "; cin >> age;
    cout << "Genero: "; cin >> gender;
    if (name.empty() || age < 0 || age > 120) throw InvalidEmployee(Employee(name, age, gender));
    return Employee(name, age, gender);
}

Service Menu::fillServiceData(const string &id) {

    string type;
    int year, month, day, hour, minute;
    cin.clear(); cin.ignore(1000, '\n');
    cout << "Tipo: "; cin >> type;
    Date d = fillDateData();
    Employee e = fillEmployeeData();
    if (type.empty()) throw InvalidService(new Service(id, type, Date(year, month, day, hour, minute), e));
    return Service(id, type, Date(year, month, day, hour, minute), e);
}

Date Menu::fillDateData() {

    int year, month, day, hour, minute;
    cout << "Ano: "; cin >> year;
    cout << "Mes: "; cin >> month;
    cout << "Dia: "; cin >> day;
    cout << "Hora: "; cin >> hour;
    cout << "Minute: "; cin >> minute;
    if (year < 2021 || month > 12 || day > 31 || hour > 23 || minute > 60) throw InvalidDate(Date(year, month, day, hour, minute));
    return Date(day, month, year, hour, minute);
}

Transport Menu::fillTransportData(const string &id) {

    string type;
    int distance, hour, minute;
    cout << "Tipo (taxi, barco, metro...): "; cin >> type;
    cout << "Distancia ao aeroporto: "; cin >> distance;
    cout << "Hora de partida: "; cin >> hour;
    cout << "Minuto de partida: "; cin >> minute;
    if (minute < 0 || minute > 59 || hour < 0 || hour > 23 || type.empty() || distance < 0) throw InvalidTransport(new Transport(id, type, distance, Date(hour, minute)));
    return Transport(id, type, distance, Date(hour, minute));
}

char Menu::totalOrPartial() {

    char option;
    do {
        cout << "Listagem total ou parcial? T/P: ";
        cin >> option;
        if (toupper(option) != 'T' && toupper(option) != 'P') cout << "Input invalido, por favor tente novamente" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (toupper(option) != 'T' && toupper(option) != 'P');

    return toupper(option);
}

void Menu::listPlanes() {

    vector<Plane*> planes = company->getAllPlanes();
    if (!planes.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por capacidade maxima de carga" << endl;
            cout << "2 - Ordenar por lotacao maxima" << endl;
            cout << "3 - Ordenar por numero de voos" << endl;
            cout << "4 - Ordenar por numero de servicos" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 4) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 4);

        switch (option) {
            case 1: sort(planes.begin(), planes.end(), byMaximumWeight); break;
            case 2: sort(planes.begin(), planes.end(), byMaximumCapacity); break;
            case 3: sort(planes.begin(), planes.end(), byNumberOfFlights); break;
            case 4: sort(planes.begin(), planes.end(), byNumberOfServices); break;
        }

        for (Plane *plane : planes) cout << *plane << endl;

    } else cout << "Nao existem avioes a mostrar" << endl;
    getMenu();
}

void Menu::listFlights() {

    char type = totalOrPartial();
    vector<Flight*> flights = {};

    if (type == 'T') flights = company->getAllFlights();
    else {
        string id;
        cout << "ID do aviao: "; cin >> id;
        Plane *p = company->findPlane(id);
        if (p) flights = p->getVectorFlights();
        else {
            cout << "Aviao nao encontrado" << endl;
            getMenu();
        }
    }

    if (!flights.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por carga" << endl;
            cout << "2 - Ordenar por lotacao" << endl;
            cout << "3 - Ordenar por data de partida" << endl;
            cout << "4 - Ordenar por duracao" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 4) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 4);

        switch (option) {
            case 1: sort(flights.begin(), flights.end(), byTotalWeight); break;
            case 2: sort(flights.begin(), flights.end(), byNumberOfPassengers); break;
            case 3: sort(flights.begin(), flights.end(), byDate); break;
            case 4: sort(flights.begin(), flights.end(), byDuration); break;
        }

        for (Flight *flight : flights) cout << *flight << endl;

    } else {
        cout << "O aviao selecionado nao possui qualquer voo" << endl;
    }
    getMenu();
}

void Menu::listPassengers() {

    char type = totalOrPartial();
    vector<Passenger*> passengers = {};

    if (type == 'T') passengers = company->getAllPassengers();
    else {
        string origin, destination;
        cout << "Origem do voo: "; cin >> origin;
        cout << "Destino do voo: "; cin >> destination;
        Flight *flight = company->findFlight(origin, destination);
        if (flight) passengers = flight->getPassengers();
        else {
            cout << "Voo nao encontrado" << endl;
            getMenu();
        }
    }

    if (!passengers.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por nome" << endl;
            cout << "2 - Ordenar por idade" << endl;
            cout << "3 - Ordenar por quantidade de malas" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 3);

        switch (option) {
            case 1: sort(passengers.begin(), passengers.end(), byPassengerName); break;
            case 2: sort(passengers.begin(), passengers.end(), byAge); break;
            case 3: sort(passengers.begin(), passengers.end(), byLuggage); break;
        }

        for (Passenger *passenger : passengers) cout << *passenger << endl;

    } else {
        cout << "O voo selecionado nao possui qualquer passageiro" << endl;
    }
    getMenu();
}

void Menu::listLuggages() {

    char type = totalOrPartial();
    vector<Luggage*> luggage = {};

    if (type == 'T') luggage = company->getAllLuggages();
    else {
        string origin, destination;
        cout << "Origem do voo: "; cin >> origin;
        cout << "Destino do voo: "; cin >> destination;
        Flight *flight = company->findFlight(origin, destination);
        if (flight) luggage = flight->getLuggage();
        else {
            cout << "Voo nao encontrado" << endl;
            getMenu();
        }
    }

    if (!luggage.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por peso" << endl;
            cout << "2 - Ordenar por volume" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 2) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 2);

        switch (option) {
            case 1: sort(luggage.begin(), luggage.end(), byWeight); break;
            case 2: sort(luggage.begin(), luggage.end(), byVolume); break;
        }

        for (Luggage *l : luggage) cout << *l << endl;

    } else {
        cout << "O voo selecionado nao possui qualquer bagagem" << endl;
    }
    getMenu();
}

void Menu::listServices() {

    char type = totalOrPartial();
    vector<Service*> services = {};

    if (type == 'T') services = company->getAllServices();
    else {
        string id;
        cout << "ID do aviao: "; cin >> id;
        Plane *plane = company->findPlane(id);
        if (plane) services = plane->getServices();
        else {
            cout << "Aviao nao encontrado" << endl;
            getMenu();
        }
    }

    if (!services.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por data de realizacao" << endl;
            cout << "2 - Ordenar por tipo" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 2) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 2);

        switch (option) {
            case 1: sort(services.begin(), services.end(), byServiceDate); break;
            case 2: sort(services.begin(), services.end(), byServiceType); break;
        }

        for (Service *service : services) cout << *service << endl;

    } else {
        cout << "O aviao selecionado nao possui qualquer servico" << endl;
    }
    getMenu();
}

void Menu::listEmployees() {

    char type = totalOrPartial();
    vector<Employee> employees = {};

    if (type == 'T')
        for (Service *service : company->getAllServices())
            employees.push_back(service->getResponsible());
    else {
        string id;
        cout << "ID do aviao: "; cin >> id;
        Plane *plane = company->findPlane(id);
        if (plane)
            for (Service *service : plane->getServices())
                employees.push_back(service->getResponsible());
        else {
            cout << "Aviao nao encontrado" << endl;
            getMenu();
        }
    }

    if (!employees.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por nome" << endl;
            cout << "2 - Ordenar por idade" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 2) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 2);

        switch (option) {
            case 1: sort(employees.begin(), employees.end(), byEmployeeName); break;
            case 2: sort(employees.begin(), employees.end(), byEmployeeAge); break;
        }

        for (const Employee &employee : employees) cout << employee << endl;

    } else {
        cout << "O aviao selecionado nao possui qualquer funcionario" << endl;
    }
    getMenu();
}

void Menu::listTransports() {

    char type = totalOrPartial();
    vector<Transport*> transports = {};

    if (type == 'T') transports = company->getAllTransports();
    else {
        string origin, destination;
        cout << "Origem do voo: "; cin >> origin;
        cout << "Destino do voo: "; cin >> destination;
        Flight *flight = company->findFlight(origin, destination);
        if (flight) transports = flight->getAllTransports();
        else {
            cout << "Voo nao encontrado" << endl;
            getMenu();
        }
    }

    if (!transports.empty()) {
        int option;
        do {
            cout << "=====================================" << endl;
            cout << "1 - Ordenar por distancia ao aeroporto" << endl;
            cout << "2 - Ordenar por tipo" << endl;
            cout << "3 - Ordenar por horario" << endl;
            cout << "Escolha: ";
            cin >> option;
            cout << "=====================================" << endl;
            if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');

        } while (option < 1 || option > 3);

        switch (option) {
            case 1: sort(transports.begin(), transports.end(), byDistance); break;
            case 2: sort(transports.begin(), transports.end(), byTransportType); break;
            case 3: sort(transports.begin(), transports.end(), byTransportTime); break;
        }

        for (Transport *transport : transports) cout << *transport << endl;

    } else {
        cout << "O voo selecionado nao possui qualquer transporte" << endl;
    }
    getMenu();
}

#endif // PROJECT_AED_MENU_CPP