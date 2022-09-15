#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const vector<int> vec = {1,3,9};
    Solution s;
    cout << "IN: vec = [";
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    auto res = s.plusOne(vec);
    cout << "OUT: [";
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;

    return 0;
}
