#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Service.h"

using testing::Eq;

TEST(Service, gettersAndSetters) {

    Employee e1 = Employee("Pedro", 20, 'M', "FEUP2021");
    Employee e2 = Employee("Carlos", 20 , 'm', "ISCTE21");
    Service s1 = Service("Cleaning", Date(29, 11, 2021, 19, 47), e1);

    // Getters
    ASSERT_EQ("Cleaning", s1.getServiceType());
    ASSERT_EQ(Date(29, 11, 2021, 19, 47), s1.getServiceDate());
    ASSERT_EQ(e1, s1.getResponsible());
    ASSERT_EQ("Pedro", s1.getResponsible().getName());

    // Setters
    s1.setResponsible(e2);

    // Na realidade este comando não modifica o nome do funcionário, mas deveria :(
    s1.getResponsible().setName("Joana");
    cout << s1.getResponsible().getName();

    ASSERT_EQ(e2, s1.getResponsible());
    ASSERT_EQ("Joana", s1.getResponsible().getName());

    // Operator <<
    cout << s1;
    cout << s1.getResponsible();
}