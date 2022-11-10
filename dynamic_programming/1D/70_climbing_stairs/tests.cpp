#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Stairs_1) {
  Solution s;
  const auto result = s.climbStairs(1);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Stairs_2) {
  Solution s;
  const auto result = s.climbStairs(2);
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Stairs_3) {
  Solution s;
  const auto result = s.climbStairs(3);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Stairs_4) {
  Solution s;
  const auto result = s.climbStairs(4);
  decltype(result) answer{5};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Stairs_5) {
  Solution s;
  const auto result = s.climbStairs(5);
  decltype(result) answer{8};
  EXPECT_EQ(result, answer);
}
