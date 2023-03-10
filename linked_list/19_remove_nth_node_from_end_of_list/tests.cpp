#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  auto list = libs::list_nodes::Parse({1, 2, 3, 4, 5});
  const auto result = libs::list_nodes::ToVector(s.removeNthFromEnd(list, 2));
  decltype(result) answer{vector<int>{1, 2, 3, 5}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  auto list = libs::list_nodes::Parse({1});
  const auto result = libs::list_nodes::ToVector(s.removeNthFromEnd(list, 1));
  decltype(result) answer{vector<int>{}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  auto list = libs::list_nodes::Parse({1, 2});
  const auto result = libs::list_nodes::ToVector(s.removeNthFromEnd(list, 1));
  decltype(result) answer{vector<int>{1}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  auto list = libs::list_nodes::Parse({1, 2});
  const auto result = libs::list_nodes::ToVector(s.removeNthFromEnd(list, 2));
  decltype(result) answer{vector<int>{2}};
  EXPECT_EQ(result, answer);
}
