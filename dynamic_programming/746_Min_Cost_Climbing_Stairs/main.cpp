#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int expect = 6;
    Solution s;
    cout << "IN: cost = [";
    copy(cost.begin(), cost.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "OUT: " << s.minCostClimbingStairs(cost) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
