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
    vector<int> nums = {4,3,6}; // {2,3,2,4,3};
	vector<int> divide = {8,2,6,10}; //{9,6,9,3,15};
    int expect = -1; //2;
    Solution s;
    cout << "IN: nums = ";
	printCont(nums);
	cout << endl;
	cout << "IN: divide = ";
	printCont(divide);
	cout << endl;
    cout << "OUT: " << s.minOperations(nums, divide) << endl;
    cout << "Expected: " << expect << endl;

    return 0;
}
