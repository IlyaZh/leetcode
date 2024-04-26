# 994. Rotting Oranges [Medium]

[Leetcode](https://leetcode.com/problems/rotting-oranges/description/)

## Task

> You are given an m x n grid where each cell can have one of three values:
>     0 representing an empty cell,
>     1 representing a fresh orange, or
>     2 representing a rotten orange.
> 
> Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
> 
> Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
> 
> Example 1:
> Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
> Output: 4
> 
> Example 2:
> Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
> Output: -1
> Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
> 
> Example 3:
> Input: grid = [[0,2]]
> Output: 0
> Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
> 
> Constraints:
>     m == grid.length
>     n == grid[i].length
>     1 <= m, n <= 10
>     grid[i][j] is 0, 1, or 2.



## Complexity

Time: O(n)
Space: O(n)

## Solution

Find an rotten fruits and save it to `queue` . Make a bfs, change every item from `ROTTEN` to `EMPTY` and and it's `FRESH` neighbours which isn't in `queued` set to `queue`. Add the neighbour to `queue` and `queued` only if it doesn't exists in `ququed`. Save the maximum of iterations `step` to `result` and increment `step`. At the end iterate through the `grid` and if FRESH elements still exists, then return `-1`, otherwise return `result`

```python
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C, step, result = len(grid), len(grid[0]), 0, 0

        queue = []
        EMPTY, FRESH, ROTTEN = 0, 1, 2

        dirs = [(0, -1),(0, 1),(-1, 0),(1, 0)]

        for r in range(R):
            for c in range(C):
                if grid[r][c] == ROTTEN:
                    queue.append((r,c))

        while queue:
            nq = []
            for item in queue:
                r,c = item[0], item[1]
                grid[r][c] = EMPTY
                for dir in dirs:
                    nr,nc = r + dir[0], c + dir[1]
                    if 0 <= nr < R and  0 <= nc < C and (nr,nc) not in queue and grid[nr][nc] == FRESH:
                        nq.append((nr,nc))
            result = max(result, step)
            step += 1
            queue = nq

        for r in range(R):
            for c in range(C):
                if grid[r][c] == FRESH:
                    return -1

        return result
```