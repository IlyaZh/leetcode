// https://leetcode.com/problems/maximum-subarray/

// 53. Maximum Subarray

// Given an integer array nums, find the
// subarray
// which has the largest sum and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Example 2:
// Input: nums = [1]
// Output: 1

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// Follow up: If you have figured out the O(n) solution, try coding another
// solution using the divide and conquer approach, which is more subtle.

#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int current_sum = nums.front();
    int max_sum = nums.front();
    for (size_t i = 1; i < nums.size(); ++i) {
      const auto& num = nums[i];
      current_sum = max(current_sum + num, num);
      max_sum = max(max_sum, current_sum);
    }
    return max_sum;
  }
};
