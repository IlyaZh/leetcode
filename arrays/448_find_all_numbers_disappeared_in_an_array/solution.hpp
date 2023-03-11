// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// 448. Find All Numbers Disappeared in an Array

// Given an array nums of n integers where nums[i] is in the range [1, n],
// return an array of all the integers in the range [1, n] that do not appear
// in nums.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:
// Input: nums = [1,1]
// Output: [2]

// Constraints:
// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n

// Follow up: Could you do it without extra space and in O(n) runtime?
// You may assume the returned list does not count as extra space.

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    size_t i = 0;
    while (i < nums.size()) {
      size_t pos = nums[i] - 1;
      if (nums[i] != nums[pos]) {
        swap(nums[i], nums[pos]);
      } else {
        ++i;
      }
    }
    vector<int> missed;
    for (size_t j = 0; j < nums.size(); ++j) {
      if (nums[j] != static_cast<int>(j + 1)) {
        missed.push_back(j + 1);
      }
    }
    return missed;
  }
};
