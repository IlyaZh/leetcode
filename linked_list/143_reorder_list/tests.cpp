#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  auto* list =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  s.reorderList(list);
  auto result = ToVector(list);
  auto expect = std::vector<int>{1, 4, 2, 3};
  EXPECT_EQ(result, expect);
}

TEST(SolutionTest, Case2) {
  Solution s;
  auto* list = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  s.reorderList(list);
  auto result = ToVector(list);
  auto expect = std::vector<int>{1, 5, 2, 4, 3};
  EXPECT_EQ(result, expect);
}
