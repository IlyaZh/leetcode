#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.countBits(2);
  std::vector<int> answer{{0, 1, 1}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.countBits(5);
  std::vector<int> answer{{0, 1, 1, 2, 1, 2}};
  EXPECT_EQ(result, answer);
}
