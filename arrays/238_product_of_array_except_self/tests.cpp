#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  std::vector<int> input{1, 2, 3, 4};
  const auto result = s.productExceptSelf(input);
  decltype(result) answer{24, 12, 8, 6};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  std::vector<int> input{-1, 1, 0, -3, 3};
  const auto result = s.productExceptSelf(input);
  decltype(result) answer{0, 0, 9, 0, 0};
  EXPECT_EQ(result, answer);
}
