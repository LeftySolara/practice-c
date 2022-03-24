add_executable(test_array test_array.c)

target_link_libraries(test_array array unity)

add_test(array test_array)