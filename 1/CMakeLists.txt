cmake_minimum_required(VERSION 3.16)

project(section1
  LANGUAGES CXX
)

set(
  CMAKE_CXX_STANDARD 23
  CMAKE_CXX_STANDARD_REQUIRED ON
  CMAKE_CXX_FLAGS "-Wall -O3"
)

add_executable(section1 test.cpp)
