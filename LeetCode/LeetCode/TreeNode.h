#pragma once

// Definition for a binary tree node.
#include "DebugUtils.h"
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

	//give v in level order traversal seq, where the INT_MIN element is equivalent to NULL.
	TreeNode(const vector<int> &v): left(NULL), right(NULL)
	{
		if (v.size() == 0)
			return;

		queue<TreeNode *> q;
		TreeNode *cur;
		int idx = 1;
		this->val = v[0];		
		q.push(this);
		while (q.empty() == false && idx < v.size())
		{
			cur = q.front();
			q.pop();

			//cout << "cur->val" << cur->val;			
			if (idx < v.size() && v[idx] != INT_MIN)
			{
				cur->left = new TreeNode(v[idx]);
				q.push(cur->left);
				//cout << ", left=" << cur->left->val;				
			}						
			idx++;

			if (idx < v.size() && v[idx] != INT_MIN)
			{
				cur->right = new TreeNode(v[idx]);
				q.push(cur->right);
				//cout << ", right=" << cur->right->val;				
			}			
			idx++;
			//cout << endl;
		}
	}

	~TreeNode()
	{
		//cout << "end of Tree node" << endl;
	}
};
