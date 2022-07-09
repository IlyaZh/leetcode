// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular
// cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular 
// cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal 
// and vertical position provided in the arrays horizontalCuts and verticalCuts. 
// Since the answer can be a large number, return this modulo 109 + 7.

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxH = 0;
        int maxW = 0;
        int lastH = 0;
        int lastW = 0;

        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());

        for(const auto& cut : horizontalCuts) {
            maxH = max(maxH, cut-lastH);
            lastH = cut;
        }

        for(const auto& cut : verticalCuts) {
            maxW = max(maxW, cut-lastW);
            lastW = cut;
        }
        return (1LL*maxH*maxW) % 1000000007;
    } 
};