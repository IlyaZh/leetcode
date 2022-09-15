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
    vector<int> vec = {1,3,2,1,3,2,2};
    Solution s;
    cout << "IN: vec = ";
	printCont(vec);
	cout << endl;
    cout << "OUT: ";
	auto answer = s.numberOfPairs(vec);
	printCont(answer);
    

    return 0;
}
