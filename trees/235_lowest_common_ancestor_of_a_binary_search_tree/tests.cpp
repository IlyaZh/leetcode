#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  TreeNode* root = new TreeNode(
      6,
      new TreeNode(2, new TreeNode(0),
                   new TreeNode(4, new TreeNode(3), new TreeNode(5))),
      new TreeNode(8, new TreeNode(7), new TreeNode(9)));
  TreeNode* p = new TreeNode(2);
  TreeNode* q = new TreeNode(8);
  const auto result = s.lowestCommonAncestor(root, p, q);
  int answer{6};
  EXPECT_EQ(result->val, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  TreeNode* root = new TreeNode(
      6,
      new TreeNode(2, new TreeNode(0),
                   new TreeNode(4, new TreeNode(3), new TreeNode(5))),
      new TreeNode(8, new TreeNode(7), new TreeNode(9)));
  TreeNode* p = new TreeNode(2);
  TreeNode* q = new TreeNode(4);
  const auto result = s.lowestCommonAncestor(root, p, q);
  int answer{2};
  EXPECT_EQ(result->val, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  TreeNode* root = new TreeNode(2, new TreeNode(1), nullptr);
  TreeNode* p = new TreeNode(2);
  TreeNode* q = new TreeNode(1);
  const auto result = s.lowestCommonAncestor(root, p, q);
  int answer{2};
  EXPECT_EQ(result->val, answer);
}

TEST(SolutionTest, Case4) {
  Solution s;
  TreeNode* root = new TreeNode(
      6,
      new TreeNode(2, new TreeNode(0, nullptr, nullptr),
                   new TreeNode(4, new TreeNode(3), new TreeNode(5))),
      new TreeNode(8, new TreeNode(7), new TreeNode(9)));
  TreeNode* p = new TreeNode(3);
  TreeNode* q = new TreeNode(5);
  const auto result = s.lowestCommonAncestor(root, p, q);
  int answer{4};
  EXPECT_EQ(result->val, answer);
}
