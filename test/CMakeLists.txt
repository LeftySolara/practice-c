add_executable(test_hello_world test_hello_world.c)
add_executable(test_linked_list test_linked_list.c)
add_executable(test_vector test_vector.c)

target_link_libraries(test_hello_world hello_world unity)
target_link_libraries(test_linked_list linked_list unity)
target_link_libraries(test_vector vector unity)

add_test(hello_world test_hello_world)
add_test(linked_list test_linked_list)
add_test(vector test_vector)