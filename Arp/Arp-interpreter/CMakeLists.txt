cmake_minimum_required(VERSION 3.23)
project(Arp_interpreter C)

set(CMAKE_C_STANDARD 99)

file(
        GLOB_RECURSE
        SOURCE_FILES
        *.c
)

add_subdirectory(../dependencies/pcre2 dependencies/pcre2)

add_library(Arp_interpreter Library.c)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC ../
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/dependencies/pcre2
)

target_link_libraries(${PROJECT_NAME} Arp_language)
target_link_libraries(${PROJECT_NAME} PCRE2)