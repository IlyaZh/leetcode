#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Null) {
  Solution s;
  const auto result = s.diameterOfBinaryTree(nullptr);
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, OneRoot) {
  Solution s;
  auto root = std::make_shared<TreeNode>(5);
  const auto result = s.diameterOfBinaryTree(root);
  decltype(result) answer{0};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, One) {
  Solution s;
  auto root =
      std::make_shared<TreeNode>(5, nullptr, std::make_shared<TreeNode>(7));
  const auto result = s.diameterOfBinaryTree(root);
  decltype(result) answer{1};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Two) {
  Solution s;
  auto root = std::make_shared<TreeNode>(5, std::make_shared<TreeNode>(6),
                                         std::make_shared<TreeNode>(7));
  const auto result = s.diameterOfBinaryTree(root);
  decltype(result) answer{2};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Three) {
  Solution s;
  auto root = std::make_shared<TreeNode>(
      1,
      std::make_shared<TreeNode>(2, std::make_shared<TreeNode>(4),
                                 std::make_shared<TreeNode>(5)),
      std::make_shared<TreeNode>(3));
  const auto result = s.diameterOfBinaryTree(root);
  decltype(result) answer{3};
  EXPECT_EQ(result, answer);
}
