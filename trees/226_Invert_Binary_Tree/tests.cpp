#include <gtest/gtest.h>

#include <vector>

#include "solution.hpp"

void parse(std::vector<int>& vec, TreeNode* node) {
  if (node == nullptr) return;
  parse(vec, node->left);
  vec.push_back(node->val);
  parse(vec, node->right);
}

bool is_same(TreeNode* lhs, TreeNode* rhs) {
  std::vector<int> left;
  std::vector<int> right;

  parse(left, lhs);
  parse(right, rhs);

  return left == right;
}

TEST(SolutionTest, check_nullptr) {
  Solution s;
  const auto result = s.invertTree(nullptr);
  decltype(result) answer{nullptr};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, check_one_element) {
  Solution s;
  auto tree = new TreeNode(1);
  const auto result = s.invertTree(tree);
  EXPECT_EQ(result, tree);
}

TEST(SolutionTest, check_mirroring) {
  Solution s;
  auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                           new TreeNode(3, new TreeNode(6), nullptr));
  auto mirrored_tree =
      new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(6)),
                   new TreeNode(2, new TreeNode(5), new TreeNode(4)));
  const auto result = s.invertTree(tree);
  EXPECT_TRUE(is_same(result, mirrored_tree));
}