add_library(StudentA_Dynamic SHARED
    StudentA_Dynamic.cpp
    StudentA_Dynamic.h
)

target_compile_definitions(StudentA_Dynamic PRIVATE STUDENTA_DYNAMIC_EXPORTS)

target_include_directories(StudentA_Dynamic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(StudentA_Dynamic PUBLIC cxx_std_20)