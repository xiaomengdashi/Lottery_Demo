include_directories(../include/)

add_executable(main
        main.cpp
        Lottery.cpp
        Staff.cpp
        )
target_link_libraries(main pthread)

