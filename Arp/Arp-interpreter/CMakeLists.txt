cmake_minimum_required(VERSION 3.23)
project(Arp_interpreter C)

set(CMAKE_C_STANDARD 99)

add_library(Arp_interpreter library.c)

target_include_directories(${PROJECT_NAME} PRIVATE Arp_language)
target_link_libraries(${PROJECT_NAME} Arp_language)