## 113. Path Sum II

[Link](https://leetcode.com/problems/path-sum-ii/)

### Condition
>Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
>
>A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

### Complexity
Time: O(n)
Space: O(n)

### Solving
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  vector<vector<int>> result;
  void calculate(TreeNode* root, int targetSum, const vector<int>& vec) {
    if(root == nullptr) {
      return;
    }
    const auto remain = targetSum - root->val;
    auto new_vec = vec;
    new_vec.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr) {
      if(remain == 0) {
        result.emplace_back(std::move(new_vec));
      }
      return;
    }
    calculate(root->left, remain, new_vec);
    calculate(root->right, remain, new_vec);
  }
 public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    result.clear();
    vector<int> vec;
    calculate(root, targetSum, vec);
    return result;
  }
};
```
