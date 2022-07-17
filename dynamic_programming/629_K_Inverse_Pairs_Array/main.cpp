#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

template<typename Container>
void printCont(const Container& cont) {
    cout << "[ ";
    copy(cont.begin(), cont.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout << "]";
}

int main(int argc, char* argv[]) {
    const int k = 3;
    const int n = 1;
    int expect = 2;
    Solution s;
    cout << "IN: k = " << k << ", n = " << n << endl;
    cout << "OUT: " << s.kInversePairs(k,n) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
