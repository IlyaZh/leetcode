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
    vector<int> vec = {100,4,200,1,3,2};
    int expect = 4;
    Solution s;
    cout << "IN: vec = ";
    printCont(vec);
    cout << endl;
    cout << "OUT: " << s.longestConsecutive(vec) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
