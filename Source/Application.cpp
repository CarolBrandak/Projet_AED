#include "Company.h"

void Application() {

    Company company = Company("AirED");
    cout << "Welcome to " << company.getName() << " Company!" << endl;
    //company.printData();
    company.saveData("../Source/Files/");
}