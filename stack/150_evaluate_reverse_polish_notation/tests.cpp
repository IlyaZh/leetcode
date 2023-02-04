#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  vector<string> input = {"2", "1", "+", "3", "*"};
  const auto result = s.evalRPN(input);
  decltype(result) answer{9};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  vector<string> input = {"4", "13", "5", "/", "+"};
  const auto result = s.evalRPN(input);
  decltype(result) answer{6};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  vector<string> input = {"10", "6", "9",  "3", "+", "-11", "*",
                          "/",  "*", "17", "+", "5", "+"};
  const auto result = s.evalRPN(input);
  decltype(result) answer{22};
  EXPECT_EQ(result, answer);
}
