cmake_minimum_required(VERSION 3.20)

project(Lab4_Variant12_StudentA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(StudentA_Dynamic/StudentA_Dynamic)
add_subdirectory(StudentA_Static/StudentA_Static)
add_subdirectory(Test/Test)
add_subdirectory(TestExplicit)
add_subdirectory(StudentB_MSVC)