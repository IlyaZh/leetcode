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
  using Pair = pair<int, int>;
  enum Direction_t {RIGHT, DOWN, LEFT, TOP};
  vector<int> borders;

  bool inBorder(const Pair& p) {
    return p.second == borders[LEFT]
          || p.second == borders[RIGHT]
          || p.first == borders[TOP]
          || p.first == borders[DOWN];
  }
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
      vector<int> retVal;
      const vector<Pair> steps = {
        {0,1}, // go to right
        {1,0}, // go to down
        {0,-1}, // go to left
        {-1,0} // go to top
      };
      borders.resize(4);
      borders[TOP] = -1;
      borders[LEFT] = -1;
      borders[RIGHT]=matrix[0].size();
      borders[DOWN]=matrix.size();
      int direction = RIGHT;
      bool canMove = true;
      Pair current = {0,0};
      retVal.push_back(matrix[current.first][current.second]);
      while(canMove) {
        auto next = current;
        next.first += steps[direction].first;
        next.second += steps[direction].second;
        if(inBorder(next)) {
          switch(direction) {
            case RIGHT:
              borders[TOP]++;
              break;
            case DOWN:
              borders[RIGHT]--;
              break;
            case LEFT:
              borders[DOWN]--;
              break;
            case TOP:
              borders[LEFT]++;
              break;
          }
          direction++;
          if(direction > TOP) direction = 0;
        } else {
          current = next;
          retVal.push_back(matrix[current.first][current.second]);
        }
        canMove = ((borders[DOWN] - borders[TOP]) > 1) && ((borders[RIGHT] - borders[LEFT]) > 1);
      }    

      return retVal;
    }
};