cmake_minimum_required(VERSION 3.6)

project(MyApp)

enable_language(CXX)

enable_testing()

set(SOURCES "solution.cpp" "solution.h")

add_subdirectory(tests)
add_executable(MyProg main.cpp)
add_library(MyProg_lib STATIC ${SOURCES})

target_compile_features(MyProg PUBLIC cxx_std_17)
target_compile_features(MyProg_lib PUBLIC cxx_std_17)
