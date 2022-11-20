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
      "//sliding_window/3_longest_substring_without_repeating_characters:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)