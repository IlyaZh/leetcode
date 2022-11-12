// https://leetcode.com/problems/balanced-binary-tree/

// 110. Balanced Binary Tree

// Given a binary tree, determine if it is
// height-balanced

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

#include <cmath>
#include <optional>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  std::optional<int> depth(TreeNode *node) {
    if (!node) return 0;
    const auto left = depth(node->left);
    if (!left) {
      return std::nullopt;
    }
    const auto right = depth(node->right);
    if (!right) {
      return std::nullopt;
    }
    if (abs(left.value() - right.value()) > 1) {
      return std::nullopt;
    }
    return 1 + std::max(left.value(), right.value());
  }

 public:
  bool isBalanced(TreeNode *root) { return depth(root).has_value(); }
};
