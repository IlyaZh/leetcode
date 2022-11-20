#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, case1) {
  Solution s;
  const auto result = s.isValidSudoku();
  decltype(result) answer{};
  EXPECT_EQ(result, answer);
}
