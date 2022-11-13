// https://leetcode.com/problems/group-anagrams/

// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

//     1 <= strs.length <= 104
//     0 <= strs[i].length <= 100
//     strs[i] consists of lowercase English letters.

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  using Count = int;
  using Key = std::string;
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    for (auto& str : strs) {
      auto key = str;
      std::sort(key.begin(), key.end());
      anagrams[key].emplace_back(str);
    }
    std::vector<std::vector<std::string>> result;
    for (auto&& [key, anagram] : anagrams) {
      std::sort(anagram.begin(), anagram.end());
      result.emplace_back(std::move(anagram));
    }
    return result;
  }
};
