cmake_minimum_required(VERSION 3.22)
project(untitled60)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.c lexer.c parser.c lang.c lib.c)
