# cmake_minimum_required(VERSION 3.11)
project(Arp C)

set(CMAKE_C_STANDARD 99)

add_executable(Arp main.c)

add_subdirectory(Arp-language)
target_link_libraries(${PROJECT_NAME} Arp_language)

add_subdirectory(Arp-interpreter)
target_link_libraries(${PROJECT_NAME} Arp_interpreter)