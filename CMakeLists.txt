cmake_minimum_required(VERSION 3.20)
project(Projet_AED)
set(CMAKE_CXX_STANDARD 14)

# To run Code, available in "Source"
add_executable(     Projet_AED main.cpp
                    Source/Employee.cpp Source/Employee.h
                    Source/Luggage.cpp Source/Luggage.h
                    Source/Passenger.cpp Source/Person.h
                    Source/Person.cpp Source/Person.h
                    Source/Date.cpp Source/Date.h
                    Source/Person.cpp Source/Person.h
                    Source/Plane.h Source/Plane.cpp
                    Source/Flight.h Source/Flight.cpp
                    Source/Service.h Source/Service.cpp
                    Source/Company.h Source/Company.cpp
                    Source/Airport.cpp Source/Airport.cpp
                    Source/Transport.cpp Source/Transport.cpp
                    Source/Menu.h Source/Menu.cpp
                    Source/BST.h
                    Tests/DateTest.cpp
                    Tests/LuggageTest.cpp
                    Tests/EmployeeTest.cpp
                    Tests/PassengerTest.cpp
                    Tests/ServiceTest.cpp Source/Exceptions.cpp Source/Exceptions.h Source/Utilities.cpp Source/Utilities.h Source/Cart.cpp Source/Cart.h)

#To run Tests, available in "Tests"
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(Projet_AED gtest gtest_main)

# To run Doxygen, available in "Documentation"
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/Documentation")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Documentation/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)