// https://leetcode.com/problems/search-a-2d-matrix/

// 74. Search a 2D Matrix

// Write an efficient algorithm that searches for a value target in an m x n
// integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the
// previous row.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    size_t r = matrix.size() * matrix[0].size();
    size_t l = 0;
    while (l < r) {
      auto m = l + (r - l) / 2;
      auto row = m / matrix[0].size();
      auto col = m % matrix[0].size();
      if (matrix[row][col] < target) {
        l = m + 1;
      } else if (matrix[row][col] > target) {
        r = m;
      } else {
        return true;
      }
    }
    return false;
  }
};
