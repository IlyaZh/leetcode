// https://leetcode.com/problems/pascals-triangle/

// 118. Pascal's Triangle

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 
// Constraints:

// 1 <= numRows <= 30

#pragma once

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> triangle = {{1}};
		for(int i = 1; i < numRows; ++i) {
			vector<int> row(i+1);
			for(int j = 0; j <= i; ++j) {
				if(j == 0 | j == i) {
					row[j] = 1;
				} else {
					row[j] = triangle[i-1][j-1] + triangle[i-1][j];
				}
			}
			triangle.push_back(row);
		}
		return triangle;
    } 
};