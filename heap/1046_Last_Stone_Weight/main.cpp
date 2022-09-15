#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> stones = {2,7,4,1,8,1};
    const int expect = 1;
    Solution s;
    cout << "IN: stones = [";
    copy(stones.begin(), stones.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "OUT: " << s.lastStoneWeight(stones) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
