#include <gtest/gtest.h>
#include "solution.hpp"

using namespace std;

TEST(ClassTest, Test_1) {
	Solution s;
	int in {123};
	int out {321};
	EXPECT_EQ(s.reverse(in), out);
}

TEST(ClassTest, Test_2) {
	Solution s;
	int in {-123};
	int out {-321};
	EXPECT_EQ(s.reverse(in), out);
}

TEST(ClassTest, Test_3) {
	Solution s;
	int in {120};
	int out {21};
	EXPECT_EQ(s.reverse(in), out);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}