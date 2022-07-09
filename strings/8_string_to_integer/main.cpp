#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
	bool is_digit(string::value_type sym) {
		auto d = digit(sym);
		return (d >= 0 && d <= 9);
	}
	int digit(string::value_type sym) {
		return sym-'0';
	}

		const long long int INT_32_MIN = -2147483648;
		const long long int INT_32_MAX = 2147483647;
		const long long int INT_64_MAX = 9223372036854775807;
		const long long int INT_64_MAX_DIV_10 = 922337203685477580;
		const unsigned long long int UINT_64_MAX_DIV_10 = 1844674407370955161;

public:
    int myAtoi(string s) {
		bool isNeg {false};
        unsigned long long int result {0};

		int it {0};
		while(it < s.size() && s.at(it) == ' ') {
			++it;
		}
		while(it < s.size() && !is_digit(s.at(it))) {
			if(s.at(it) == '+') {
				++it;
				break;
			} else if(s.at(it) == '-') {
				++it;
				isNeg = !isNeg;
				break;
			} else {
                return 0;
            }
			
		}
		while(it < s.size() && is_digit(s.at(it))) {
			result *= 10;
			result += digit(s.at(it));
			if(result > INT_32_MAX) break;
			++it;
		};

		long long int retVal {0};
		if(isNeg) {
			retVal = (-INT_32_MIN < result) ? -INT_32_MIN : static_cast<long long int>(result);
			retVal = -retVal;
		} else {
			retVal = (INT_32_MAX < result) ? INT_32_MAX : static_cast<long long int>(result);
		}

		return retVal;
    }
};

TEST(ClassTest, Test_1) {
	Solution s;
	string in{"42"};
	int out {42};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_2) {
	Solution s;
	string in{"   -42"};
	int out {-42};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_3) {
	Solution s;
	string in{"4193 with words"};
	int out {4193};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_4) {
	Solution s;
	string in{"+-12"};
	int out {0};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_5) {
	Solution s;
	string in{"20000000000000000000"};
	int out {2147483647};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_6) {
	Solution s;
	string in{"-91283472332"};
	int out {-2147483648};
	EXPECT_EQ(s.myAtoi(in), out);
}

TEST(ClassTest, Test_7) {
	Solution s;
	string in{"20000000000000000000"};
	int out {2147483647};
	EXPECT_EQ(s.myAtoi(in), out);
}



int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}