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
  vector<int> prices = {1, 2, 3, 9, 5, 1};
  int expect = 8;
  Solution s;
  auto answer = s.maxProfit(prices);
  cout << "IN: prices = ";
  print(prices);
  cout << endl;
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
