# 2. Add Two Numbers [Medium]

[Leetcode](https://leetcode.com/problems/add-two-numbers/description/)

## Task

> You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
> 
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.
> 
> Example 1
> Input: l1 = [2,4,3], l2 = [5,6,4]
> Output: [7,0,8]
> Explanation: 342 + 465 = 807.
> 
> Example 2
> Input: l1 = [0], l2 = [0]
> Output: [0]
> 
> Example 3:
> Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
> Output: [8,9,9,9,0,0,0,1]

## Complexity

Time: O(n+m)
Space: O(max(n,m))

## Solution

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        c, r, head = 0, None, None
        while l1 or l2:
            s1 = l1.val if l1 is not None else 0
            s2 = l2.val if l2 is not None else 0
            c += s1 + s2
            t = ListNode(c % 10)
            c = c // 10
            if head:
                head.next = t
            else:
                r = t
            head = t
            l1 = None if not l1 else l1.next
            l2 = None if not l2 else l2.next
        if c != 0:
            head.next = ListNode(c)
        return r
```