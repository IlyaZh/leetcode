// https://leetcode.com/problems/3sum/

// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not
// matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:
// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    if (nums.size() < 3) {
      return {};
    }
    std::sort(nums.begin(), nums.end());
    if (nums.front() > 0) {
      return {};
    }
    std::vector<std::vector<int>> result;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        return result;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      auto l = i + 1;
      auto r = nums.size() - 1;
      while (l < r) {
        const auto sum = nums[i] + nums[l] + nums[r];
        if (sum > 0) {
          --r;
        } else if (sum < 0) {
          ++l;
        } else {
          const auto l_value = nums[l];
          const auto r_value = nums[r];
          result.push_back({nums[i], l_value, r_value});
          while (l < r && nums[l] == l_value) {
            ++l;
          }
          while (l < r && nums[r] == r_value) {
            --r;
          }
        }
      }
    }
    return result;
  }
};
