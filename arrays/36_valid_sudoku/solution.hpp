// https://leetcode.com/problems/valid-sudoku/

// 36. Valid Sudoku

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
// without repetition. Note:

// A Sudoku board (partially filled) could be valid but is not necessarily
// solvable. Only the filled cells need to be validated according to the
// mentioned rules.

// Example 1:
// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true

// Example 2:
// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
// is invalid.

// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

// #include <unordered_set>
#include <vector>

class Solution {
  constexpr static const size_t kSize = 9;  // by conditions
  constexpr static const size_t kCubeSize = 3;
  int GetCubeNum(size_t r, size_t c) {
    return (r / kCubeSize) * (kSize / kCubeSize) + (c / kCubeSize);
  }

 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    // Time: O(n) = O(size^2)
    // Space: O(size^2)
    std::vector<std::vector<bool>> rows(kSize, std::vector<bool>(kSize, false));
    std::vector<std::vector<bool>> cols(kSize, std::vector<bool>(kSize, false));
    std::vector<std::vector<bool>> cubes(kSize,
                                         std::vector<bool>(kSize, false));

    for (size_t r = 0; r < kSize; ++r) {
      for (size_t c = 0; c < kSize; ++c) {
        const auto& num = board[r][c];
        const auto idx = num - '0';
        const auto cube = GetCubeNum(r, c);
        if (num == '.') {
          continue;
        }
        if (rows[r][idx] || cols[c][idx] || cubes[cube][idx]) {
          return false;
        }
        rows[r][idx] = cols[c][idx] = cubes[cube][idx] = true;
      }
    }
    return true;
  }
};
