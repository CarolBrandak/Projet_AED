#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Source/Employee.h"

using testing::Eq;

TEST(Employee, gettersAndSetters) {

    // Getters
    Employee e1 = Employee(1, "Pedro", 20, 'M');
    ASSERT_EQ("Pedro", e1.getName());
    ASSERT_EQ(20, e1.getAge());
    ASSERT_EQ('M', e1.getGender());
    ASSERT_EQ(1, e1.getID());

    // Setters
    e1.setAge(21); e1.setName("Marco");
    ASSERT_EQ(21, e1.getAge());
    ASSERT_EQ("Marco", e1.getName());
}

TEST(Employee, operators) {

    vector<Employee> employees = {};
    Employee e1 = Employee(1, "Pedro", 20, 'M'); employees.push_back(e1);
    Employee e2 = Employee(2, "Carlos", 20 , 'm'); employees.push_back(e2);
    Employee e3 = Employee(3, "Gabriel", 20, 'M'); employees.push_back(e3);
    Employee e4 = Employee(4, "Carolina", 20, 'f'); employees.push_back(e4);
    Employee e5 = Employee(5, "Fabio", 19, 'm'); employees.push_back(e5);

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