// https://leetcode.com/problems/product-of-array-except-self/

// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i]
// is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in
// a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using
// the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit
// in a 32-bit integer.

// Follow up: Can you solve the problem in O(1) extra space complexity?
// (The output array does not count as extra space for space complexity
// analysis.)

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    /*
    // O(n) time
    // O(n) space
    vector<int> prefix(nums.size(), 0);
    vector<int> postfix(nums.size(), 0);
    const auto last = nums.size() - 1;
    for (size_t l = 0, size = nums.size(), r = last; l < size; ++l, --r) {
      auto last_prefix = (l != 0) ? prefix[l - 1] : 1;
      auto last_postfix = (r != last) ? postfix[r + 1] : 1;
      prefix[l] = last_prefix * nums[l];
      postfix[r] = last_postfix * nums[r];
    }
    std::vector<int> result(nums.size(), 0);
    for (size_t i = 0, size = nums.size(); i < size; ++i) {
      const auto pref = (i != 0) ? prefix[i - 1] : 1;
      const auto post = (i != last) ? postfix[i + 1] : 1;
      result[i] = pref * post;
    }
    */

    // O(n) time
    // O(1) space
    vector<int> result(nums.size(), 1);
    auto pref = 1;
    for (size_t i = 0, size = nums.size(); i < size; i++) {
      result[i] *= pref;
      pref *= nums[i];
    }
    auto post = 1;
    auto current = nums.size() - 1;
    for (size_t i = 0, size = nums.size(); i < size; i++) {
      result[current] *= post;
      post *= nums[current];
      --current;
    }

    return result;
  }
};
