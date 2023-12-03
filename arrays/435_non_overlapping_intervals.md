# 435. Non-overlapping Intervals [Medium]

[Leetcode](https://leetcode.com/problems/non-overlapping-intervals/description/)

## Task

> Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
> 
> Example 1:
> Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
> Output: 1
> Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
> 
> Example 2:
> Input: intervals = [[1,2],[1,2],[1,2]]
> Output: 2
> Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
> 
> Example 3:
> Input: intervals = [[1,2],[2,3]]
> Output: 0
> Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
> 
> Constraints:
> 1 <= intervals.length <= 105
> intervals[i].length == 2
> -5 * 10^4 <= start[i] < end[i] <= 5 * 10^4

## Complexity

Time: O(nlog(n))
Space: O(1)

## Solution

Sort list by end of interval. Count non-overlapping intervals. Return len(intervals) - count non-overlapping intervals

```python
def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    intervals.sort(key=lambda row: row[1])

    prev, count, Size = 0, 1, len(intervals)

    for i in range(1, Size):
        if intrevals[i][0] >= intervals[prev][1]:
            count += 1
            prev = i

    return Size - count
```