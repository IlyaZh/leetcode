#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>

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
  Solution s;
  ListNode* no_cycle = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode* chain = new ListNode(3);
  ListNode* cycle = new ListNode(1, new ListNode(2, chain));
  chain->next = new ListNode(4, new ListNode(5, new ListNode(6, chain)));

  assert(s.hasCycle(no_cycle) == false);
  assert(s.hasCycle(cycle) == true);
  std::cout << "Good" << std::endl;
  return 0;
}
