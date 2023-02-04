#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.generateParenthesis(3);
  decltype(result) answer{"((()))", "(()())", "(())()", "()(())", "()()()"};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.generateParenthesis(1);
  decltype(result) answer{"()"};
  EXPECT_EQ(result, answer);
}
