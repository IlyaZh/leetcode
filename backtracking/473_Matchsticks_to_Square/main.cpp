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
    vector<int> sticks = {1,1,2,2,2};
    bool expect = true;
    Solution s;
    cout << "IN: vec = ";
    printCont(sticks);
    cout << endl;
    cout << "OUT: " << s.makesquare(sticks) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
