#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <optional>

using namespace std;

class Solution {
	vector<int> m_heap;
	
	public:
	int findKthLargest(vector<int>& nums, int k) {
		m_heap.clear();
		m_heap = nums;
		make_heap(m_heap.begin(), m_heap.end());
		while(k-- > 1) {
			pop_heap(m_heap.begin(), m_heap.end(), std::greater<>());
		}
		return m_heap.front();
	}
};






TEST(ClassTest, Test_1) {
	Solution s;
	vector<int> in {3,2,1,5,6,4};
	int k = 2;
	int out = 5;
	int res = s.findKthLargest(in, k);
	EXPECT_EQ(res, out);
}

TEST(ClassTest, Test_2) {
	Solution s;
	vector<int> in {3,2,3,1,2,4,5,5,6};
	int k = 4;
	int out = 4;
	EXPECT_EQ(s.findKthLargest(in, k), out);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}