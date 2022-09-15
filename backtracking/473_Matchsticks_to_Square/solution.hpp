// https://leetcode.com/problems/matchsticks-to-square/

// 473. Matchsticks to Square

// You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

// Return true if you can make this square and false otherwise.

// Example 1:

// Input: matchsticks = [1,1,2,2,2]
// Output: true
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
// Example 2:

// Input: matchsticks = [3,3,3,3,4]
// Output: false
// Explanation: You cannot find a way to form a square with all the matchsticks.

// Constraints:

// 1 <= matchsticks.length <= 15
// 1 <= matchsticks[i] <= 108

#pragma once

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
    vector<int> sticks;
    vector<int> sides = {0,0,0,0};
    int sideLength = 0;
    bool putStick(int idx) {
        if(idx == sticks.size()) {
           return all_of(sides.begin(), sides.end(), [this](int count){
               return count == sideLength;
           });
        }
        
        const int stick = sticks[idx];
        
        for(int i = 0; i < 4; ++i) {
            if(sides[i] + stick <= sideLength) {
                sides[i] += stick;
                if(putStick(idx+1)) {
                    return true;
                }
                sides[i] -= stick;
            } 
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        sticks = matchsticks;
        const int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(totalLength % 4) {
            return false;
        }
        sideLength = totalLength / 4;
        sort(sticks.begin(), sticks.end(), std::greater<int>());
        return putStick(0);
    }
};