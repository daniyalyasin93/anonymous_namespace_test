cmake_minimum_required(VERSION 3.19)
project(test)

execute_process(COMMAND ${CMAKE_COMMAND}
-G "${CMAKE_GENERATOR}"
-A "${CMAKE_GENERATOR_PLATFORM}"
-T "${CMAKE_GENERATOR_TOOLSET}"
${CMAKE_CURRENT_LIST_DIR}/secondlib
WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/secondlib/build")

execute_process(COMMAND ${CMAKE_COMMAND}
        --build .
        --config ${CMAKE_BUILD_TYPE}
        --target install
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/secondlib/build")

find_package(MyLib PATHS ${CMAKE_CURRENT_LIST_DIR}/secondlib/install/lib/cmake/MyLib)

add_executable(test main.cpp)

target_link_libraries(test MyLib::mylib)