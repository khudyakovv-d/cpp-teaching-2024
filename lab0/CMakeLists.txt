cmake_minimum_required(VERSION 3.22)
project(lab0)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab0 main.cpp module2/module2.cpp)

add_subdirectory(module1)

target_include_directories(lab0 PRIVATE module1 module2)

target_link_libraries(lab0 PRIVATE module1)