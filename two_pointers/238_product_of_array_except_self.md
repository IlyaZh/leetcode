# 238. Product of Array Except Self [Medium]

[Leetcode](https://leetcode.com/problems/product-of-array-except-self/description/)

## Task

> Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
> 
> The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
> 
> You must write an algorithm that runs in O(n) time and without using the division operation.
> 
> Example 1:
> Input: nums = [1,2,3,4]
> Output: [24,12,8,6]
> 
> Example 2:
> Input: nums = [-1,1,0,-3,3]
> Output: [0,0,9,0,0]
> 
> Constraints:
>     2 <= nums.length <= 10^5
>     -30 <= nums[i] <= 30
>     The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
> 
> Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


## Complexity

Time: O(n)
Space: O(1)

## Solution

Begin two pointers: forward and backward. Every iterator save prefix and suffix multiplication to resulted array.

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        l,r, size = 1, 1, len(nums)

        result = [1] * size

        for i in range(size):
            result[i] *= l
            l *= nums[i]

            rit = size - 1 - i
            result[rit] *= r
            r *= nums[rit]

        return result
```