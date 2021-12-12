#ifndef PROJECT_AED_TRANSPORT_CPP
#define PROJECT_AED_TRANSPORT_CPP

#include "Transport.h"

Transport::Transport() {}

Transport::Transport(string id, string type, int distance, Date date) : id(id), type(type), distance(distance), date(date) {}

string Transport::getID() const {
    return id;
}

string Transport::getType() const {
    return type;
}

int Transport::getDistance() const {
    return distance;
}

Date Transport::getDate() const {
    return date;
}

bool Transport::operator == (const Transport &transport) const {
    return this->id == transport.id && this->type == transport.type && this->distance == transport.distance &&
            this->date == transport.date;
}

bool Transport::operator < (const Transport &transport) const {
    if (this->distance == transport.distance) {
        if (this->date == transport.date) {
            return this->type < transport.type;
        } return this->date < transport.date;
    } return this->distance < transport.distance;
}

ostream& Transport::operator<<(ostream &os, const Transport &transport) const {
    os << id << " " << type << " " << distance << " " << date << endl;
    return os;
}

#endif // PROJECT_AED_TRANSPORT_CPP
