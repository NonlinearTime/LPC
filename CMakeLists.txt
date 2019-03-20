cmake_minimum_required(VERSION 3.12)
project(LPC)

set(CMAKE_CXX_STANDARD 14)

add_executable(LPC main.cpp lpc.cpp lpc.h)