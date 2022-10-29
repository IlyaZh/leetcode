// https://leetcode.com/problems/happy-number/

// 202. Happy Number

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the
// squares of its digits. Repeat the process until the number equals 1 (where it
// will stay), or it loops endlessly in a cycle which does not include 1. Those
// numbers for which this process ends in 1 are happy. Return true if n is a
// happy number, and false if not.

// Example 1:
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// Example 2:
// Input: n = 2
// Output: false

// Constraints:
// 1 <= n <= 231 - 1

#include <unordered_set>

class Solution {
  int SqareAndSum(int num) {
    int sum{0};
    while (num) {
      sum += (num % 10) * (num % 10);
      num /= 10;
    }
    return sum;
  }

 public:
  bool isHappy(int n) {
    auto slow = n;
    auto fast = SqareAndSum(n);
    while (slow != fast) {
      slow = SqareAndSum(slow);
      fast = SqareAndSum(SqareAndSum(fast));
    }
    return fast == 1;
  }
  bool isHappySet(int n) {
    std::unordered_set<int> visited;
    int result = n;
    while (result != 1) {
      result = SqareAndSum(result);
      if (visited.contains(result)) {
        return false;
      }
      visited.insert(result);
    }
    return true;
  }
};
