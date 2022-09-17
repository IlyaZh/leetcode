cc_binary(
  name="main",
  srcs=["main.cpp", "solution.hpp"],
  deps=["//libs:common"],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "tests",
  srcs = ["tests.cpp"],
  deps = [
      "//_template:main",
      "@gtest//:gtest_main"
    ],
)