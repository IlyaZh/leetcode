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
      "//heap/973_K_closest_points_to_origin:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)