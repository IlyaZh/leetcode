#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> input{1, 8, 6, 2, 5, 4, 8, 3, 7};
  const auto result = s.maxArea(input);
  decltype(result) answer{49};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> input{1, 1};
  const auto result = s.maxArea(input);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}
