#include <string>
using namespace std;

class First {

    string phrase;
    public:
        First(string &phrase) : phrase(phrase) {};
        void show() {
            cout << this->phrase << endl;
        };
};