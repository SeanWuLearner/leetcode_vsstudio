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

#pragma region sean_naive_solution
//class Solution {
//private:
//	enum MaxIdx {
//		kBreakMax = 0,
//		kLineMax = 1,
//		kJointMax = 2,
//		kSizeMaxIdx
//	};	
//
//	vector<int> helper(TreeNode *root)
//	{
//		if (root == NULL)
//			return { INT_MIN,INT_MIN,INT_MIN };
//
//		if (root->left == NULL && root->right == NULL)
//			return { root->val, root->val, INT_MIN };
//		
//		vector<int> ret(kSizeMaxIdx);
//		vector<int> max_l(kSizeMaxIdx);
//		vector<int> max_r((kSizeMaxIdx));
//		
//		max_l = helper(root->left);
//		max_r = helper(root->right);
//
//		//---compute max---		
//		int tmp;		
//		//max of broken path would be maximum num between (left[break], right[break], left[line], right[line]).
//		tmp = std::max(max_l[kLineMax], max_r[kLineMax]);		
//		ret[kBreakMax] = std::max(max_l[kBreakMax], max_r[kBreakMax]);
//		ret[kBreakMax] = std::max(ret[kBreakMax], tmp);		
//		ret[kLineMax] = std::max(tmp + root->val, root->val);
//		
//		//compute jointed max
//		tmp = root->val;
//		if (root->left)	tmp += max_l[kLineMax];
//		if (root->right) tmp += max_r[kLineMax];
//		ret[kJointMax] = std::max(tmp, std::max(max_l[kJointMax], max_r[kJointMax]));
//
//		return ret;
//	}
//public:
//	int maxPathSum(TreeNode* root) {
//		vector<int> v = helper(root);
//		int i = std::max(v[kJointMax], v[kLineMax]);		
//		return std::max(i, v[kBreakMax]);
//	}
//};
#pragma endregion

#pragma region genius_ans_on_leetcode
/*
	Idea:
		1. The helper function would only return the l/r "linked" maximum. 
		2. The "Jointed" max is maintained by a global max, so is broken max.
*/
class Solution {
private: 
	int max_val_;
	int helper(TreeNode *root)
	{
		if (root == NULL) return 0;

		int l = helper(root->left);
		int r = helper(root->right);
		if (l < 0) l = 0;
		if (r < 0) r = 0;
		
		max_val_ = std::max(max_val_, root->val + l + r);
		return std::max(l, r) + root->val;
	}

public:
	int maxPathSum(TreeNode* root) {
		max_val_ = INT_MIN;
		helper(root);
		return max_val_;
	}
};
#pragma endregion

void q0124_tester()
{
	Solution s;
	vector<int> q;
	TreeNode root(0);

	q = { 1, 2, 3 };
	root = TreeNode(q);
	cout << s.maxPathSum(&root) << endl; //expect 6

	q = { -10, 9, 20, INT_MIN, INT_MIN, 15, 7 };
	root = TreeNode(q);
	cout << s.maxPathSum(&root) << endl; //expect 42

	q = { -3 };
	root = TreeNode(q);
	cout << s.maxPathSum(&root) << endl; //expect -3

	q = { -2, -1 };
	root = TreeNode(q);
	cout << s.maxPathSum(&root) << endl; //expect -1

	q = { -2, -3, INT_MIN };
	root = TreeNode(q);
	cout << s.maxPathSum(&root) << endl; //expect -2
}
