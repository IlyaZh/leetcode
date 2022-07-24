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
  int target = 5;
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  bool expect = true;
  Solution s;
  auto answer = s.searchMatrix(matrix, target);
  cout << "IN: h = " << target << "matrix=" << endl;
  for (auto& line : matrix) {
    printCont(line);
    cout << endl;
  }
  cout << endl;
  cout << "OUT: " << answer << endl;
  cout << "Expected: " << expect << endl;
  assert(answer == expect && "Wrong answer");
  return 0;
}
