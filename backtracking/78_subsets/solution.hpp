// https://leetcode.com/problems/subsets/
//
// 78. Subsets
//
// Given an integer array nums of unique elements, return all possible subsets
//(the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
//
//
// Constraints:
// 1 <= nums.length <= 10
//-10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    result.push_back(vector<int>());
    for (const auto &num : nums) {
      auto newLine = result;
      for (auto &item : newLine) {
        item.push_back(num);
      }
      move(newLine.begin(), newLine.end(), back_inserter(result));
    }
    return result;
  }
};
