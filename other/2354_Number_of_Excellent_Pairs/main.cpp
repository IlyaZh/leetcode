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
  const vector<int> vec = {1, 2, 3, 1};
  const int k = 3;
  int expect = 5;
  Solution s;
  cout << "IN: k = " << k << " vec = ";
  printCont(vec);
  cout << endl;
  auto answer = s.countExcellentPairs(vec, k);
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect);

  return 0;
}
