cmake_minimum_required(VERSION 3.22)
project(CS2205_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CS2205_Project
        lang.c
        lang.h
        lexer.c
        lexer.h
        lib.c
        lib.h
        main.c
        parser.c
        parser.h)
