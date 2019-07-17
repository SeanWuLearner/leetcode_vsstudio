#pragma once

#include "DebugUtils.h"
#include "TreeNode.h"

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<pair<TreeNode*, int>> q;	//<node_ptr* , level>
		pair<TreeNode*, int> node;

		q.emplace(root, 0);
		while (q.empty() != true)
		{
			node = q.front();
			q.pop();

			if (node.first == NULL)
				continue;

			//extend the row
			if (ans.size() < node.second + 1)
				ans.push_back({});

			ans.at(node.second).push_back(node.first->val);
			q.emplace(node.first->left, node.second + 1);
			q.emplace(node.first->right, node.second + 1);
			//q.push(make_pair(node.first->left, node.second + 1));
			//q.push(make_pair(node.first->right, node.second + 1));			
		}
		return ans;
	}
};


void q0102_tester()
{
	Solution s;
	vector<vector<int>> ans;
	TreeNode head({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });  //use INT_MIN to simulate NULL point...

	ans = s.levelOrder(&head);
	print(ans);
}
