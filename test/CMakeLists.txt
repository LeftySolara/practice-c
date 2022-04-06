add_executable(test_array test_array.c)
add_executable(test_linked_list test_linked_list.c)
add_executable(test_queue_ll test_queue_ll.c)

target_link_libraries(test_array array unity)
target_link_libraries(test_linked_list linked_list unity)
target_link_libraries(test_queue_ll queue_ll unity)

add_test(array test_array)
add_test(linked_list test_linked_list)
add_test(queue_ll, test_queue_ll)