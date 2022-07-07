
// https://leetcode.com/problems/interleaving-string/

// 97. Interleaving String

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> grid(s1.size()+1, vector<bool>(s2.size()+1, false));
        grid[0][0] = true;

        for(size_t r = 1; r < grid.size(); r++) {
            if(s1.at(r-1) == s3.at(r-1)) {
                grid[r][0] = grid[r-1][0];
            } else {
                grid[r][0] = false;
            }
        }
        for(size_t c = 1; c < grid[0].size(); c++) {
            if(s2.at(c-1) == s3.at(c-1)) {
                grid[0][c] = grid[0][c-1];
            } else {
                grid[0][c] = false;
            }
        }

        for(int r = 1; r < grid.size(); ++r) {
            for(int c = 1; c < grid[0].size(); ++c) {
                const char& sym1 = s1.at(r-1);
                const char& sym2 = s2.at(c-1);
                const char& sym3 = s3.at(r+c-1);
                if(sym1 == sym3 && sym2 == sym3) {
                    grid[r][c] = grid[r-1][c] | grid[r][c-1];
                } else if(sym1 == sym3) {
                    grid[r][c] = grid[r-1][c];
                } else if(sym2 == sym3) {
                    grid[r][c] = grid[r][c-1];
                } else {
                    grid[r][c] = false;
                }
            }
        }

        return grid[s1.size()][s2.size()];
    }
};