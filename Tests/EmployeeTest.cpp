#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Employee.h"

using testing::Eq;

TEST(Employee, getters) {

    // Getters
    Employee e1 = Employee("Pedro", 20, 'M');
    ASSERT_EQ("Pedro", e1.getName());
    ASSERT_EQ(20, e1.getAge());
    ASSERT_EQ('M', e1.getGender());

}

TEST(Employee, operators) {

    vector<Employee> employees = {};
    Employee e1 = Employee("Pedro", 20, 'M'); employees.push_back(e1);
    Employee e2 = Employee("Carlos", 20 , 'm'); employees.push_back(e2);
    Employee e3 = Employee("Gabriel", 20, 'M'); employees.push_back(e3);
    Employee e4 = Employee("Carolina", 20, 'f'); employees.push_back(e4);
    Employee e5 = Employee("Fabio", 19, 'm'); employees.push_back(e5);

    // Equality, ==
    ASSERT_EQ(false, e1 == e4);
    ASSERT_EQ(false, e2 == e1);

    // Operator <
    sort(employees.begin(), employees.end());
    ASSERT_EQ(employees[0], e5);
    ASSERT_EQ(employees[1], e2);
    ASSERT_EQ(employees[2], e4);
    ASSERT_EQ(employees[3], e3);
    ASSERT_EQ(employees[4], e1);

    // Operator <<
    cout << "Cout dos funcionários, por ordem crescente:" << endl;
    for (Employee employee : employees) {
        cout << employee;
    }
}