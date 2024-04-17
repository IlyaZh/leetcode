# 1004. Max Consecutive Ones III [Medium]

[Leetcode](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

## Task

> Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
> 
> Example 1:
> Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
> Output: 6
> Explanation: [1,1,1,0,0,1,1,1,1,1,1]
> Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
> 
> Example 2:
> Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
> Output: 10
> Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
> Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
> 
> Constraints:
>     1 <= nums.length <= 105
>     nums[i] is either 0 or 1.
>     0 <= k <= nums.length

## Complexity

Time: O(n)
Space: O(1)

## Solution

Find a maximum sliding window size. Move borders and count amount of zeros in `count`. If count of zeros is less than `k`, then move right border and increase `count` if zero is added to slided window. Every time while window extends save maximum window size to `result`. If count of zeros is equal `k`, move left border until `l<r and count >= k` and at every zero decreese `count`. 

```python
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l, r, count, size, result = 0, 0, 0, len(nums), 0

        while r < size:
            if nums[r] == 1:
                r += 1
                result = max(result, r-l)
            elif count < k:
                r += 1
                count += 1
                result = max(result, r-l)
            else:
                if nums[l] == 0:
                    count -= 1
                l += 1


        return result
```