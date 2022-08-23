cmake_minimum_required(VERSION 3.12)

project(
  "practice-c"
  LANGUAGES C
  VERSION 0.1
)

set (CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)

include(CTest)

add_subdirectory(unity)
add_subdirectory(test)
