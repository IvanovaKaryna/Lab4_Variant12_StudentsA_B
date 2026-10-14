
cmake_minimum_required(VERSION 3.20)

project(StudentB_MSVC LANGUAGES CXX)

add_library(PermutationDLL SHARED
    PermutationLib.cpp
)

target_compile_definitions(PermutationDLL PRIVATE PERMUTATION_BUILD)

target_include_directories(PermutationDLL PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(PermutationDLL PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
