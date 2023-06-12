# 287. Find the Duplicate Number [Medium]

[Leetcode](https://leetcode.com/problems/find-the-duplicate-number/)

## Task

> Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
> 
> There is only one repeated number in nums, return this repeated number.
> 
> You must solve the problem without modifying the array nums and uses only constant extra space.

## Complexity

Time: O(n)
Space: O(1)

## Solution

> use fast and slow pointers to find a point where they meet. This point will be before the cycle starts for the same amount of steps like distance between start and cycle point

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0, 0 
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        
        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                break;

        return slow


```