#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.getSum(1, 2);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.getSum(2, 3);
  decltype(result) answer{5};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.getSum(-1, 1);
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}
