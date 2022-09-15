// https://leetcode.com/problems/top-k-frequent-words/

// 692. Top K Frequent Words

// Given an array of strings words and an integer k, return the k most
// frequent strings.
// Return the answer sorted by the frequency from highest to lowest. 
// Sort the words with the same frequency by their lexicographical order.

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent 
// words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 
// Constraints:
// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]

// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

#pragma once

#include <vector>
#include <string>
#include <utility>
#include <map>
#include <queue>

using namespace std;

class Solution {
  using Node = pair<int, string>;
  struct Cmp {
    bool operator()(const Node& lhs, const Node& rhs) {
      if(lhs.first == rhs.first)
        return lhs.second > rhs.second;
      return lhs.first < rhs.first;
    }
  };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string,int> freqMap;
      for(const auto& word : words) // O(n)
      {
        freqMap[word] += 1;
      }
      priority_queue<Node, vector<Node>, Cmp> pq;
      for(const auto& [k, v] : freqMap) {
        pq.push({v, k});
      }
      freqMap.clear();
      vector<string> result;  
      while(k-- && !pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
      }

      return result;
    }
};