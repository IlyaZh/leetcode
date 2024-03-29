// https://leetcode.com/problems/reverse-linked-list/

// 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

// Constraints:
// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

// Follow up: A linked list can be reversed either iteratively or recursively.
// Could you implement both?

#pragma once

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next;
    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
};

// Recursive solution

class Solution2 {
  ListNode* Recursive(ListNode* prev, ListNode* curr) {
    if (curr == nullptr) {
      return prev;
    }
    auto next = curr->next;
    curr->next = prev;
    return Recursive(curr, next);
  }

 public:
  ListNode* reverseList(ListNode* head) { return Recursive(nullptr, head); }
};