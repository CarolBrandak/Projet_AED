#include "Company.h"

void Application() {

    Company company = Company("AirED");
    company.presentation();

    company.saveData("../Source/Files/");

}