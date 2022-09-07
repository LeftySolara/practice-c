file(GLOB SOURCES ./*.c)

add_library(priority_queue STATIC ${SOURCES})

target_include_directories(priority_queue PUBLIC ${CMAKE_CURRENT_LIST_DIR})



