#include <iostream>
#include "FirstClass.h"
using namespace std;

/**
 * Uma função muito simples que chama as classes
 */
void Application() {

    int n1, n2;
    First f = First();

    cout << "Number 1: "; cin >> n1;
    cout << "Number 2: "; cin >> n2;
    cout << "Result = " << f.sum(n1, n2) << endl;

}