#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    string s1("aadd");
    string s2("bcba");
    string s3("aabcddba");
    bool expect = true;
    cout << "IN: s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << endl;
    cout << "OUT: " << s.isInterleave(s1, s2, s3) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}