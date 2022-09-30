project(test)
find_package(MyLib)

add_executable(test main.cpp)

target_link_libraries(test MyLib::mylib)