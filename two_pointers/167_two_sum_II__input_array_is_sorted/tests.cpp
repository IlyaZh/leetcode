#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> vec = {2, 7, 11, 15};
  int target = 9;
  const auto result = s.twoSum(vec, target);
  decltype(result) answer{1, 2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> vec = {2, 3, 4};
  int target = 6;
  const auto result = s.twoSum(vec, target);
  decltype(result) answer{1, 3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> vec = {-1, 0};
  int target = -1;
  const auto result = s.twoSum(vec, target);
  decltype(result) answer{1, 2};
  EXPECT_EQ(result, answer);
}
