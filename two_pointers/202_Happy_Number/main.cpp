#include <iostream>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int n = 81;
    if(argc > 1) {
        n = atoi(argv[1]);
    }
    Solution s;
    cout << "IN: n = " << n << endl;
    cout << "OUT: " << s.isHappy(n) << endl;

    return 0;
}
