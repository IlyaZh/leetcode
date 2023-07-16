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
        answer = None
        lastAnswer = None
        shift = 0

        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            newNumber = (v1 + v2 + shift)
            newNode = ListNode(newNumber % 10)
            shift = (v1 + v2 + shift) // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

            if not answer:
                answer = newNode
                lastAnswer = answer
            else:
                lastAnswer.next = newNode
                lastAnswer = lastAnswer.next

        if shift != 0:
            lastAnswer.next = ListNode(shift)

        return answer
```