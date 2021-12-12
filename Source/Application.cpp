#include "Company.h"

void Application() {

    Company company = Company("AirED");
    cout << "Welcome to " << company.getName() << " Company!" << endl;

    Plane *P = new Plane(to_string(company.getNextPlaneID()), "Taltaltal", "Outracena", 9238, 39);
    company.addPlane(P);
    //cout << company.getPlanes().size() << endl;
    company.saveData("../Source/Files/");
}