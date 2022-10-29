#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, BasicAssertions) {
  Solution s;
  const auto result = s.func();
  decltype(result) answer{};
  EXPECT_EQ(result, answer);
}
