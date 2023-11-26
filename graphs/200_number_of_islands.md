# 200. Number of Islands [Medium]

[Leetcode](https://leetcode.com/problems/number-of-islands/description/)

## Task

> Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
> 
> An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
> 
> Example 1:
> Input: grid = [
>   ["1","1","1","1","0"],
>   ["1","1","0","1","0"],
>   ["1","1","0","0","0"],
>   ["0","0","0","0","0"]
> ]
> Output: 1
> 
> Example 2:
> Input: grid = [
>   ["1","1","0","0","0"],
>   ["1","1","0","0","0"],
>   ["0","0","1","0","0"],
>   ["0","0","0","1","1"]
> ]
> Output: 3
> 
> Constraints:
> m == grid.length
> n == grid[i].length
> 1 <= m, n <= 300
> grid[i][j] is '0' or '1'.

## Complexity

Time: O(n)
Space: O(n)

## Solution

> Iterate thrugh matric until current ceil is not '1'. For every '1' ceil exec Dfs function which makes visited '1' to '0'

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        R,C = len(grid), len(grid[0])

        def Dfs(r: int, c: int):
            if r < 0 or r >= R or c < 0 or c >= C or grid[r][c] != "1":
               return
            grid[r][c] = 0

            Dfs(r - 1, c)
            Dfs(r + 1, c)
            Dfs(r,c - 1)
            Dfs(r,c + 1)
                
        
        for r in range(R):
            for c in range(C):
                if grid[r][c] == "1":
                    Dfs(r,c)
                    islands += 1

        return islands
```