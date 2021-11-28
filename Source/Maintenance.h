//
// Created by gabrieltmjr on 11/28/2021.
//

#ifndef PROJET_AED_MAINTENANCE_H
#define PROJET_AED_MAINTENANCE_H

#include "Service.h"

class Maintenance: public Service {
public:
    /**
     * Constructor for creating a Maintenance object
     * @param serviceDate
     * @param responsible
     */
    Maintenance(Date serviceDate, Employee responsible);
    Date getServiceDate() {
        return serviceDate;
    }

    Employee getResponsible() {
        return responsible;
    }
};

#endif //PROJET_AED_MAINTENANCE_H
