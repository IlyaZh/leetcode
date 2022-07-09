#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    const int h = 1000000000;
    const int w = 1000000000;
    int expect = 4;
    Solution s;
    cout << "IN: h = " << h << ", w = " << w << ", " << endl;
    cout << "OUT: " << s.func() << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}