#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <iterator>

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

using namespace std;
// Solving by backtracking method
class Solution {
    vector<string> result;
    const vector<string> chars {
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}
    };
    void backtrack(string s, int n, const string& digits) {
        if(s.size() == digits.size()) {
            result.emplace_back(s);
            return;
        }

        for(auto& c : chars[digits[n]-'2']) {
            backtrack(s+c, n+1, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        result.clear();
        backtrack("", 0, digits);
        return result;
    }
};

// Another one solution
/*class Solution {
    const vector<string> chars = {
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}
    };
    vector<string> permutate(const string s, const string& symbols) {
        vector<string> result(symbols.size(), s);
        for (size_t i = 0; i < symbols.size(); ++i) {
            result[i] += symbols[i];
        }
        return result;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for (const auto& digit : digits) {
            if(result.empty()) {
                result = permutate("", chars[digit-'2']);
            } else {
                auto strs = result;
                result.clear();
                for(const auto& str : strs) {
                    auto vec = permutate(str, chars[digit-'2']);
                    std::copy(vec.begin(), vec.end(), std::back_inserter(result));
                }
            }
        }
        return result;
    }
};*/

TEST(ClassTest, Test_1) {
    Solution s;
    string in{"23"};
    vector<string> out{ "ad","ae","af","bd","be","bf","cd","ce","cf" };
    auto res = s.letterCombinations(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
    Solution s;
    string in{ "" };
    vector<string> out{ };
    auto res = s.letterCombinations(in);
    EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_3) {
    Solution s;
    string in{ "2" };
    vector<string> out{ "a","b","c" };
    auto res = s.letterCombinations(in);
    EXPECT_EQ(res, out);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}