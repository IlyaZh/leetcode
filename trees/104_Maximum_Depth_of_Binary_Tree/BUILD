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
      "//trees/104_Maximum_Depth_of_Binary_Tree:main",
      "@gtest//:gtest_main"
    ],
)