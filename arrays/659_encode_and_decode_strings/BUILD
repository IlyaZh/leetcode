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
      "//arrays/659_encode_and_decode_strings:main",
      "@gtest//:gtest_main"
    ],
  copts=["--std=c++2a"],
)