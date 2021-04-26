cmake_minimum_required(VERSION 3.17)
project(Ex3)

set(CMAKE_CXX_STANDARD 20)

add_executable(DEMO
        Demo.cpp
        NumberWithUnits.cpp
        NumberWithUnits.hpp
        Test.cpp
        )
add_executable(TEST
        TestRunner.cpp
        NumberWithUnits.cpp
        NumberWithUnits.hpp
        My_Demo.cpp
        StudentTest1.cpp
        StudentTest2.cpp
        StudentTest3.cpp
        )

add_executable(MY_DEMO My_Demo.cpp
        NumberWithUnits.cpp
        NumberWithUnits.hpp
        TestRunner.cpp
        doctest.h
        )