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
      "//trees/572_Subtree_of_Another_Tree:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)