// https://leetcode.com/problems/ransom-note/description/

// 383. Ransom Note

// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:
// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<string::value_type, int> freq_dict;
    for (const auto& c : magazine) {
      freq_dict[c] += 1;
    }
    for (const auto& c : ransomNote) {
      if (!freq_dict.contains(c) ||
          (freq_dict.contains(c) && freq_dict[c] == 0)) {
        return false;
      }
      freq_dict[c] -= 1;
    }
    return true;
  }
};
