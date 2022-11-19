#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  std::vector<int> input = {1, 1, 1, 2, 2, 3};
  const auto result = s.topKFrequent(input, 2);
  decltype(result) answer{1, 2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  std::vector<int> input = {1};
  const auto result = s.topKFrequent(input, 1);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  std::vector<int> input = {1, 2, 3, 4, 4, 4, 5, 5, 7, 9, 9, 9, 9, 9};
  const auto result = s.topKFrequent(input, 1);
  decltype(result) answer{9};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  std::vector<int> input = {1, 2, 3, 4, 4, 4, 5, 5, 7, 9, 9, 9, 9, 9};
  const auto result = s.topKFrequent(input, 2);
  decltype(result) answer{9, 4};
  EXPECT_EQ(result, answer);
}
