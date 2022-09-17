#include <vector>

namespace libs::list_nodes {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

std::vector<int> ToVector(ListNode* head) {
  std::vector<int> nums;
  while (head != nullptr) {
    nums.push_back(head->val);
    head = head->next;
  }
  return nums;
}

ListNode* Parse(const std::vector<int>& nums) {
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

}  // namespace libs::list_nodes
