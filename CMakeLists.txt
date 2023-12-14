cmake_minimum_required(VERSION 3.0)

project(vectorlib)

add_executable(vectorlib main.cpp)

install(TARGETS vectorlib RUNTIME DESTINATION bin)
