// https://leetcode.com/problems/binary-tree-right-side-view/

// 199. Binary Tree Right Side View

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
// Example 2:

// Input: root = [1,null,3]
// Output: [1,3]
// Example 3:

// Input: root = []
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

#pragma once

#include <vector>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
	map<int, int> m;
	void getRightest(TreeNode* root, int level) {
		if(root == nullptr) return;
		if(auto it = m.find(level); it == m.end()) {
			m.insert({level, root->val});
		}
		getRightest(root->right, level+1);
		getRightest(root->left, level+1);
	}
public:
    vector<int> rightSideView(TreeNode* root) {
		m.clear();
        vector<int> retVal;
		getRightest(root, 0);
		
		for(const auto &[level, num] : m) {
			retVal.push_back(num);
		}
        return retVal;
    }
};