#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.rotate(matrix);
  decltype(matrix) answer{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  EXPECT_EQ(matrix, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<vector<int>> matrix{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(matrix);
  decltype(matrix) answer{
      {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
  EXPECT_EQ(matrix, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<vector<int>> matrix{{1, 2}, {3, 4}};
  s.rotate(matrix);
  decltype(matrix) answer{{3, 1}, {4, 2}};
  EXPECT_EQ(matrix, answer);
}