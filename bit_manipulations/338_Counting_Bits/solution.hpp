// https://leetcode.com/problems/counting-bits/

// 338. Counting Bits

// Given an integer n, return an array ans of length n + 1 such that for each i
// (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

// Example 2:
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

// Constraints:
// 0 <= n <= 105

// Follow up:
// It is very easy to come up with a solution with a runtime of O(n log n). Can
// you do it in linear time O(n) and possibly in a single pass? Can you do it
// without using any built-in function (i.e., like __builtin_popcount in C++)?

#include <unordered_map>
#include <vector>

class Solution {
  using Map = std::unordered_map<int, size_t>;
  int CountOnes(int n) {
    int count = 0;
    while (n) {
      ++count;
      const auto prev = n - 1;
      n &= prev;
    }
    return count;
  }
  int divide(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2) {
      return 1 + divide(n / 2);
    } else {
      return divide(n / 2);
    }
  }
  int divideMemo(size_t n, Map& map) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (map.count(n)) return map[n];
    if (n % 2) {
      map[n] = 1 + divideMemo(n / 2, map);
    } else {
      map[n] = divideMemo(n / 2, map);
    }
    return map[n];
  }

 public:
  std::vector<int> countBits(int n) {
    std::vector<int> result(n + 1);
    Map map;
    for (size_t i = 0, size = result.size(); i < size; ++i) {
      result[i] = divideMemo(i, map);
    }
    return result;
  }
};
