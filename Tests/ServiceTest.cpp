#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Service.h"

using testing::Eq;

TEST(Service, getters) {

    Employee e1 = Employee("1", "Pedro", 20, 'M');
    Employee e2 = Employee("2", "Carlos", 20 , 'm');
    Service s1 = Service("1", "Cleaning", Date(29, 11, 2021, 19, 47), e1);

    // Getters
    ASSERT_EQ("Cleaning", s1.getServiceType());
    ASSERT_EQ(Date(29, 11, 2021, 19, 47), s1.getServiceDate());
    ASSERT_EQ(e1, s1.getResponsible());
    ASSERT_EQ("Pedro", s1.getResponsible().getName());

    // Operator <<
    cout << s1;}