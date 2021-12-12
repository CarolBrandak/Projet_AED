#ifndef PROJECT_AED_TRANSPORT_H
#define PROJECT_AED_TRANSPORT_H

#include <string>
#include "Date.h"

class Transport {

    private:
        const string type;
        const int distance;
        const Date date;
    public:
        Transport();
        Transport(string type, int distance, Date date);
        string getType() const;
        int getDistance() const;
        Date getDate() const;
        bool operator < (const Transport &transport) const;
        bool operator == (const Transport &transport) const;
};

ostream & operator << (ostream &os, const Transport &transport);

#endif // PROJECT_AED_TRANSPORT_H
