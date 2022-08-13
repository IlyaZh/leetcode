cmake_minimum_required(VERSION 3.6)
project(solution)


add_executable(
        solution
        main.cpp
        solution.hpp
)
set_property(TARGET solution PROPERTY CXX_STANDARD 20)
target_compile_features(solution PUBLIC cxx_std_20)
