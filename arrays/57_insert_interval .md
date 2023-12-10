# 57. Insert Interval  [Medium]

[Leetcode](https://leetcode.com/problems/insert-interval/description/)

## Task

> You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
> 
> Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
> 
> Return intervals after the insertion.
> 
> Example 1:
> Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
> Output: [[1,5],[6,9]]
> 
> Example 2:
> Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
> Output: [[1,2],[3,10],[12,16]]
> Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
> 
> Constraints:
> 0 <= intervals.length <= 10^4
> intervals[i].length == 2
> 0 <= start[i] <= endi <= 10^5
> intervals is sorted by start[i] in ascending order.
> newInterval.length == 2
> 0 <= start <= end <= 10^5



## Complexity

Time: O(n)
Space: O(n)

## Solution

Text solution

```python
def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    if not intervals:
        return [newInterval]

    if intervals[0][0] > newInterval[1]:
        intervals.insert(0, newInterval)
        return intervals

    inserted = False
    result = []
    for interval in intervals:
        if interval[1] < newInterval[0]:
            result.append(interval)
        elif interval[0] > newInterval[1]:
            if not inserted:
                inserted = True
                result.append(newInterval)
            result.append(interval)
        else: 
            newInteval = [min(), max()]

    if not inserted:
        result.append(newInterval)

    return result
```