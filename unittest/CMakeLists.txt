include_directories(../include)

add_executable(unittest
        ../src/Lottery.cpp
        ../src/Staff.cpp
        unittest.cpp)

target_link_libraries(unittest gtest gtest_main pthread)

