#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> input = {1, 2, 3, 1};
  const auto result = s.rob(input);
  decltype(result) answer{4};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> input = {2, 7, 9, 3, 1};
  const auto result = s.rob(input);
  decltype(result) answer{12};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> input = {7, 1, 1, 9};
  const auto result = s.rob(input);
  decltype(result) answer{16};
  EXPECT_EQ(result, answer);
}
