#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#include "solution.hpp"

using namespace std;

template<typename Container>
void printCont(const Container& cont) {
    cout << "[ ";
    copy(cont.begin(), cont.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout << "]";
}

int main(int argc, char* argv[]) {
    vector<string> vec = {"102", "473", "251", "814"};
	vector<vector<int>> queries = {
		{1, 1},	
		{2, 3},
		{4, 2},
		{1, 2}
	};
    Solution s;
    cout << "IN: h = ";
	printCont(vec);
	cout << endl;
    cout << "OUT: ";
	auto answ = s.smallestTrimmedNumbers(vec, queries);
	printCont(answ);
	cout << endl;
    

    return 0;
}
