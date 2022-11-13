// https://leetcode.com/problems/subtree-of-another-tree/

// 572. Subtree of Another Tree

// Given the roots of two binary trees root and subRoot, return true if there is
// a subtree of root with the same structure and node values of subRoot and
// false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and
// all of this node's descendants. The tree tree could also be considered as a
// subtree of itself.

// Example 1:
// Input: root = [3,4,5,1,2], subRoot = [4,1,2]
// Output: true

// Example 2:
// Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
// Output: false

// Constraints:
// The number of nodes in the root tree is in the range [1, 2000].
// The number of nodes in the subRoot tree is in the range [1, 1000].
// -104 <= root.val <= 104
// -104 <= subRoot.val <= 104

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
  bool IsIdentical(TreeNode* lhs, TreeNode* rhs) {
    if (lhs == nullptr || rhs == nullptr) {
      return lhs == nullptr && rhs == nullptr;
    }
    return lhs->val == rhs->val && IsIdentical(lhs->left, rhs->left) &&
           IsIdentical(lhs->right, rhs->right);
  }

 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
      return false;
    }
    if (IsIdentical(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
