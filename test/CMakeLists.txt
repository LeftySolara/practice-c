add_executable(test_hello_world test_hello_world.c)

target_link_libraries(test_hello_world hello_world unity)

add_test(hello_world test_hello_world)
