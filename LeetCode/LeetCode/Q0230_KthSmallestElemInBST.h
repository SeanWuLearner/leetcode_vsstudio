#pragma once

#include "DebugUtils.h"
#include "TreeNode.h"


#pragma region recursion_manner
//class Solution {
//private:
//	int ans_;
//
//	//return true as hit
//	bool inorderDfs(TreeNode *root, int &k)
//	{
//		if (root == 0)
//			return false;
//		
//		if (inorderDfs(root->left, k))
//			return true;
//
//		if (--k == 0)
//		{
//			ans_ = root->val;
//			return true;
//		}
//
//		if (inorderDfs(root->right, k))
//			return true;
//
//		return false;
//	}
//public:
//	int kthSmallest(TreeNode* root, int k) 
//	{
//		ans_ = 0;
//		inorderDfs(root, k);
//		return ans_;
//	}
//};
#pragma endregion

#pragma region iteration_manner
#include <stack>
class Solution {	
public:
	int kthSmallest(TreeNode* root, int k)
	{
		stack<TreeNode*> stk;
		
		while (true)
		{
			while (root != NULL)
			{
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			if (--k == 0) return root->val;
			root = root->right;
		}
				
	}
};
#pragma endregion

void q0230_tester()
{
	Solution s;
	vector<int> q;
	TreeNode *root;

	q = { 3,1,4,INT_MIN,2 };
	root = new TreeNode(q);
	cout << s.kthSmallest(root, 1) << endl; //output: 1

	q = { 5,3,6,2,4,INT_MIN,INT_MIN,1 };
	root = new TreeNode(q);
	cout << s.kthSmallest(root, 3) << endl; //output: 3
}
