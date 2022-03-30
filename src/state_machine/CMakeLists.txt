file(GLOB SOURCES ./*.c)

add_library(state_machine STATIC ${SOURCES})

target_include_directories(state_machine PUBLIC ${CMAKE_CURRENT_LIST_DIR})
