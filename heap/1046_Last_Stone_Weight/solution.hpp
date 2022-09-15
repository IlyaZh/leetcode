/*
https://leetcode.com/problems/last-stone-weight/

1046. Last Stone Weight

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and
smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, 
return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
 - We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 - we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 - we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 - we combine 1 and 1 to get 0 so the array converts to [1] then that's the 
 - value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
*/

#include <vector>

using namespace std;

class Solution {
  int getMax() {
    return heap.empty() ? 0 : heap.front();
  }

  void pop() {
    if(heap.size() >= 1) {
      std::swap(heap[0], heap[heap.size()-1]);
      heap.pop_back();
      size_t current = 0;
      while(current < heap.size()) {
        size_t l = 2 * current + 1;
        size_t r = 2 * current + 2;
        size_t largest = current;
        if(l < heap.size() && heap.at(l) > heap.at(largest)) {
          largest = l;
        }
        if(r < heap.size() && heap.at(r) > heap.at(largest)) {
          largest = r;
        }
        if(largest != current) {
          std::swap(heap[current], heap[largest]);
          current = largest;
        } else {
          break; 
        }
      }
    } else if(heap.size() == 1) {
      heap.clear();
    }
  }

  void push(int value) {
    heap.push_back(value);
    size_t current = heap.size() - 1;
    while(current != 0) {
      size_t parent = (current - 1) / 2;
      if(heap.at(parent) < heap.at(current)) {
        std::swap(heap[parent], heap[current]);
      }
      current = parent;
    }
  }

  vector<int> heap;
  public:
    int lastStoneWeight(vector<int>& stones) {
        for(const auto& stone : stones) {
          push(stone);
        }

        while(heap.size() > 1) {
          auto first = getMax();
          pop();
          auto second = getMax();
          pop();
          if(first != second) {
            push(first-second);
          }
        }

        return getMax();
    }
};
