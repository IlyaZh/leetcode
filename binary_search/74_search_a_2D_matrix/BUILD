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
      "//binary_search/74_search_a_2D_matrix:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)