cmake_minimum_required(VERSION 3.15)
project(Lottery_Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lottery_Demo
        Lottery.cpp
        Lottery.h
        main.cpp
        Staff.cpp
        Staff.h
        test.cpp
        unittest.cpp)
