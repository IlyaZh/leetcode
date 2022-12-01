#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  auto input = vector<int>{1, 2, 3};
  const auto result = s.subsets(input);
  vector<vector<int>> answer{{},  {1},    {2},    {1, 2},
                             {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  auto input = vector<int>{0};
  const auto result = s.subsets(input);
  vector<vector<int>> answer{
      {},
      {0},
  };
  EXPECT_EQ(result, answer);
}
