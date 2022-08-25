file(GLOB SOURCES ./*.c)

add_library(linked_list STATIC ${SOURCES})

target_include_directories(linked_list PUBLIC ${CMAKE_CURRENT_LIST_DIR})


