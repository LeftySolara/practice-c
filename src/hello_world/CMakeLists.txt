file(GLOB SOURCES ./*.c)

add_library(hello_world STATIC ${SOURCES})

target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_LIST_DIR})
