#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  const auto result = s.dailyTemperatures(input);
  vector<int> answer{1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> input = {30, 40, 50, 60};
  const auto result = s.dailyTemperatures(input);
  vector<int> answer{1, 1, 1, 0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> input = {30, 60, 90};
  const auto result = s.dailyTemperatures(input);
  vector<int> answer{1, 1, 0};
  EXPECT_EQ(result, answer);
}
