// https://leetcode.com/problems/longest-consecutive-sequence/

// 128. Longest Consecutive Sequence

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109

#pragma once

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int global = nums.empty() ? 0 : 1;
      int local = 1;
      set<int> s(nums.begin(), nums.end());
      for(const auto& num : s) {
        if(auto it = s.find(num+1); it != s.end()) {
          ++local;
          global = max(global, local);
        } else {
          local = 1;
        }
      }
      return global;
    }
};