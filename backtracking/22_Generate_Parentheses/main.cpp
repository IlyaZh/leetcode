#include <gtest/gtest.h>
#include <string>

// https://leetcode.com/problems/generate-parentheses/

using namespace std;

class Solution {
    vector<string> vec;
    void create(string str, int left, int right, int total) {
        if(left == total && right == total) {
            vec.push_back(str);
        }
        if(left < total) {
            create(str+"(", left+1, right, total);
        }
        if(right < left) {
            create(str+")",left, right+1,total);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        create("", 0,0,n);
        
        return vec;
    }
};

TEST(ClassTest, Test_1) {
    Solution s;
    int in{3};
    vector<string> out{ "((()))","(()())","(())()","()(())","()()()"};
    auto res = s.generateParenthesis(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
    Solution s;
    int in{1};
    vector<string> out{ "()"};
    auto res = s.generateParenthesis(in);
    EXPECT_EQ(res, out);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}