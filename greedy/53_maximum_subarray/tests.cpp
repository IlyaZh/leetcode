#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{6};
  EXPECT_EQ(result, answer);
}
// 0, -2, -1, -4, 0, -1, 1, 2, -3, 1 = 2-(-4) = 6

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> input = {1};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}
// 0, 1 = 1 - 0  = 1

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> input = {5, 4, -1, 7, 8};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{23};
  EXPECT_EQ(result, answer);
}  // 0, 5, 9, 8, 15, 23 = 23-0 = 23

TEST(SolutionTest, Case4) {
  Solution s;
  vector<int> input = {-4, 26, -5};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{26};
  EXPECT_EQ(result, answer);
}  // 0, -4, 22, 17 = 22-(-4) = 26

TEST(SolutionTest, Case5) {
  Solution s;
  vector<int> input = {1, 2, 3};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{6};
  EXPECT_EQ(result, answer);
}  // 0, 1, 3, 6 = 6 - 0 = 6

TEST(SolutionTest, Case6) {
  Solution s;
  vector<int> input = {-4, 2, 3};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{5};
  EXPECT_EQ(result, answer);
}  // 0, -4, -2, 1 = 1 - (-4) = 5

TEST(SolutionTest, Case7) {
  Solution s;
  vector<int> input = {-1};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{-1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case8) {
  Solution s;
  vector<int> input = {-2, -3};
  const auto result = s.maxSubArray(input);
  decltype(result) answer{-2};
  EXPECT_EQ(result, answer);
}
