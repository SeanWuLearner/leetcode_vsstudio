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
#include <stack>
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		stack<TreeNode*> odd_stk;
		stack<TreeNode*> even_stk;
		stack<TreeNode*> *cur_stk, *next_stk;
		vector<vector<int>> ans;
		TreeNode* cur;

		even_stk.push(root);
		int level = 0;
		while (odd_stk.empty() == false || even_stk.empty() == false)
		{
			if (level % 2 == 0)
			{
				cur_stk = &even_stk;
				next_stk = &odd_stk;
			}
			else
			{
				cur_stk = &odd_stk;
				next_stk = &even_stk;
			}

			while (cur_stk->empty() == false)
			{
				cur = cur_stk->top();
				cur_stk->pop();

				if (cur == NULL)
					continue;

				if (ans.size() <= level)
					ans.push_back({});

				ans[level].push_back(cur->val);

				if (level % 2 == 0)
				{
					next_stk->push(cur->left);
					next_stk->push(cur->right);
				}
				else
				{
					next_stk->push(cur->right);
					next_stk->push(cur->left);
				}
			}
			level++;
		}
		return ans;
	}
};


void q0103_tester()
{
	Solution s;
	vector<vector<int>> ans;
	TreeNode root({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });  //use INT_MIN to simulate NULL point...

	ans = s.zigzagLevelOrder(&root);
	print(ans);
}
