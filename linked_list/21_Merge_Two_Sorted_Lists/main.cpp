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

std::vector<int> ListNodeToVector(ListNode* head) {
  std::vector<int> nums;
  while (head != nullptr) {
    nums.push_back(head->val);
    head = head->next;
  }
  return nums;
}

ListNode* VectorToListNode(const std::vector<int>& nums) {
  ListNode* head{nullptr};
  ListNode* current{nullptr};
  for (const auto& num : nums) {
    if (head == nullptr) {
      head = current = new ListNode(num);
    } else {
      current->next = new ListNode(num);
      current = current->next;
    }
  }
  return head;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  const std::vector<int> empty_vec{};
  const std::vector<int> one_vec{1};
  const std::vector<int> first_vec{1, 4, 5};
  const std::vector<int> second_vec{2, 3, 6};

  auto empty_list = VectorToListNode(empty_vec);
  auto one_list = VectorToListNode(one_vec);
  auto first_list = VectorToListNode(first_vec);
  auto second_list = VectorToListNode(second_vec);
  Solution s;
  assert(ListNodeToVector(s.mergeTwoLists(empty_list, empty_list)) ==
         empty_vec);
  assert(ListNodeToVector(s.mergeTwoLists(empty_list, one_list)) == one_vec);
  assert(ListNodeToVector(s.mergeTwoLists(one_list, first_list)) ==
         std::vector<int>({1, 1, 4, 5}));
  assert(ListNodeToVector(s.mergeTwoLists(second_list, first_list)) ==
         std::vector<int>({1, 2, 3, 4, 5, 6}));
  std::cout << "OK" << std::endl;
  return 0;
}
