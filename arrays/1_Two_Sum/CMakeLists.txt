cmake_minimum_required(VERSION 3.6)
project(solution)

set(CMAKE_CXX_STANDARD 17)


add_executable(
        solution
        main.cpp
        solution.hpp
)

target_compile_features(solution PUBLIC cxx_std_17)
