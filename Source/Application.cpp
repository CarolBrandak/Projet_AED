#include "Company.h"

void Application() {

    Company company = Company("AirED");
    cout << "Welcome to " << company.getName() << " Company!" << endl;

    cout << "Print data:" << endl;
    company.printData();
    /**
    cout << "Vai salvar a data!" << endl;
    company.saveData("../Source/Files/");
     */

}