// https://leetcode.com/problems/valid-anagram/

// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false
// otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt
// your solution to such a case?

#pragma once

// Time O(m+n)
// Space O(m+n)

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(const string& s, const string& t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> freqDict_1;
    unordered_map<char, int> freqDict_2;

    for (const auto& c : s) {
      freqDict_1[c] += 1;
    }
    for (const auto& c : t) {
      freqDict_2[c] += 1;
    }

    return freqDict_1 == freqDict_2;
  }
};

// Time O(MlogM+NlogN)
// Space O(1)

class Solution2 {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};