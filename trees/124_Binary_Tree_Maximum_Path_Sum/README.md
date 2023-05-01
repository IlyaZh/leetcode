## 124. Binary Tree Maximum Path Sum

[Link](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

### Condition
>A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
>
>The path sum of a path is the sum of the node's values in the path.
>
>Given the root of a binary tree, return the maximum path sum of any non-empty path.

### Complexity
Time: O(n)
Space: O(n)

### Solving
> Every node calculate DFS for each node and take a maximum between 0 and Dfs(child). Store to global_max variable maximum value between global_max and root->val + left_node_dfs + right_node_dfs. Dfs method should be return root->val + std::max(left_node_dfs, right_node_dfs);
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
    int max_sum_{};
    int Dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        auto left = std::max(0, Dfs(root->left));
        auto right = std::max(0, Dfs(root->right));
        max_sum_ = std::max(max_sum_, root->val + left + right);
        return root->val + std::max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        max_sum_ = INT_MIN;
        Dfs(root);
        return max_sum_;
    }
};
```
