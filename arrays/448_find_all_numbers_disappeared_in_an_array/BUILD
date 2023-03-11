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
      "//arrays/448_find_all_numbers_disappeared_in_an_array:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)