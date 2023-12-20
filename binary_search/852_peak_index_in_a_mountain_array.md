# 852. Peak Index in a Mountain Array [Medium]

[Leetcode](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

## Task

> An array arr is a mountain if the following properties hold:
> 
> arr.length >= 3
> There exists some i with 0 < i < arr.length - 1 such that:
> arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
> arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
> 
> Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
> 
> You must solve it in O(log(arr.length)) time complexity.
> 
> Example 1:
> Input: arr = [0,1,0]
> Output: 1
> 
> Example 2:
> Input: arr = [0,2,1,0]
> Output: 1
> 
> Example 3:
> Input: arr = [0,10,5,2]
> Output: 1
> 
> Constraints:
> 3 <= arr.length <= 105
> 0 <= arr[i] <= 106
> arr is guaranteed to be a mountain array.


## Complexity

Time: O(log(n))
Space: O(1)

## Solution

Use a binary search with comparing current element and the next. If the next more than current, set start item to the next, else set current item as end. 

```python
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        r = len(arr) - 1
        l = 0
        while l < r:
            m = l + (r - l) // 2
            if arr[m] < arr[m+1]:
                l = m+1
            else:
                r = m

        return l
```