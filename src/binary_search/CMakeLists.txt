file(GLOB SOURCES ./*.c)

add_library(binary_search STATIC ${SOURCES})

target_include_directories(binary_search PUBLIC ${CMAKE_CURRENT_LIST_DIR})


