#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, zero) {
  Solution s;
  const auto result = s.maxDepth(nullptr);
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}
TEST(SolutionTest, one) {
  Solution s;
  auto tree = new TreeNode(1);
  const auto result = s.maxDepth(tree);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, two) {
  Solution s;
  auto tree = new TreeNode(1, new TreeNode(3), nullptr);
  const auto result = s.maxDepth(tree);
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, three) {
  Solution s;
  auto tree = new TreeNode(3, new TreeNode(9),
                           new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  const auto result = s.maxDepth(tree);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}