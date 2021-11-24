# To run Code, available in "Source"
cmake_minimum_required(VERSION 3.20)
project(Projet_AED)
set(CMAKE_CXX_STANDARD 14)

# To run Tests, available in "Tests"
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_executable(Projet_AED main.cpp Source/FirstClass.cpp Tests/FirstClassTest.cpp) # add files as we take tests and classes
target_link_libraries(Projet_AED gtest gtest_main)

# To run Doxygen, available in "docs"