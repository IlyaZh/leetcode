#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  string str = "ABAB";
  const auto result = s.characterReplacement(str, 2);
  decltype(result) answer{4};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  string str = "AABABBA";
  const auto result = s.characterReplacement(str, 1);
  decltype(result) answer{4};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  string str = "ACBABCA";
  const auto result = s.characterReplacement(str, 1);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  string str = "ACB";
  const auto result = s.characterReplacement(str, 1);
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}
