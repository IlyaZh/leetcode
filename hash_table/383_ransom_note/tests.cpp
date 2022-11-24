#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.canConstruct("a", "b");
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.canConstruct("inter", "interstellar");
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.canConstruct("aa", "ab");
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  const auto result = s.canConstruct("aa", "aba");
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}
