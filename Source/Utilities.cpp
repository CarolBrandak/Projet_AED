#ifndef PROJECT_AED_UTILITIES_H
#define PROJECT_AED_UTILITIES_H

#include "Utilities.h"

// Para os voos

bool byNumberOfPassengers(const Flight &f1, const Flight &f2) {
    return f1.getPassengersQuantity() < f2.getPassengersQuantity();
}

bool byTotalWeight(const Flight &f1, const Flight &f2) {
    return f1.quantityOfWeight < f2.quantityOfWeight;
}

bool byDate(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DATE < f2.FLIGHT_DATE;
}

bool byDuration(const Flight &f1, const Flight &f2) {
    return f1.FLIGHT_DURATION < f2.FLIGHT_DURATION;
}


// Outras coisas

#endif // PROJECT_AED_UTILITIES_H