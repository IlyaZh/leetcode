#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.lengthOfLongestSubstring("abcabcbb"s);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.lengthOfLongestSubstring("bbbbb"s);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.lengthOfLongestSubstring("pwwkew"s);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  const auto result = s.lengthOfLongestSubstring("aaaaabcdefgaaaa"s);
  decltype(result) answer{7};
  EXPECT_EQ(result, answer);
}
