cmake_minimum_required (VERSION 2.6)

project (fauxels)

file(GLOB sources *.cpp)

add_executable(fauxels ${sources})
