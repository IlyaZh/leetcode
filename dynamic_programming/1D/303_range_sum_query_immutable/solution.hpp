// LINK TO LEETCODE

// X. Title

// TASK DESCTIPTION

#include <vector>

using namespace std;

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    sum.reserve(nums.size() + 1);
    sum.push_back(0);
    for (const auto& num : nums) {
      sum.push_back(sum.back() + num);
    }
  }

  int sumRange(int left, int right) { return sum[right + 1] - sum[left]; }

 private:
  vector<int> sum;
};
