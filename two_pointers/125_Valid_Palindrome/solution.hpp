// LINK TO LEETCODE

// X. Title

// TASK DESCTIPTION

#pragma once

#include <cctype>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (!std::isalnum(s[l])) {
        ++l;
        continue;
      }
      if (!std::isalnum(s[r])) {
        --r;
        continue;
      }
      if (std::tolower(static_cast<unsigned char>(s[l])) !=
          std::tolower(static_cast<unsigned char>(s[r]))) {
        return false;
      }
      ++l;
      --r;
    }
    return true;
  }
};