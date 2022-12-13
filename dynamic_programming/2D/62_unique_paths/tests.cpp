#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.uniquePaths(3, 7);
  decltype(result) answer{28};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.uniquePaths(3, 2);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}
