# 19. Remove Nth Node From End of List [Medium]

[Leetcode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

## Task

> Given the head of a linked list, remove the nth node from the end of the list and return its head.
>
>Example 1:
>Input: head = [1,2,3,4,5], n = 2
>Output: [1,2,3,5]
>
>Example 2:
>Input: head = [1], n = 1
>Output: []
>
>Example 3:
>Input: head = [1,2], n = 1
>Output: [1]
>
>Constraints:
>    The number of nodes in the list is sz.
>    1 <= sz <= 30
>    0 <= Node.val <= 100
>    1 <= n <= sz
>
> Follow up: Could you do this in one pass?

## Complexity

Time: O(n)
Space: O(1)

## Solution

> Make two pointers: slow and fast. Move fast for n steps. If "fast" points to last element then "slow" points to element before removable. If "fast" points to None, then "slow" points to removable element. "fast" points to None if the first element should be remove => return head.next. If "fast" points to not None, make slow.next = slow.next.next to skip removable item and return head

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow, fast = head, head
        while n > 0:
            n -= 1
            fast = fast.next
        
        if not fast: # should remove the first element
            return head.next
        
        while fast.next:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next

        return head
```