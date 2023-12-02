# 328. Odd Even Linked List [Medium]

[Leetcode](https://leetcode.com/problems/odd-even-linked-list/description/)

## Task

> Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
> 
> The first node is considered odd, and the second node is even, and so on.
> 
> Note that the relative order inside both the even and odd groups should remain as it was in the input.
> 
> You must solve the problem in O(1) extra space complexity and O(n) time complexity.
> 
> Example 1:
> Input: head = [1,2,3,4,5]
> Output: [1,3,5,2,4]
> 
> Example 2:
> Input: head = [2,1,3,5,6,4,7]
> Output: [2,3,6,7,1,5,4]
> 
> Constraints:
> The number of nodes in the linked list is in the range [0, 104].
>  -10^6 <= Node.val <= 10^6


## Complexity

Time: O(n)
Space: O(1)

## Solution

Create two pointers: even and odd. Save the start of the "even" list at another pointer (dummy). If `head is None` return `None`. `Odd` points to `head`. `Even` points to `head.next`. While `even` and `even.next` is exits: change next pointers to item after the next item. e.g. `odd.next = odd.next.next` and move to the next item by `odd = odd.next`. Afther the end of cycle set the start of the "even" list (dummy pointer points to it) and return `head`

```python
def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None: return None

    odd = head
    dummy = even = head.next

    while even and even.next:
        odd.next = odd.next.next
        odd = odd.next

        even.next = even.next.next
        even = even.next

    odd.next = dummy

    return head
```