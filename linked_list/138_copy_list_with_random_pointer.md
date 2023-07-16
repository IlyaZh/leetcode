# 138. Copy List with Random Pointer [Medium]

[Leetcode](https://leetcode.com/problems/copy-list-with-random-pointer/description/)

## Task

> A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
> 
> Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
> 
> For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
> 
> Return the head of the copied linked list.
> 
> The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
>
> val: an integer representing Node.val
> random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
> Your code will only be given the head of the original linked list.

## Complexity

Time: O(n)
Space: O(n)

## Solution

> This task solves by 2 steps. First, iterate through the original list and create its deep copy and at the same time create a map where key is node from the original list and value is node from the new list. Second, iterate through the original list and the new list and mapping by random node of the original item to node of the new list and assign it.

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        newHead = None
        newLast = None
        current = head
        m = {}
        while current:
            newNode = Node(current.val)
            if newLast is None:
                newHead = newNode
                newLast = newHead
            else:
                newLast.next = newNode
                newLast = newLast.next
            m[current] = newLast
            current = current.next

        current = head
        newLast = newHead
        while current:
            newLast.random = m[current.random] if current.random else None
            newLast = newLast.next
            current = current.next

        return newHead
```