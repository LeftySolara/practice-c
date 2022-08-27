file(GLOB SOURCES ./*.c)

add_library(hash_table STATIC ${SOURCES})

target_include_directories(hash_table PUBLIC ${CMAKE_CURRENT_LIST_DIR})


