#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  auto input = vector<int>{-2, 0, 3, -5, 2, -1};
  NumArray s(input);
  EXPECT_EQ(s.sumRange(0, 2), 1);
  EXPECT_EQ(s.sumRange(2, 5), -1);
  EXPECT_EQ(s.sumRange(0, 5), -3);
}
