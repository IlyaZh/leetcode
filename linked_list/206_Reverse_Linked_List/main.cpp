#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

void print(bool flag) { cout << (flag ? "YES" : "NO"); }

void RemoveAllNodes(ListNode* node) {
  if (node != nullptr) {
    if (node->next != nullptr) {
      RemoveAllNodes(node->next);
    } else {
      delete node;
    }
  }
}

ListNode* CreateNodes(const std::vector<int>& nodes) {
  ListNode* head{nullptr};
  ListNode* last{nullptr};
  for (const int node : nodes) {
    if (head == nullptr) {
      head = last = new ListNode(node);
    } else {
      last->next = new ListNode(node);
      last = last->next;
    }
  }
  return head;
}

std::vector<int> NodesToVector(ListNode* head) {
  std::vector<int> vec;
  for (ListNode* current = head; current != nullptr; current = current->next) {
    vec.push_back(current->val);
  }
  return vec;
}

template <typename Container>
void print(const Container& cont) {
  cout << "[ ";
  copy(cont.begin(), cont.end(),
       ostream_iterator<typename Container::value_type>(cout, " "));
  cout << "]";
}

std::vector<int> ReverseVector(const std::vector<int>& input) {
  std::vector<int> reversed(input.size());
  std::reverse_copy(std::begin(input), std::end(input), std::begin(reversed));
  return reversed;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::vector<int> empty_vec = {};
  std::vector<int> one_vec = {1};
  std::vector<int> five_vec = {1, 2, 3, 4, 5};

  std::vector<int> empty_reverse_vec = ReverseVector(empty_vec);
  std::vector<int> one_reverse_vec = ReverseVector(one_vec);
  std::vector<int> five_reverse_vec = ReverseVector(five_vec);

  ListNode* empty_list = CreateNodes(empty_vec);
  ListNode* one_list = CreateNodes(one_vec);
  ListNode* five_list = CreateNodes(five_vec);
  Solution s;

  const auto empty_answer = NodesToVector(s.reverseList(empty_list));
  const auto one_answer = NodesToVector(s.reverseList(one_list));
  const auto five_answer = NodesToVector(s.reverseList(five_list));

  std::cout << "1) IN = ";
  print(empty_vec);
  std::cout << std::endl << "EXPECTED = ";
  print(empty_reverse_vec);
  std::cout << std::endl << "OUT = ";
  print(empty_answer);
  std::cout << std::endl << std::endl;
  assert(empty_answer == empty_reverse_vec);

  std::cout << "2) IN = ";
  print(one_vec);
  std::cout << std::endl << "EXPECTED = ";
  print(one_reverse_vec);
  std::cout << std::endl << "OUT = ";
  print(one_answer);
  std::cout << std::endl << std::endl;
  assert(one_answer == one_reverse_vec);

  std::cout << "3) IN = ";
  print(five_vec);
  std::cout << std::endl << "EXPECTED = ";
  print(five_reverse_vec);
  std::cout << std::endl << "OUT = ";
  print(five_answer);
  std::cout << std::endl << std::endl;
  assert(five_answer == five_reverse_vec);

  RemoveAllNodes(one_list);
  RemoveAllNodes(five_list);
  return 0;
}
