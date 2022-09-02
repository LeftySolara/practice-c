file(GLOB SOURCES ./*.c)

add_library(binary_tree STATIC ${SOURCES})

target_include_directories(binary_tree PUBLIC ${CMAKE_CURRENT_LIST_DIR})



