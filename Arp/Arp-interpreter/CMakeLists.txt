cmake_minimum_required(VERSION 3.23)
project(Arp_interpreter C)

set(CMAKE_C_STANDARD 99)

file(
        GLOB_RECURSE
        SOURCE_FILES
        *.c
)

add_subdirectory(../dependencies/pcre2 ../dependencies/../pcre2/cmake-build-debug)

add_library(Arp_interpreter Library.c)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC Arp_language
        PRIVATE ../dependencies/pcre2/src
)
target_link_libraries(${PROJECT_NAME} Arp_language)