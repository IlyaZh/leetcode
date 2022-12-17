#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.longestCommonSubsequence("abcde", "ace");
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.longestCommonSubsequence("abc", "abc");
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.longestCommonSubsequence("abc", "def");
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  const auto result = s.longestCommonSubsequence("ezupkr", "ubmrapg");
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}
