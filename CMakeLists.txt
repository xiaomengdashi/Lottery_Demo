cmake_minimum_required(VERSION 3.15)
project(Lottery_Demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

#头文件目录
include_directories(
        /usr/local/include/
)

#链接库目录
link_directories(
        /usr/local/lib/
)

add_executable(Lottery_Demo
    Lottery.cpp
    Lottery.h
    main.cpp
    Staff.cpp
    Staff.h
    test.cpp
    unittest.cpp)

target_link_libraries(Lottery_Demo gtest gtest_main pthread)

