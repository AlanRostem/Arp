cmake_minimum_required(VERSION 3.23)
project(Arp C)

set(CMAKE_C_STANDARD 99)

add_executable(Arp main.c Arp-language/library.c Arp-language/library.h)

add_subdirectory(Arp-language)
target_link_libraries(${PROJECT_NAME} Arp_language)