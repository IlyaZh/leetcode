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
struct Test {
  std::string str{};
  bool expected{false};
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  vector<Test> tests = {
      {"A man, a plan, a canal: Panama", true},
      {"race a car", false},
      {" ", true},
      {"a", true},
  };
  Solution s;
  for (int i = 0, size = tests.size(); i < size; ++i) {
    auto& test = tests[i];
    auto answer = s.isPalindrome(test.str);
    const auto testNum = i + 1;
    cout << "Case #" << testNum << endl;
    cout << "IN: str = [" << test.str << "]" << endl;
    cout << "OUT: ";
    print(answer);
    cout << endl;
    cout << "Expected: ";
    print(test.expected);
    cout << endl;
    cout << "===============" << endl << endl;
    assert(answer == test.expected && "Wrong answer");
  }
  return 0;
}
