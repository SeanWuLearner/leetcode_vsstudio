#pragma once

#include "DebugUtils.h"
#include "TreeNode.h"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
private:
	template <typename T>
	T max(T a, T b) { return (a > b) ? a : b; }

public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

void q0104_tester()
{
	Solution s;

	vector<int> q = { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 };
	TreeNode *root = new TreeNode(q);
	cout << s.maxDepth(root) << endl; // 3
}
