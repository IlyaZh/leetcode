#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
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
  const string s{"Breathe"};
  const string t{"Bicycle"};
  bool expect = false;
  Solution solution;
  auto answer = solution.isAnagram(s, t);
  cout << "IN: s = " << s << ", t = " << t << ", " << endl;
  cout << "OUT: " << ((answer) ? "true" : "false") << endl;
  cout << "Expected: " << ((expect) ? "true" : "false") << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
