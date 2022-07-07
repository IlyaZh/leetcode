#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    string str = "BAAC";// "ABABAACA";
    int k = 2;
    int expect = 6;
    Solution s;
    cout << "IN: s = " << str << ", k = " << k << endl;
    cout << "OUT: " << s.characterReplacement(str, k) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}