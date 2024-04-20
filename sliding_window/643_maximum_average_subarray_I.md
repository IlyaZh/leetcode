# 643. Maximum Average Subarray I [Easy]

[Leetcode](https://leetcode.com/problems/maximum-average-subarray-i/description/)

## Task

> You are given an integer array nums consisting of n elements, and an integer k.
> 
> Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
> 
> Example 1:
> Input: nums = [1,12,-5,-6,50,3], k = 4
> Output: 12.75000
> Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
> 
> Example 2:
> Input: nums = [5], k = 1
> Output: 5.00000
> 
> Constraints:
>     n == nums.length
>     1 <= k <= n <= 10^5
>     -10^4 <= nums[i] <= 10^4


## Complexity

Time: O(n)
Space: O(1)

## Solution

Make a sliding window and calculate sliding average. Save the maximum of sliding average and return it.

```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        l, r, size, maxAvg, avg = 0, 0, len(nums), 0, 0

        while r < k:
            avg += nums[r] / k
            r += 1
        maxAvg = avg

        while r < size:
            avg -= nums[l] / k
            avg += nums[r] / k
            maxAvg = max(maxAvg, avg)
            l += 1
            r += 1

        return maxAvg
```