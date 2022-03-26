add_executable(test_array test_array.c)
add_executable(test_linked_list test_linked_list.c)

target_link_libraries(test_array array unity)
target_link_libraries(test_linked_list linked_list unity)

add_test(array test_array)
add_test(linked_list test_linked_list)