# 230. Kth Smallest Element in a BST [Medium]

[Leetcode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Task

> Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
> 
> Example 1:
> Input: root = [3,1,4,null,2], k = 1
> Output: 1
> 
> Example 2:
> Input: root = [5,3,6,2,4,null,null,1], k = 3
> Output: 3
> 
> Constraints:
> The number of nodes in the tree is n.
> 1 <= k <= n <= 104
> 0 <= Node.val <= 104
> 
> Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## Complexity

Time: O(n)
Space: O(k)

## Solution

> Visit every node until the list of values is less than k. Visit the left node until its left child is not null. If the left child is null and the list of valeus is less than k, put this value to list of values and visit the right child if it exists.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    k = 0
    result = []
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        self.result = []
        self.visit(root)
        return self.result[-1]

    def visit(self, root: Optional[TreeNode]) -> None:
        if len(self.result) >= self.k:
            return

        if root.left:
            self.visit(root.left)

        if len(self.result) < self.k:
            self.result.append(root.val)

        if root.right:
            self.visit(root.right)
```