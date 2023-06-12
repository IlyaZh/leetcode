# 853. Car Fleet [Medium]

[Leetcode](https://leetcode.com/problems/car-fleet/)

## Task

> There are n cars going to the same destination along a one-lane road. The destination is target miles away.
>
> You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).
>
> A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).
>
> A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
>
> If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
>
> Return the number of car fleets that will arrive at the destination.

## Complexity

Time: O(n)
Space: O(n)

## Solution

> Text solution

```python
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = [[p,s] for p, s in zip(position, speed)]
        pairs.sort(reverse=True)
        cars = []
        for p,s in pairs:
            cars.append((target - p) / s)
            if len(cars) >= 2 and  cars[-1] <= cars[-2]:
                cars.pop()
                
        return len(cars)
```
