#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{6};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> input = {1};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> input = {5,4,-1,7,8};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{23};
  EXPECT_EQ(result, answer);
}
