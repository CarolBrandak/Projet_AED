#ifndef PROJECT_AED_TRANSPORT_CPP
#define PROJECT_AED_TRANSPORT_CPP

#include "Transport.h"

Transport::Transport() : ID(""), TYPE(""), DISTANCE(0), DATE(Date(0, 0)) {}

Transport::~Transport() {}

Transport::Transport(string id, string type, int distance, Date date) : ID(id), TYPE(type), DISTANCE(distance), DATE(date) {}

string Transport::getID() const {
    return ID;
}

string Transport::getType() const {
    return TYPE;
}

int Transport::getDistance() const {
    return DISTANCE;
}

Date Transport::getDate() const {
    return DATE;
}

bool Transport::operator == (const Transport &transport) const {
    return TYPE == transport.TYPE && DISTANCE == transport.DISTANCE;
}

bool Transport::operator < (const Transport &transport) const {
    if (this->DISTANCE == transport.DISTANCE) {
        if (this->DATE == transport.DATE) {
            return this->TYPE < transport.TYPE;
        } return this->DATE < transport.DATE;
    } return this->DISTANCE < transport.DISTANCE;
}

ostream& operator<<(ostream &os, const Transport &transport) {
    os << "Tipo: " << transport.TYPE <<
        "\nDistancia ao aeroporto: " << transport.DISTANCE <<
        "\nHora de partida: " << transport.DATE << endl;
    return os;
}

#endif // PROJECT_AED_TRANSPORT_CPP