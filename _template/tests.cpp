#include <gtest/gtest.h>

#include "solution.hpp"

// Demonstrate some basic assertions.
TEST(SolutionTest, BasicAssertions) {
  Solution s;
  const auto result = s.func();
  decltype(result) answer{};
  EXPECT_EQ(result, answer);
}