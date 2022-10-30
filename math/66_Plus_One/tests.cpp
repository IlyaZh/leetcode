#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Zero) {
  Solution s;
  const auto result = s.plusOne(std::vector<int>{0});
  auto answer = std::vector<int>{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, One) {
  Solution s;
  const auto result = s.plusOne(std::vector<int>{1});
  auto answer = std::vector<int>{2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Nine) {
  Solution s;
  const auto result = s.plusOne(std::vector<int>{9});
  auto answer = std::vector<int>{1, 0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, NinetyNine) {
  Solution s;
  const auto result = s.plusOne(std::vector<int>{9, 9});
  auto answer = std::vector<int>{1, 0, 0};
  EXPECT_EQ(result, answer);
}
