cmake_minimum_required(VERSION 3.19)
project(test)

execute_process(COMMAND ${CMAKE_COMMAND}
        -G "${CMAKE_GENERATOR}"
        -A "${CMAKE_GENERATOR_PLATFORM}"
        -T "${CMAKE_GENERATOR_TOOLSET}"
        -B ${CMAKE_CURRENT_LIST_DIR}/secondlib/build
        -S ${CMAKE_CURRENT_LIST_DIR}/secondlib)

execute_process(COMMAND ${CMAKE_COMMAND}
        --build ${CMAKE_CURRENT_LIST_DIR}/secondlib/build
        --target install
        COMMAND_ECHO STDOUT)

find_package(MyLib PATHS ${CMAKE_CURRENT_LIST_DIR}/secondlib/install/lib/cmake/MyLib)

add_executable(test main.cpp)

target_link_libraries(test MyLib::mylib)