
add_executable(TestExplicit TestExplicit.cpp)

add_custom_command(TARGET TestExplicit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_LIST_DIR}/../StudentB_SDK/bin/PermutationDLL.dll"
        "$<TARGET_FILE_DIR:TestExplicit>"
)
