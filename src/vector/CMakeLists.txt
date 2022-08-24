file(GLOB SOURCES ./*.c)

add_library(vector STATIC ${SOURCES})

target_include_directories(vector PUBLIC ${CMAKE_CURRENT_LIST_DIR})

