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
      "//arrays/238_product_of_array_except_self:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)