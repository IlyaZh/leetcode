#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Null) {
  Solution s;
  TreeNode* root = nullptr;
  const auto result = s.isBalanced(root);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, OneNode) {
  Solution s;
  TreeNode* root = new TreeNode(5);
  const auto result = s.isBalanced(root);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, First) {
  Solution s;
  TreeNode* root = new TreeNode(
      3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  const auto result = s.isBalanced(root);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Second) {
  Solution s;
  TreeNode* root = new TreeNode(
      1,
      new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)),
                   new TreeNode(3)),
      new TreeNode(2));
  const auto result = s.isBalanced(root);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}
