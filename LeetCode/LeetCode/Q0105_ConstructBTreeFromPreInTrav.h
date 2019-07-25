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

#include <unordered_map>

class Solution {
private:
	unordered_map<int, int> inidx_;

	TreeNode* buildHelper(vector<int>& preorder, int &idx, int low_bound, int high_bound)
	{		
		TreeNode *ret;

		if (idx >= preorder.size())
			return NULL;

		ret = new TreeNode(preorder[idx++]);		
		if (inidx_[ret->val] > low_bound)
			ret->left = buildHelper(preorder, idx, low_bound, inidx_[ret->val] - 1);
		if (inidx_[ret->val] < high_bound)
			ret->right = buildHelper(preorder, idx, inidx_[ret->val] + 1, high_bound);
		return ret;
	}
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {

		//build reverse map
		inidx_.clear();
		for (int i = 0; i < inorder.size(); i++)
			inidx_[inorder[i]] = i;

		int idx = 0;
		TreeNode *root = buildHelper(preorder, idx, 0, preorder.size() - 1);
		return root;
	}
};

void q0105_tester()
{
	Solution s;
	TreeNode *ans;

	vector<int> pre;
	vector<int> in;

	pre = { 3, 9, 20, 15, 7 };
	in = { 9, 3, 15, 20, 7 };
	ans = s.buildTree(pre, in);

	//pre = { 1,2,4,5,3,6,7 };
	//in = { 4,2,5,1,6,3,7 };
	//ans = s.buildTree(pre, in);

	cout << ans->val << endl;
	/* expect :

	 3
	/ \
   9  20
     /  \
	15   7

	*/
}



