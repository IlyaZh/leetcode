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
    vector<int> vec = {18,43,36,13,7};
	const int expected = 54;
    Solution s;
    cout << "IN: vec = ";
	printCont(vec);
	cout << endl;
    cout << "OUT: " << s.maximumSum(vec) << endl;
	cout << "Expected: " << expected << endl;

    return 0;
}
