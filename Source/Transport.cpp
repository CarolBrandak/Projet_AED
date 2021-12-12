#ifndef PROJECT_AED_TRANSPORT_CPP
#define PROJECT_AED_TRANSPORT_CPP

#include "Transport.h"

Transport::Transport() {}

Transport::Transport(string type, int distance, Date date) : type(type), distance(distance), date(date) {}

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
    return this->type == transport.type &&
            this->distance == transport.distance && this->date.getMinute() == transport.getDate().getMinute();
}

bool Transport::operator < (const Transport &transport) const {
    if (this->distance == transport.distance) {
        if (this->date == transport.date) {
            return this->type < transport.type;
        } return this->date < transport.date;
    } return this->distance < transport.distance;
}

ostream& operator<<(ostream &os, const Transport &transport) {
    os << transport.getType() << " " << transport.getDistance() << " " << transport.getDate() << endl;
    return os;
}

#endif // PROJECT_AED_TRANSPORT_CPP
