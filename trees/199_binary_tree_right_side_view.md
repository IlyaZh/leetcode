# 199. Binary Tree Right Side View [Medium]

[Leetcode](https://leetcode.com/problems/binary-tree-right-side-view/)

## Task

>Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
> 
> 
> Example 1:
> Input: root = [1,2,3,null,5,null,4]
> Output: [1,3,4]
> 
> Example 2:
> Input: root = [1,null,3]
> Output: [1,3]
> 
> Example 3:
> Input: root = []
> Output: []
>  
> Constraints:
> The number of nodes in the tree is in the range [0, 100].
> -100 <= Node.val <= 100

## Complexity

Time: O(n)
Space: O(log(n))

## Solution

> DFS (value, right, left) put into visitor method a depth and list of values. If depth is more than length of list, then put current value to list. Else do nothing with list.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        return self.visit(root, 1, [])

    def visit(self, root: Optional[TreeNode], depth: int, result: List[int]) -> List[int]:
        if not root:
            return result;
            
        if depth > len(result):
            result.append(root.val)

        result = self.visit(root.right, depth + 1, result)

        result = self.visit(root.left, depth + 1, result)

        return result;
```