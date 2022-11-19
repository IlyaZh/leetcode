// https://leetcode.com/problems/top-k-frequent-elements/

// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// Follow up: Your algorithm's time complexity must be better than O(n log n),
// where n is the array's size.

#include <utility>
#include <vector>
// #include <algorithm>
#include <queue>
#include <unordered_map>

class Solution {
 public:
  using Key = int;
  using Count = int;
  using Pair = std::pair<Key, Count>;

  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::unordered_map<Key, Count> freq_map;
    for (const auto& num : nums) {
      freq_map[num] += 1;
    }
    auto Comp = [](const Pair& lhs, const Pair& rhs) {
      return lhs.second < rhs.second;
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(Comp)> queue;
    for (const auto& [k, v] : freq_map) {
      queue.push(Pair{k, v});
    }
    while (k--) {
      result.push_back(queue.top().first);
      queue.pop();
    }
    return result;
  }
};
