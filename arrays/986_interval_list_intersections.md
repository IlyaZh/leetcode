# 986. Interval List Intersections [Medium]

[Leetcode](https://leetcode.com/problems/interval-list-intersections/description/)

## Task

>

## Complexity

Time: O(m+n)
Space: O(1)

## Solution

if one of lists is empty return an empty list.
Make a two pointers which points to lists. In cycle while both pointer is less than sizes of lists do:
- if intervals is overlaping put to results a new interval starts from `max(start points of intervals)` and ends at `min(end points of intervals)`
- increment pointer for that list where selected interval's end point is less than another interval ends point. If ends points are the same, increment both pointers

```python
def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
    if not firstList or not secondList: return None

    i,j, SizeFirst, SizeSecond = 0, 0, len(firstList), len(secondList)
    result = []

    while i < SizeFirst and j < SizeSecond:
        if firstList[i][0] <= secondList[j][1] and firstList[i][1] >= secondList[j][1]:
            result.append([max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])])

        if firstList[i][1] < secondList[j][1]:
            i += 1
        elif firstList[i][1] > secondList[j][1]:
            j += 1
        else:
            i += 1
            j += 1

    return result
```