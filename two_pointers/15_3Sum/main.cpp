#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/3sum/

using namespace std;

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums.at(i) == nums.at(i - 1)) continue;

            size_t l = i + 1;
            size_t r = nums.size() - 1;
            const int value = -nums.at(i);
            while (l < r) {
                const int sum = nums.at(l) + nums.at(r);

                if (sum > value) {
                    --r;
                }
                else if (sum < value) {
                    ++l;
                }
                else {
                    vector<int> triplet = { nums.at(i), nums.at(l), nums.at(r) };
                    result.push_back(triplet);

                    while (l < r && nums.at(l) == triplet.at(1))
                        ++l;

                    while (l < r && nums.at(r) == triplet.at(2))
                        --r;
                }
            }
        }

        return result;
    }
};

TEST(ClassTest, Test_1) {
    Solution s;
    vector<int> in{ -1,0,1,2,-1,-4 };
    vector<vector<int>> out = {
        {-1,-1,2},
        {-1,0,1}
    };
    auto res = s.threeSum(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
    Solution s;
    vector<int> in{};
    vector<vector<int>> out = {
    };
    auto res = s.threeSum(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_3) {
    Solution s;
    vector<int> in{0 };
    vector<vector<int>> out = {
    };
    auto res = s.threeSum(in);
    EXPECT_EQ(res, out);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}