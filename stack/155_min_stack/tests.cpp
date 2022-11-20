#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  MinStack s;
  s.push(-2);
  s.push(0);
  s.push(-3);
  EXPECT_EQ(s.getMin(), -3);
  s.pop();
  EXPECT_EQ(s.top(), 0);
  EXPECT_EQ(s.getMin(), -2);
}
