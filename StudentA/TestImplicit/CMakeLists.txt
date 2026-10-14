
cmake_minimum_required(VERSION 3.20)

project(TestImplicit LANGUAGES CXX)

add_executable(TestImplicit TestImplicit.cpp)

target_include_directories(TestImplicit PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../StudentB_MSVC"
)

target_link_libraries(TestImplicit PRIVATE
    "${CMAKE_BINARY_DIR}/StudentB_MSVC/PermutationDLL.lib"
)
add_custom_command(TARGET TestImplicit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/StudentB_MSVC/PermutationDLL.dll"
        "$<TARGET_FILE_DIR:TestImplicit>"
)
