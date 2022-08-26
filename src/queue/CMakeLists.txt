file(GLOB SOURCES ./*.c)

add_library(queue_ll STATIC ${SOURCES})

target_include_directories(queue_ll PUBLIC ${CMAKE_CURRENT_LIST_DIR})



