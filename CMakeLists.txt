cmake_minimum_required(VERSION 3.24)
project(InspectorGadget)

set(CMAKE_CXX_STANDARD 23)

add_executable(InspectorGadget main.cpp memory.hpp computer.hpp storage.hpp)
