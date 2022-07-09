#include <gtest/gtest.h>
#include <vector>

// https://leetcode.com/problems/container-with-most-water/

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        size_t l = 0;
        size_t r = height.size() - 1;
        int maxArea = 0;
        while(l < r) {
            const int area = std::min(height.at(l), height.at(r)) * (r - l);
            maxArea = std::max(maxArea, area);
            if(height.at(l) < height.at(r)) {
                ++l;
            } else {
                --r;
            }
        }
        return maxArea;
    }
};

TEST(ClassTest, Test_1) {
    Solution s;
    vector<int> in{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int out = 49;
    int res = s.maxArea(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
    Solution s;
    vector<int> in{1, 1};
    int out = 1;
    int res = s.maxArea(in);
    EXPECT_EQ(res, out);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}