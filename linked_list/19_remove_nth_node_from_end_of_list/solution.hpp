// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:
// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?

#include "libs/list_nodes.hpp"

using namespace std;
using namespace libs::list_nodes;

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) {
      return nullptr;
    }

    ListNode* l = head;
    ListNode* r = head;

    while (n-- > 0) {
      r = r->next;
    }

    if (r == nullptr) {
      return head->next;
    }

    while (r->next != nullptr) {
      r = r->next;
      l = l->next;
    }

    l->next = l->next->next;
    return head;
  }
};
