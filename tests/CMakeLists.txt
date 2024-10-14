add_executable(result_bool_test result_bool_test.c)
target_include_directories(result_bool_test PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_test(NAME result_bool_test COMMAND result_bool_test)
