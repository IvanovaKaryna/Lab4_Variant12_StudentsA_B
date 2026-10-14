
cmake_minimum_required(VERSION 3.10)

project(StudentA_Static LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(StudentA_Static STATIC
    combinatorics.cpp
)

add_executable(TestStatic main.cpp)

target_link_libraries(TestStatic PRIVATE StudentA_Static)
