file(GLOB SOURCES ./*.c)

add_library(array STATIC ${SOURCES})

target_include_directories(array PUBLIC ${CMAKE_CURRENT_LIST_DIR})