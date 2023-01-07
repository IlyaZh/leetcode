cc_binary(
  name="main",
  srcs=["main.cpp", "solution.hpp"],
  deps=["//libs:common"],
  visibility = ["//visibility:public"],
  copts=["--std=c++2a"],
)

cc_test(
  name = "tests",
  srcs = ["tests.cpp"],
  deps = [
      "//bit_manipulations/371_sum_of_two_integers:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)