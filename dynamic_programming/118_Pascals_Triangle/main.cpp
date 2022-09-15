#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>

#include "solution.hpp"

using namespace std;

template<typename Container>
void printCont(const Container& cont) {
    cout << "[ ";
    copy(cont.begin(), cont.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout << "]";
}

int main(int argc, char* argv[]) {
	int num = 6;
	if(argc > 1) {
		num = atoi(argv[1]);
	}
    Solution s;
	auto result = s.generate(num);
    cout << "IN: num = " << num << endl;
    cout << "OUT: " << endl;
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result.size()-1-i; ++j) {
			cout << "    ";
		}
		
		for(int j = 0; j < result[i].size(); ++j) {
			cout << setw(6) << setfill(' ') << result[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
