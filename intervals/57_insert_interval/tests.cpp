#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<vector<int>> input{{1, 3}, {6, 9}};
  vector<int> new_interval{2, 5};
  const auto result = s.insert(input, new_interval);
  decltype(result) answer{{1, 5}, {6, 9}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<vector<int>> input{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> new_interval{4, 8};
  const auto result = s.insert(input, new_interval);
  decltype(result) answer{{1, 2}, {3, 10}, {12, 16}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<vector<int>> input{{1, 3}, {6, 9}};
  vector<int> new_interval{10, 11};
  const auto result = s.insert(input, new_interval);
  decltype(result) answer{{1, 3}, {6, 9}, {10, 11}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  vector<vector<int>> input{{6, 9}, {10, 11}};
  vector<int> new_interval{1, 3};
  const auto result = s.insert(input, new_interval);
  decltype(result) answer{{1, 3}, {6, 9}, {10, 11}};
  EXPECT_EQ(result, answer);
}