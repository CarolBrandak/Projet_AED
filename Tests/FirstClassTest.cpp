#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/FirstClass.h"

using testing::Eq;

TEST(test_1, sum1) {

    First teste = First();
    int a = 10, b = 30;
    int result = teste.sum(a, b);
    EXPECT_EQ(40, result);
}

TEST(test_2, sum2) {

    First teste = First();
    int a = -453, b = 31;
    int result = teste.sum(a, b);
    EXPECT_EQ(-422, result);
}