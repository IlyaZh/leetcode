#103. Binary Tree Zigzag Level Order Traversal [Medium]

[Leetcode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

## Task

> Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
> 
> Example 1:
> Input: root = [3,9,20,null,null,15,7]
> Output: [[3],[20,9],[15,7]]
> 
> Example 2:
> Input: root = [1]
> Output: [[1]]
> 
> Example 3:
> Input: root = []
> Output: []
> 
> Constraints:
>  The number of nodes in the tree is in the range [0, 2000].
>  -100 <= Node.val <= 100


## Complexity

Time: O(n)
Space: O(n)

## Solution

> Doing BFS algorithm save values into list. Every even level reverse list of values

```python
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        result = []
        rtl = False
        queue = [root]
        
        while queue:
            sizeQueue = len(queue)
            newQueue = []
            currentResult = []

            for item in queue:
                if item.left is not None:
                    newQueue.append(item.left)
                if item.right is not None:
                    newQueue.append(item.right)
                currentResult.append(item.val)               

            if currentResult:
                if rtl:
                    result.append([item for item in reversed(currentResult)])
                else:
                    result.append(currentResult)
            rtl = not rtl
            queue = newQueue

        return result
```