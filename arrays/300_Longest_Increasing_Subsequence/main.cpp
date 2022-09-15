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
  vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
  int expect = 6;
  Solution s;
  auto answer = s.lengthOfLIS(nums);
  cout << "IN: nums = ";
  printCont(nums);
  cout << endl;
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
