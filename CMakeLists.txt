cmake_minimum_required(VERSION 3.15)
project(Lottery)

set(CMAKE_CXX_STANDARD 11)

add_executable(Lottery main.cpp Staff.cpp Staff.h Lottery.cpp Lottery.h test.cpp unittest.cpp)