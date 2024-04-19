# 257. Binary Tree Paths [Easy]

[Leetcode](https://leetcode.com/problems/binary-tree-paths/description/)

## Task

> Given the root of a binary tree, return all root-to-leaf paths in any order.
> 
> A leaf is a node with no children.
> 
> Example 1:
> Input: root = [1,2,3,null,5]
> Output: ["1->2->5","1->3"]
> 
> Example 2:
> Input: root = [1]
> Output: ["1"]
> 
> Constraints:
>     The number of nodes in the tree is in the range [1, 100].
>     -100 <= Node.val <= 100

## Complexity

Time: O(n)
Space: O(n) - recursive, amortized O(1)

## Solution

Dfs

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if not root: 
            return []

        result = []

        def Dfs(path: str, root: Optional[TreeNode]):
            nonlocal result

            if not root:
                return

            current = path + ('->' if path else '') + str(root.val)

            if not root.left and not root.right:
                result.append(current)

            Dfs(current, root.left)
            Dfs(current, root.right)


        Dfs('', root)

        return result
```