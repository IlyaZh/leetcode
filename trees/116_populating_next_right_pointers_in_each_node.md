# 116. Populating Next Right Pointers in Each Node [Medium]

[Leetcode](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)

## Task

> You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
> 
> struct Node {
>   int val;
>   Node *left;
>   Node *right;
>   Node *next;
> }
> 
> Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
> 
> Initially, all next pointers are set to NULL.
> 
> Example 1:
> Input: root = [1,2,3,4,5,6,7]
> Output: [1,#,2,3,#,4,5,6,7,#]
> 
> Example 2:
> Input: root = []
> Output: []
> 
> Constraints:
> The number of nodes in the tree is in the range [0, 212 - 1].
> -1000 <= Node.val <= 1000

## Complexity

Time: O(n)
Space: O()

## Solution

Doing BFS save current level in queue. Iterate over list and make a link from every element except the last one to the next element.

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None

        queue = [root]
        while queue:
            childs = []
            i = 0
            count = len(queue)
            for item in queue:
                if item.left is not None:
                    childs.append(item.left)
                if item.right is not None:
                    childs.append(item.right)

            for i in range(count - 1):
                    queue[i].next = queue[i+1]
            queue = childs

        return root
```