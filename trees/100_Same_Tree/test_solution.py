import pytest
from solution import Solution
from solution import TreeNode


def test_none_none():
  s = Solution()
  assert s.isSameTree(None, None) == True


def test_null_num():
  s = Solution()
  right = TreeNode(5)
  assert s.isSameTree(None, right) == False


def test_X_X():
  s = Solution()
  left = TreeNode(5)
  right = TreeNode(5)
  assert s.isSameTree(left, right) == True


def test_X_Y():
  s = Solution()
  left = TreeNode(5)
  right = TreeNode(6)
  assert s.isSameTree(left, right) == False


def test_Xy_Xy():
  s = Solution()
  left = TreeNode(5, TreeNode(4))
  right = TreeNode(5, TreeNode(4))
  assert s.isSameTree(left, right) == True


def test_Xy_Xz():
  s = Solution()
  left = TreeNode(5, TreeNode(35))
  right = TreeNode(6, TreeNode(42))
  assert s.isSameTree(left, right) == False


def test_mirrored():
  s = Solution()
  left = TreeNode(5, TreeNode(4), None)
  right = TreeNode(5, None, TreeNode(4))
  assert s.isSameTree(left, right) == False

