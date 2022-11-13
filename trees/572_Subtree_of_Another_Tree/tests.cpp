#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Successed) {
  Solution s;
  TreeNode* left(new TreeNode(
      3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5)));
  TreeNode* right(new TreeNode(4, new TreeNode(1), new TreeNode(2)));
  const auto result = s.isSubtree(left, right);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Failed) {
  Solution s;
  TreeNode* left(
      new TreeNode(3,
                   new TreeNode(4, new TreeNode(1),
                                new TreeNode(2, new TreeNode(0), nullptr)),
                   new TreeNode(5)));
  TreeNode* right(new TreeNode(4, new TreeNode(1), new TreeNode(2)));
  const auto result = s.isSubtree(left, right);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}
