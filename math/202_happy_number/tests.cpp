#include <gtest/gtest.h>

#include "solution.hpp"

// first solution
TEST(SolutionTest, Success_number) {
  Solution s;
  const auto result = s.isHappy(19);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Success_one) {
  Solution s;
  const auto result = s.isHappy(1);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Fail) {
  Solution s;
  const auto result = s.isHappy(2);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

// Second solution
TEST(SolutionTest_Set, Success_number) {
  Solution s;
  const auto result = s.isHappySet(19);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest_Set, Success_one) {
  Solution s;
  const auto result = s.isHappySet(1);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest_Set, Fail) {
  Solution s;
  const auto result = s.isHappySet(2);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}