#include <gtest/gtest.h>

#include <algorithm>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<vector<int>> input = {{1, 3}, {-2, 2}};
  const auto result = s.kClosest(input, 1);
  decltype(result) answer{{-2, 2}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<vector<int>> input = {{3, 3}, {5, -1}, {-2, 4}};
  const auto result = s.kClosest(input, 2);
  decltype(result) answer{{3, 3}, {-2, 4}};
  EXPECT_EQ(result, answer);
}
