# 713. Subarray Product Less Than K [Medium]

[Leetcode](https://leetcode.com/problems/subarray-product-less-than-k/description/)

## Task

> Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
> 
> Example 1:
> Input: nums = [10,5,2,6], k = 100
> Output: 8
> Explanation: The 8 subarrays that have product less than 100 are:
> [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
> Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
> 
> Example 2:
> Input: nums = [1,2,3], k = 0
> Output: 0
> 
> Constraints:
>     1 <= nums.length <= 3 * 104
>     1 <= nums[i] <= 1000
>     0 <= k <= 106


## Complexity

Time: O(n)
Space: O(1)

## Solution

Use a sliding window. Extend it while product is less than `k`. If product more or equals to `k`, then shrink the window. On each iteration of extending add `1 + (r - l)` to `count`.

```python
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        size = len(nums)
        l,r,product,count = 0,0,1,0
        if k <= 1: return 0
        while r < size:
            product *= nums[r]
            while product >= k:
                product /= nums[l]
                l += 1
            count += 1 + (r - l)
            r += 1
            
        return count
```