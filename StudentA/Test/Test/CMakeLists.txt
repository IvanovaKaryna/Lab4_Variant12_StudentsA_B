
cmake_minimum_required(VERSION 3.20)

add_executable(Test Test.cpp)

target_link_libraries(Test PRIVATE StudentA_Dynamic)

add_custom_command(TARGET Test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/StudentA_SDK/bin/StudentA_Dynamic.dll"
        "$<TARGET_FILE_DIR:Test>"
)
