#include <iostream>
#include <iterator>
#include <algorithm>
#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const int h = 1000000000;
    const int w = 1000000000;
    vector<int> horizontalCuts {2};
    vector<int> verticalCuts {2};
    int expect = 4;
    Solution s;
    cout << "IN: h = " << h << ", w = " << w << ", " << endl;
    cout << "horizontal: ";
    copy(horizontalCuts.begin(), horizontalCuts.end(), ostream_iterator<int>(cout, " "));
    cout << endl << "vertical: ";
    copy(verticalCuts.begin(), verticalCuts.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "OUT: " << s.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}