#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

void print(bool flag) { cout << (flag ? "YES" : "NO"); }

template <typename Container>
void print(const Container& cont) {
  cout << "[ ";
  copy(cont.begin(), cont.end(),
       ostream_iterator<typename Container::value_type>(cout, " "));
  cout << "]";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  const int h = 1000000000;
  const int w = 1000000000;
  int expect = 4;
  Solution s;
  auto answer = s.func();
  cout << "IN: h = " << h << ", w = " << w << ", " << endl;
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
