cmake_minimum_required(VERSION 3.17)

project(enigma)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(enigma main.cpp source/Enigma.cpp)