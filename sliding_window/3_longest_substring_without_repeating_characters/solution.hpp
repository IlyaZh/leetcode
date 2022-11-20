// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// 3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest
// substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    std::unordered_set<string::value_type> symbols;
    size_t length = 1;
    symbols.insert(s[0]);
    for (size_t l = 0, r = l + 1; l < s.size() && r < s.size();) {
      if (symbols.count(s[r])) {
        symbols.erase(s[l]);
        ++l;
      } else {
        symbols.insert(s[r]);
        ++r;
        length = max(length, symbols.size());
      }
    }
    return length;
  }
};
