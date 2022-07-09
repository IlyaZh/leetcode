#include <gtest/gtest.h>
#include <string>

// https://leetcode.com/problems/longest-common-prefix/

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if (strs.empty())
            return prefix;
        if (strs.size() == 1)
            return strs[0];

        prefix = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            size_t j = 0;
            while (j < prefix.size() && j < strs[i].size()) {
                if (prefix.at(j) != strs[i].at(j)) {
                    break;
                }
                ++j;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};

TEST(ClassTest, Test_1) {
    Solution s;
    vector<string> in{ "flower","flow","flight" };
    string out("fl");
    auto res = s.longestCommonPrefix(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
    Solution s;
    vector<string> in{ "dog","racecar","car" };
    string out("");
    auto res = s.longestCommonPrefix(in);
    EXPECT_EQ(res, out);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}