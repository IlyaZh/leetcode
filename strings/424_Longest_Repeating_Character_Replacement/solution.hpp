/*
* 424. Longest Repeating Character Replacement
* You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
*
* Return the length of the longest substring containing the same letter you can get after performing the above operations.
*
* Example 1.
* Input: s = "ABAB", k = 2
* Output: 4
*
* Exmaple 2.
* Input: s = "AABABBA", k = 1
* Output: 4
*
*/

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int seq = 0;
        int longest = 0;
        unordered_map<char,int> freqAlph;
        for(size_t i = 0; i < s.size(); ++i) {
            longest = max(longest, ++freqAlph[s.at(i)]);
            if(seq < k + longest) {
                ++seq;
            } else {
                --freqAlph[s.at(i-seq)];
            }
        }

        return seq;
    }
};