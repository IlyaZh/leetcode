#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <string>
#include <vector>

// Time: O(n*log(m+n))
// Space: O(m+n)

using namespace std;

class Solution {
  int k_{};
  std::priority_queue<int, vector<int>, std::greater<int>> pq_{};

 public:
  Solution(int k, vector<int>& nums) : k_(k) {
    for (const auto& num : nums) {
      pq_.push(num);
    }

    while (pq_.size() > k_) {
      pq_.pop();
    }
  }

  int add(int val) {
    pq_.push(val);

    if (pq_.size() > k_) {
      pq_.pop();
    }

    return pq_.top();
  }
};
