// https://leetcode.com/problems/generate-parentheses/

// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// Constraints:
// 1 <= n <= 8

using namespace std;

class Solution {
  vector<string> result;
  void generate(string prefix, int open, int close, int total) {
    if (open < total) {
      generate(prefix + "(", open + 1, close, total);
    }
    if (close < open) {
      generate(prefix + ")", open, close + 1, total);
    }
    if (open == close && open == total) {
      result.push_back(prefix);
    }
  }

 public:
  vector<string> generateParenthesis(int n) {
    result.clear();
    generate("", 0, 0, n);
    return result;
  }
};
