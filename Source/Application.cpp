#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Company.h"

using namespace std;

void Application() {

    /**
     * Atenção!
     * Versão experimental da povoação do sistema com base em ficheiros.
     * Rodar a aplicação provoca mudanças nos ficheiros em "Files". No final deixar
     * como estavam inicialmente (há bugs para corrigir, ver abaixo)
     * Os testes não correm (brevemente serão baseados somente nos dados dos ficheiros, para poupar trabalho)
     *
     * Bugs detectados e não corrigidos:
     * A adição de um novo aeroporto/passageiro... causa uma dupla adição nos respectivos ficheiros,
     * quando agency.saveData() é invocada. Causa ainda por descobrir.
     *
     * Aspectos a melhorar no futuro:
     * - Inserir os saves() como métodos da agência
     * - Documentar o resto da agência
     * - IDs semi-automáticos, para não haver colisão
     * - Melhorar a aquisição do directório dos ficheiros
     */

    // Criação do objecto principal, que é automaticamente carregado toda a informação dos ficheiros
    Company agency = Company("Maravilhosa agência de viagens!");

    // Adiciona um novo Aeroporto
    Airport* a = new Airport("4", "Aeroporto Internacional de Pequim", "Pequim");
    agency.addAirport(*a);

    // Adiciona um novo passageiro ao voo 1, do Avião 1 do Aeroporto 1
    Passenger* p = new Passenger("1118", "Novo Passageiro", 56, 'F', "ISDM9374");
    agency.getAirports()[0]->getPlanes()[0]->getFlights().front()->addPassenger(*p);

    // Troca o nome do passageiro 1 do voo 1 do Avião 2 do Aeroporto 1
    agency.getAirports()[0]->getPlanes()[1]->getFlights().front()->getPassengers()[0]->setName("Augusto Sousa");

    //agency.printData(); --> quase 700 linhas de output, façam por vossa conta e risco!
    agency.saveData();
}