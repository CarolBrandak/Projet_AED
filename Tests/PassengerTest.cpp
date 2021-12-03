#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Passenger.h"

using testing::Eq;

TEST(Passenger, gettersAndSetters) {

    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Luggage commonLuggage1 = Luggage("1",45, v1, true);
    Luggage commonLuggage2 = Luggage("1",3, v1, false);
    vector<Luggage> commonLuggage = {commonLuggage1, commonLuggage2};

    // Getters
    Passenger e1 = Passenger("1","Pedro", 20, 'M', "FEUP2021", commonLuggage);
    ASSERT_EQ("Pedro", e1.getName());
    ASSERT_EQ(20, e1.getAge());
    ASSERT_EQ('M', e1.getGender());
    ASSERT_EQ(commonLuggage, e1.getLuggage());

    // Setters
    e1.setAge(21); e1.setName("Marco");
    ASSERT_EQ(21, e1.getAge());
    ASSERT_EQ("Marco", e1.getName());
}

TEST(Passenger, operators) {

    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Luggage commonLuggage1 = Luggage("1",45, v1, true);
    Luggage commonLuggage2 = Luggage("1",3, v1, false);
    vector<Luggage> commonLuggage = {commonLuggage1, commonLuggage2};

    vector<Passenger> passengers = {};
    Passenger e1 = Passenger("1","Pedro", 20, 'M', "FEUP2021", commonLuggage); passengers.push_back(e1);
    Passenger e2 = Passenger("1","Carlos", 20 , 'm', "ISCTE21", commonLuggage); passengers.push_back(e2);
    Passenger e3 = Passenger("1","Gabriel", 20, 'M', "master21", commonLuggage); passengers.push_back(e3);
    Passenger e4 = Passenger("1","Carolina", 20, 'f', "2points", commonLuggage); passengers.push_back(e4);
    Passenger e5 = Passenger("1","Fabio", 19, 'm', "things1", commonLuggage); passengers.push_back(e5);

    // Equality, ==
    ASSERT_EQ(false, e1 == e4);
    ASSERT_EQ(false, e2 == e1);

    // Operator <
    sort(passengers.begin(), passengers.end());
    ASSERT_EQ(passengers[0], e5);
    ASSERT_EQ(passengers[1], e2);
    ASSERT_EQ(passengers[2], e4);
    ASSERT_EQ(passengers[3], e3);
    ASSERT_EQ(passengers[4], e1);

    // Operator <<
    cout << "Cout dos passageiros, por ordem crescente:" << endl;
    for (Passenger passenger : passengers) {
        cout << passenger;
    }
}

TEST(Passenger, totalLuggageVolume) {

    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Luggage commonLuggage1 = Luggage("1",45, v1, true);
    Luggage commonLuggage2 = Luggage("1",3, v1, false);
    vector<Luggage> commonLuggage = {commonLuggage1, commonLuggage2};
    Passenger e1 = Passenger("1","Pedro", 20, 'M', "FEUP2021", commonLuggage);

    ASSERT_EQ(56, e1.getTotalVolume());

}

TEST(Passenger, totalLuggageWeight) {

    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Luggage commonLuggage1 = Luggage("1",45, v1, true);
    Luggage commonLuggage2 = Luggage("1",3, v1, false);
    vector<Luggage> commonLuggage = {commonLuggage1, commonLuggage2};
    Passenger e1 = Passenger("1","Pedro", 20, 'M', "FEUP2021", commonLuggage);

    ASSERT_EQ(48, e1.getTotalWeight());
}