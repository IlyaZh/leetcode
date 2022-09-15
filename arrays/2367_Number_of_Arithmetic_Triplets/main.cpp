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
  vector<int> nums = {0, 1, 3, 5, 6, 8, 9};
  int diff = 3;
  int expect = 2;
  Solution s;
  auto answer = s.arithmeticTriplets(nums, diff);
  cout << "IN: nums = ";
  printCont(nums);
  cout << endl;
  cout << "diff = " << diff << endl;
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
