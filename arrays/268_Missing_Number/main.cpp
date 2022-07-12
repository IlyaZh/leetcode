#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const vector<int> nums = {10,7,9,0,3,2,6,5,4,1}; // 8 is missed
    int expect = 8;
    Solution s;
    cout << "IN: nums = [";
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "OUT: " << s.missingNumber(nums) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
