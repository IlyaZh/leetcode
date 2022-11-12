// https://leetcode.com/problems/diameter-of-binary-tree/

// 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the
// tree.

// The diameter of a binary tree is the length of the longest path between any
// two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges
// between them.

// Example 1:
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

// Example 2:
// Input: root = [1,2]
// Output: 1

// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -100 <= Node.val <= 100

#include <memory>

struct TreeNode {
  int val;
  std::shared_ptr<TreeNode> left;
  std::shared_ptr<TreeNode> right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, std::shared_ptr<TreeNode> left,
           std::shared_ptr<TreeNode> right)
      : val(x), left(left), right(right) {}
};

class Solution {
  int max_diameter = 0;
  int max_depth(std::shared_ptr<TreeNode> node) {
    if (!node) return 0;
    const auto left = max_depth(node->left);
    const auto right = max_depth(node->right);
    max_diameter = std::max(max_diameter, left + right);
    return 1 + std::max(left, right);
  }

 public:
  int diameterOfBinaryTree(std::shared_ptr<TreeNode> root) {
    max_depth(root);
    return max_diameter;
  }
};
