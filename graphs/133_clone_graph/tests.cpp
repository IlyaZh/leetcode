#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.cloneGraph(nullptr);
  decltype(result) answer{};
  EXPECT_EQ(result, answer);
}
