#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  auto input = vector<int>{2, 2, 1};
  const auto result = s.singleNumber(input);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  auto input = vector<int>{4, 1, 2, 1, 2};
  const auto result = s.singleNumber(input);
  decltype(result) answer{4};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  auto input = vector<int>{1};
  const auto result = s.singleNumber(input);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}
