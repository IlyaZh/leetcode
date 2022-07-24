#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
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
    string str = "abccbaacz";
    char expect = 'c';
    Solution s;
    cout << "IN: s = " << str << endl;
    cout << "OUT: " << s.repeatedCharacter(str) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
