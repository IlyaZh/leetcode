## 112. Path Sum

[Link](https://leetcode.com/problems/path-sum/)

> Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
> 
> A leaf is a node with no children.


### Complexity
Time: O(n)
Space: O(1)

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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       if (root == nullptr) {
            return false;
        }
        const int remain = targetSum - root->val;
        if(root->left == nullptr && root->right == nullptr) {
            return (sum == 0);
        } 
        return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
    }
};
```
