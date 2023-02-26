#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<int> piles = {3, 6, 7, 11};
  const auto result = s.minEatingSpeed(piles, 8);
  decltype(result) answer{4};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<int> piles = {30, 11, 23, 4, 20};
  const auto result = s.minEatingSpeed(piles, 5);
  decltype(result) answer{30};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<int> piles = {30, 11, 23, 4, 20};
  const auto result = s.minEatingSpeed(piles, 6);
  decltype(result) answer{23};
  EXPECT_EQ(result, answer);
}