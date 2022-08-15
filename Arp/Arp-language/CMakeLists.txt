cmake_minimum_required(VERSION 3.23)
project(Arp_language C)

set(CMAKE_C_STANDARD 99)

file(
        GLOB_RECURSE
        SOURCE_FILES
        *.c
)

add_library(Arp_language Library.c)