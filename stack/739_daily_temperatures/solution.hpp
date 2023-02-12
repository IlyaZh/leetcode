// https://leetcode.com/problems/daily-temperatures/

// 739. Daily Temperatures

// Given an array of integers temperatures represents the daily temperatures,
// return an array answer such that answer[i] is the number of days you have to
// wait after the ith day to get a warmer temperature. If there is no future day
// for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:
// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  using Value = int;
  using Index = size_t;
  using Pair = std::pair<Value, Index>;
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<Pair> st;
    for (size_t i = 0, size = temperatures.size(); i < size; ++i) {
      while (!st.empty() && temperatures[i] > st.top().first) {
        const auto& [temp, idx] = st.top();
        st.pop();
        result[idx] = (i - idx);
      }
      st.emplace(make_pair(temperatures[i], i));
    }
    return result;
  }
};
