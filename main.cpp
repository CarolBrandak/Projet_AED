#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Source/Application.cpp"

int main() {

    testing::InitGoogleTest();
    char answer;

    cout << "Run Tests (T) or Application (A):  "; cin >> answer;
    if (answer == 'T' || answer == 't') {
        cout << "Run Tests" << endl;
        return RUN_ALL_TESTS();
    } else {
        cout << "Run Application" << endl;
        Application();
        return 0;
    }
}
