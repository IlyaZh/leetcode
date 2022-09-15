// https://leetcode.com/problems/spiral-matrix/

// 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#pragma once

#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
      vector<int> retVal;
      const size_t m = matrix.size();
      const size_t n = matrix[0].size();
      int left = 0;
      int right = n-1;
      int top = 0;
      int bottom = m-1;
      while(retVal.size() < m*n) {
        for(int c = left; c <= right && retVal.size() < m*n; ++c) {
          retVal.push_back(matrix[top][c]);
        }
        ++top;

        for(int r = top; r <= bottom && retVal.size() < m*n; ++r) {
          retVal.push_back(matrix[r][right]);
        }
        --right;

        for(int c = right; c >= left && retVal.size() < m*n; --c) {
          retVal.push_back(matrix[bottom][c]);
        }
        --bottom;

        for(int r = bottom; r >= top && retVal.size() < m*n; --r) {
          retVal.push_back(matrix[r][left]);
        }
        ++left;

      }
      return retVal;
    }
};