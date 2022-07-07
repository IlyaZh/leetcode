#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Solution s;
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    bool expect = true;
    cout << "IN: s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << endl;
    cout << "OUT: " << s.isInterleave(s1, s2, s3) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}