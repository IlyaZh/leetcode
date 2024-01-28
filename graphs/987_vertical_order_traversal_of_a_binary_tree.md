# 987. Vertical Order Traversal of a Binary Tree [Hard]

[Leetcode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)

## Task

> Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

> For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
> 
> The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
> 
> Return the vertical order traversal of the binary tree.

## Complexity

Time: O(n)
Space: O(n)

## Solution

Create hash map for column and as a key use another hash map with row as a column and value is sorted list of values. Go though graph using DFS algorithm. Put values to hash table by col-row-values. Then tranform map to list of lists by iteration from columns and rows ASC. If at the same row-col has more than one value, put them in ASC order

```c++
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
    using Col = int;
    using Row = int;
    using Value = int;

    map<Col, map<Row, multiset<Value>>> m;
public:
    void Dfs(TreeNode* root, Row row, Col col) {
        if (!root) {
            return;
        }
        if (!m.contains(col)) {
            m[col] = {};
        }
        if(!m[col].contains(row)) {
            m[col][row] = {};
        }
        m[col][row].insert(root->val);

        Dfs(root->left, row+1, col-1);
        Dfs(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        m.clear();

        Dfs(root, 0, 0);

        vector<vector<int>> result;
        result.reserve(m.size());
        for(const auto& [col, rows] : m) {
            vector<int> result_row;
            result_row.reserve(rows.size());
            for(const auto& [_, v] : rows) {
                for(const auto& v2 : v) {
                    result_row.push_back(v2);
                }
            }
            result.push_back(std::move(result_row));
        }
        
        return result;
    }
};
```