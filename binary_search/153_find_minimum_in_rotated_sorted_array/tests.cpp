#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> nums{3, 4, 5, 1, 2};
  const auto result = s.findMin(nums);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  const auto result = s.findMin(nums);
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> nums{11, 13, 15, 17};
  const auto result = s.findMin(nums);
  decltype(result) answer{11};
  EXPECT_EQ(result, answer);
}
