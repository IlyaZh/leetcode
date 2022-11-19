#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  std::vector<int> input = {-1, 0, 1, 2, -1, -4};
  const auto result = s.threeSum(input);
  decltype(result) answer{{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  std::vector<int> input = {0, 1, 1};
  const auto result = s.threeSum(input);
  decltype(result) answer{};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  std::vector<int> input = {0, 0, 0};
  const auto result = s.threeSum(input);
  decltype(result) answer{{0, 0, 0}};
  EXPECT_EQ(result, answer);
}
