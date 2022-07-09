#include <gtest/gtest.h>
#include "../solution.h"
#include <string>

using namespace std;

TEST(ClassTest, Something) {
	string in {"aacabdkacaa"};
	string out {"aca"};
	Solution s;
	EXPECT_EQ(s.longestPalindrome(in), out);
}

TEST(ClassTest, First) {
	string in {"babad"};
	string out {"bab"};
	Solution s;
	EXPECT_EQ(s.longestPalindrome(in), out);
}

TEST(ClassTest, Second) {
	string in {"cbbd"};
	string out {"bb"};
	Solution s;
	EXPECT_EQ(s.longestPalindrome(in), out);
}

TEST(ClassTest, OneLetter) {
	string in {"s"};
	string out {"s"};
	Solution s;
	EXPECT_EQ(s.longestPalindrome(in), out);
}

TEST(ClassTest, Empty) {
	string in {""};
	string out {""};
	Solution s;
	EXPECT_EQ(s.longestPalindrome(in), out);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}