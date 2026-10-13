cmake_minimum_required(VERSION 3.20)
project(PartnerExplicit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../PartnerSDK_GCC")

add_executable(PartnerExplicit main.cpp)

add_custom_command(TARGET PartnerExplicit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDK_DIR}/bin/StudentA_Dynamic.dll"
    "$<TARGET_FILE_DIR:PartnerExplicit>"
)
