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
    const int h = 1000000000;
    const int w = 1000000000;
    int expect = 4;
    Solution s;
    cout << "IN: h = " << h << ", w = " << w << ", " << endl;
    cout << "OUT: " << s.func() << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
