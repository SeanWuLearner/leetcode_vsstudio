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
	TreeNode * helper(vector<int> &nums, int l, int h)
	{
		if (l > h)
			return NULL;

		int mid = l + ((h - l) >> 1);
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = helper(nums, l, mid - 1);
		root->right = helper(nums, mid+1, h);

		return root;
	}
public:
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};


void q0108_tester()
{
	Solution s;
	vector<int> q = { -10,-3,0,5,9 };

	TreeNode* ans;

	ans = s.sortedArrayToBST(q);
	cout << "test" << endl;
}
