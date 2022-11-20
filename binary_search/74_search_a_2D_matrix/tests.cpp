#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  const auto target = 3;
  const auto result = s.searchMatrix(matrix, target);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  const auto target = 13;
  const auto result = s.searchMatrix(matrix, target);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}
