#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Luggage.h"

using testing::Eq;

TEST(Luggage, gettersAndSetters) {

    // Getters
    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Luggage l1 = Luggage(45, v1, true);
    ASSERT_EQ(45, l1.getWeight());
    ASSERT_EQ(28, l1.getVolume());
    ASSERT_EQ(true, l1.getPlaneHold());

    // Setters
    l1.setPlaneHold(false);
    ASSERT_EQ(false, l1.getPlaneHold());
}

TEST(Luggage, operators) {

    vector<Luggage> luggages = {};
    Volume v1; v1.depth = 1; v1.height = 4; v1.width = 7;
    Volume v2; v2.depth = 2; v2.height = 5; v2.width = 8;
    Volume v3; v3.depth = 3; v3.height = 6; v3.width = 9;
    Luggage l1 = Luggage(45, v1, true); luggages.push_back(l1);
    Luggage l2 = Luggage(2, v2, false); luggages.push_back(l2);
    Luggage l3 = Luggage(2, v3, false); luggages.push_back(l3);
    Luggage l4 = Luggage(45, v1, true); luggages.push_back(l4);
    Luggage l5 = Luggage(89, v2, true); luggages.push_back(l5);
    Luggage l6 = Luggage(1, v3, true); luggages.push_back(l6);

    // Equality, ==
    ASSERT_EQ(true, l1 == l4);
    ASSERT_EQ(false, l2 == l3);

    // Operator <
    sort(luggages.begin(), luggages.end());
    ASSERT_EQ(luggages[0], l6);
    ASSERT_EQ(luggages[1], l2);
    ASSERT_EQ(luggages[2], l3);
    ASSERT_EQ(luggages[3], l1);
    ASSERT_EQ(luggages[4], l4);
    ASSERT_EQ(luggages[5], l5);

    // Operator <<
    cout << "Cout das bagagens, por ordem crescente:" << endl;
    for (Luggage luggage : luggages) {
        cout << luggage;
    }
}