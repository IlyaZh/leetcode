cmake_minimum_required(VERSION 3.6)
project(tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        tests
        main.cpp
        solution.hpp
)
target_link_libraries(
        tests
        gtest_main
        #MyProg_lib
)

#include_directories(../)

target_compile_features(tests PUBLIC cxx_std_17)
include(GoogleTest)
gtest_discover_tests(tests)
