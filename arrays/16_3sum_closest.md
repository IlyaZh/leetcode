# 16. 3Sum Closest [Medium]

[Leetcode](https://leetcode.com/problems/3sum-closest/description/)

## Task

> Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
> 
> Return the sum of the three integers.
> 
> You may assume that each input would have exactly one solution.
> 
> Example 1:
> Input: nums = [-1,2,1,-4], target = 1
> Output: 2
> Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
> 
> Example 2:
> Input: nums = [0,0,0], target = 1
> Output: 0
> Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
> 
> Constraints:
>     3 <= nums.length <= 500
>     -1000 <= nums[i] <= 1000
>     -10^4 <= target <= 10^4

## Complexity

Time: O(n^2)
Space: O(n)

## Solution

Make 3 pointers. The first, let's call it `i`, iterate from begin to `len(nums)-2`, the second `j` iterate from `i+1` to `k` (third iterator) and `k` starts from `size-1` and go backward. `j` and `k` move ahead to each other until `j<k`. On each step of iteration check if sum of three numbers is equals zero, then save it tupple. If `sum > 0`, decrease `k`, otherwise increase `j`. Save result to set.

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        size = len(nums)
        nums.sort()
        result = None
        for i in range(size-2):
            j = i + 1
            k = size - 1
            while j < k:
                temp = nums[i] + nums[j] + nums[k]
                if temp == target:
                    return temp
                else:
                    if result:
                        result = temp if abs(target-temp) < abs(target-result) else result
                    else:
                        result = temp

                    if temp > target:
                        k -= 1
                    else:
                        j += 1

        return result
```