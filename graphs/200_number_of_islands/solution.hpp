// https://leetcode.com/problems/number-of-islands/

// 200. Number of Islands

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and
// '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands
// horizontally or vertically. You may assume all four edges of the grid are all
// surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include <utility>
#include <vector>

using namespace std;

class Solution {
  enum { WATER = '0', LAND = '1' };

 public:
  using Grid = vector<vector<char>>;
  using Point = pair<size_t, size_t>;
  int numIslands(Grid& grid) {
    int islands_count = 0;
    for (size_t r = 0; r < grid.size(); ++r) {
      for (size_t c = 0; c < grid[0].size(); ++c) {
        if (grid[r][c] == LAND) {
          dfs(grid, Point(r, c));
          ++islands_count;
        }
      }
    }
    return islands_count;
  }

 private:
  void dfs(Grid& grid, Point&& start) {
    if (start.first < 0 || start.second < 0 || start.first >= grid.size() ||
        start.second >= grid[0].size() ||
        grid[start.first][start.second] != LAND) {
      return;
    }
    grid[start.first][start.second] = WATER;

    dfs(grid, Point(start.first, start.second - 1));
    dfs(grid, Point(start.first, start.second + 1));
    dfs(grid, Point(start.first - 1, start.second));
    dfs(grid, Point(start.first + 1, start.second));
  }
};
