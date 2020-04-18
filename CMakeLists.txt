cmake_minimum_required(VERSION 3.15)
project(Lottery_Demo)

set(CMAKE_CXX_STANDARD 14)

#头文件目录
include_directories(
        ./include/
        /usr/local/include/
)

#链接库目录
link_directories(
        /usr/local/lib/
)

add_subdirectory(src)
add_subdirectory(unittest)