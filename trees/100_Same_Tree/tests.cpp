#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, null_null) {
  Solution s;
  std::shared_ptr<TreeNode> left = nullptr;
  std::shared_ptr<TreeNode> right = nullptr;
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, null_num) {
  Solution s;
  std::shared_ptr<TreeNode> left = nullptr;
  std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(5);
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, X_X) {
  Solution s;
  std::shared_ptr<TreeNode> left(new TreeNode(5));
  std::shared_ptr<TreeNode> right(new TreeNode(5));
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, X_Y) {
  Solution s;
  std::shared_ptr<TreeNode> left(new TreeNode(5));
  std::shared_ptr<TreeNode> right(new TreeNode(6));
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Xy_Xy) {
  Solution s;
  std::shared_ptr<TreeNode> left(
      new TreeNode(5, std::make_shared<TreeNode>(4), nullptr));
  std::shared_ptr<TreeNode> right(
      new TreeNode(5, std::make_shared<TreeNode>(4), nullptr));
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Xy_Xz) {
  Solution s;
  std::shared_ptr<TreeNode> left(
      new TreeNode(5, std::make_shared<TreeNode>(4), nullptr));
  std::shared_ptr<TreeNode> right(
      new TreeNode(5, std::make_shared<TreeNode>(7), nullptr));
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Xy_X_y) {
  Solution s;
  std::shared_ptr<TreeNode> left(
      new TreeNode(5, std::make_shared<TreeNode>(4), nullptr));
  std::shared_ptr<TreeNode> right(
      new TreeNode(5, nullptr, std::make_shared<TreeNode>(4)));
  const auto result = s.isSameTree(left, right);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}
