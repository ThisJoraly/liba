cmake_minimum_required(VERSION 3.26)
project(liba)

set(CMAKE_CXX_STANDARD 17)

add_library(liba library.cpp
        src/main.cpp
        Library/Stream.cpp
        DLL/poop.cpp)
