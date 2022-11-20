// https://leetcode.com/problems/reorder-list/

// 143. Reorder List

// You are given the head of a singly linked-list. The list can be represented
// as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// Constraints:
// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

#include <stack>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

std::vector<int> ToVector(ListNode* node) {
  std::vector<int> vec;
  while (node != nullptr) {
    vec.push_back(node->val);
    node = node->next;
  }
  return vec;
}

class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode *slow, *fast;
    slow = head;
    fast = slow->next;
    // find middle
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
      } else {
        fast = nullptr;
      }
    }

    // reverse second half
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr;
    while (second != nullptr) {
      auto* tmp = second->next;
      second->next = prev;
      prev = second;
      second = tmp;
    }

    // merge two halfs
    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
      ListNode* first_next = first->next;
      ListNode* second_next = second->next;
      first->next = second;
      second->next = first_next;
      first = first_next;
      second = second_next;
    }
  }
};
