cmake_minimum_required(VERSION 3.21)
project(Program8)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program8 main.cpp Rational.cpp Rational.h DividedByZeroException.h)
