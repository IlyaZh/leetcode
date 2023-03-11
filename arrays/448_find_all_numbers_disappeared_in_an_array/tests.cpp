#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  auto input = vector<int>{4, 3, 2, 7, 8, 2, 3, 1};
  const auto result = s.findDisappearedNumbers(input);
  decltype(result) answer{5, 6};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  auto input = vector<int>{1, 1};
  const auto result = s.findDisappearedNumbers(input);
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}
