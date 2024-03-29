// https://www.lintcode.com/problem/920/

// 920 Meeting Rooms

// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
// meetings. Wechat reply 【Google】 get the latest requent Interview questions.
// (0,8),(8,10) is not conflict at 8

// Example

// Example1
// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: false

// Explanation:
// (0,30), (5,10) and (0,30),(15,20) will conflict

// Example2
// Input: intervals = [(5,8),(9,15)]
// Output: true

// Explanation:
// Two times will not conflict

#include <algorithm>
#include <vector>

using Event = std::pair<int, int>;

class Solution {
 public:
  bool canAttendMeetings(std::vector<Event>& meetings) {
    if (meetings.empty()) return false;
    std::sort(meetings.begin(), meetings.end());
    for (size_t i = 1, size = meetings.size(); i < size; ++i) {
      if (meetings.at(i - 1).second > meetings.at(i).first) {
        return false;
      }
    }
    return true;
  }
};
