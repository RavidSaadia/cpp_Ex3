cmake_minimum_required(VERSION 3.17)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(DEMO Demo.cpp
        NumberWithUnits.cpp
        NumberWithUnits.hpp
        Test.cpp My_Deme.cpp
        StudentTest1.cpp
        StudentTest2.cpp
        StudentTest3.cpp)

add_executable(TEST TestRunner.cpp
        NumberWithUnits.cpp
        NumberWithUnits.hpp
        Test.cpp My_Deme.cpp
        StudentTest1.cpp
        StudentTest2.cpp
        StudentTest3.cpp)