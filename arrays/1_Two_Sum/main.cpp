#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

template <typename Container>
void printCont(const Container& cont) {
  cout << "[ ";
  copy(cont.begin(), cont.end(),
       ostream_iterator<typename Container::value_type>(cout, " "));
  cout << "]";
}

int main(int argc, char* argv[]) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expect = {0, 1};
  Solution s;
  auto answer = s.twoSum(nums, target);
  cout << "IN: target = " << target << ", nums = ";
  printCont(nums);
  cout << endl;
  cout << "OUT: ";
  printCont(answer);
  cout << endl;
  cout << "Expected: ";
  printCont(expect);
  cout << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
