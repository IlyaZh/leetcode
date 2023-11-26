# 79. Word Search [Medium]

[Leetcode](https://leetcode.com/problems/word-search/description/)

## Task

> Given an m x n grid of characters board and a string word, return true if word exists in the grid.
> 
> The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
> 
> Constraints:
> m == board.length
> n = board[i].length
> 1 <= m, n <= 6
> 1 <= word.length <= 15
> board and word consists of only lowercase and uppercase English letters.
> 
> Follow up: Could you use search pruning to make your solution faster with a larger board?

## Complexity

Time: O(n)
Space: O(1)

## Solution

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        Rows, Cols, W = len(board), len(board[0]), len(word)
        path = set()

        def Dfs(r: int, c: int, i: int) -> bool:
            if i >= W:
                return True
            if not (0 <= r < Rows and 0 <= c < Cols):
                return False

            if board[r][c] != word[i] or (r,c) in path:
                return False

            path.add((r,c))
            n = i + 1
            result = (
                Dfs(r-1, c, n) or
                Dfs(r+1, c, n) or
                Dfs(r, c-1, n) or
                Dfs(r, c+1, n) 
            )
            path.remove((r,c))
            return result


        for r in range(Rows):
            for c in range(Cols):
                if Dfs(r,c, 0):
                    return True
        return False
```