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
      "//two_pointers/11_container_with_most_water:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)