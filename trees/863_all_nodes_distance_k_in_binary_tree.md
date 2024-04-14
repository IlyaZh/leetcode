# 863. All Nodes Distance K in Binary Tree [Medium]

[Leetcode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

## Task

> Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
> 
> You can return the answer in any order.
> 
> Example 1:
> Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
> Output: [7,4,1]
> Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
> 
> Example 2:
> Input: root = [1], target = 1, k = 3
> Output: []
> 
> Constraints:
>     The number of nodes in the tree is in the range [1, 500].
>     0 <= Node.val <= 500
>     All the values Node.val are unique.
>     target is the value of one of the nodes in the tree.
>     0 <= k <= 1000



## Complexity

Time: O(n)
Space: O(n)

## Solution

This task is solved in a few steps. At the first step we create a parent map using BFS or DFS. The next step we put target to queue and iterate through the queue until it not empty and `k > 0`. On every step we add current element to visited set and add every child and parent if it haven't visited yet to queue. On the next level decrease `k` by one. After that the result was in queue.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        parent = {}
        visited = {}
        queue = deque()
        queue.append(root)

        while queue:
            size = len(queue)
            for _ in range(size):
                top = queue.popleft()
                if top.left:
                    parent[top.left] = top
                    queue.append(top.left)
                if top.right:
                    parent[top.right] = top
                    queue.append(top.right)

        queue.append(target)
        while queue and k > 0:
            size = len(queue)
            for _ in range(size):
                top = queue.popleft()
                visited[top] = 1

                if top.left and top.left not in visited:
                    queue.append(top.left)

                if top.right and top.right not in visited:
                    queue.append(top.right)

                if top in parent and parent[top] not in visited:
                    queue.append(parent[top])

            k -= 1

        result = []
        while queue:
            result.append(queue.popleft().val)

        return result
                
```