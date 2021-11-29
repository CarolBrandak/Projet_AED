#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Date.h"

using testing::Eq;

void fillDates(vector<Date> &dates) {

    dates.push_back(Date(27, 11, 2021, 14, 3));
    dates.push_back(Date(27, 11, 2021, 14, 31));
    dates.push_back(Date(27, 11, 2021, 4, 3));
    dates.push_back(Date(27, 11, 2021, 11, 31));
    dates.push_back(Date(27, 11, 2021, 14, 3));
    dates.push_back(Date(27, 11, 2021, 0, 3));
    dates.push_back(Date(27, 11, 2021, 23, 58));
    dates.push_back(Date(27, 11, 2021, 4, 0));
    dates.push_back(Date(27, 11, 2021, 1, 1));
    dates.push_back(Date(27, 11, 2021, 2, 1));
}

TEST(Data, gettersAndSetters) {

    // Getters
    Date d1 = Date(27, 11, 2021);
    ASSERT_EQ(27, d1.getDay());
    ASSERT_EQ(2021, d1.getYear());
    ASSERT_EQ(11, d1.getMonth());

    // Setters
    d1.setDay(d1.getDay()+4);
    d1.setMonth(d1.getMonth()-3);
    d1.setYear(d1.getYear()-1);
    ASSERT_EQ(31, d1.getDay());
    ASSERT_EQ(2020, d1.getYear());
    ASSERT_EQ(8, d1.getMonth());
}

TEST(Data, operators) {

    vector<Date> dates = {};
    Date d1 = Date(27, 11, 2021); dates.push_back(d1);
    Date d2 = Date(9, 3, 2018); dates.push_back(d2);
    Date d3 = Date(29, 11, 2045); dates.push_back(d3);
    Date d4 = Date(27, 11, 2021); dates.push_back(d4);
    Date d5 = Date(1, 1, 2021); dates.push_back(d5);
    Date d6 = Date(4, 12, 2021); dates.push_back(d6);

    // Equality, ==
    ASSERT_EQ(false, d1 == d6);
    ASSERT_EQ(true, d1 == d4);

    // Operator <
    sort(dates.begin(), dates.end());
    ASSERT_EQ(dates[0], d2);
    ASSERT_EQ(dates[1], d5);
    ASSERT_EQ(dates[2], d1);
    ASSERT_EQ(dates[3], d4);
    ASSERT_EQ(dates[4], d6);
    ASSERT_EQ(dates[5], d3);

    // Operator << and print style: 9-3-2018 -> 09-03-2018
    cout << "Cout das datas, por ordem crescente:" << endl;
    for (Date date : dates) {
        cout << date;
    }
}

TEST(Data, hoursAndMinutes) {

    vector<Date> dates = {};
    fillDates(dates);

    // Operator <
    ASSERT_EQ(dates[0], Date(27, 11, 2021, 0, 3));
    ASSERT_EQ(dates[dates.size()-1], Date(27, 11, 2021, 23, 58));

    // Operator << and print style: 9-3-2018 5:9 -> 09-03-2018 05:09
    sort(dates.begin(), dates.end());
    cout << "Cout das datas, por ordem crescente:" << endl;
    for (Date date : dates) {
        cout << date;
    }
}