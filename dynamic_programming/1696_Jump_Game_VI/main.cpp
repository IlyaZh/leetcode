#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const int k = 16309; //2;
    int expect = 7;
    vector<int> nums = {1,-1,-2,4,-7,3};
    Solution s;
    cout << "IN: k = " << k << ", nums = [";
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ","));
    cout << "]" << endl;
    cout << "OUT: " << s.maxResult(nums, k)  << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
