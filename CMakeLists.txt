cmake_minimum_required(VERSION 3.24)
project(csvql)

set(CMAKE_CXX_STANDARD 20)

add_executable(csvql main.cpp Scanner.cpp Scanner.h Token.cpp Token.h)
