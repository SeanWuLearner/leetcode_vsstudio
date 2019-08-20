#pragma once

#include "DebugUtils.h"

#pragma region time_limit_exceeded_ans
//#include <set>
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		vector<int> ans(nums.size());
//		multiset<int> rec;
//
//		for (int i = nums.size() - 1; i >= 0; i--)
//		{			
//			ans[i] = std::distance(rec.begin(), rec.upper_bound(nums[i] - 1));
//			rec.insert(nums[i]);
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region BST_manner
////the worst time complexity would be O(n^2)
//struct CTreeNode {
//	int val;
//	int cnt;
//	CTreeNode *left;
//	CTreeNode *right;
//	CTreeNode(int x) : val(x), cnt(0), left(NULL), right(NULL) {}
//	~CTreeNode()
//	{
//		cout << "end of Tree node" << endl;
//	}
//};
//
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		int n = nums.size();
//		if (n == 0)return{};
//		vector<int> ans(n);
//		CTreeNode **cur, *root = new CTreeNode(nums[n - 1]);				
//		
//		for (int i = n-2; i >= 0; i--)
//		{
//			int count = 0;
//			cur = &root;
//			while (*cur != NULL)
//			{				
//				if (nums[i] > (*cur)->val)
//				{					
//					count += (*cur)->cnt + 1;
//					cur = &(*cur)->right;
//				}
//				else
//				{
//					(*cur)->cnt++;
//					cur = &(*cur)->left;
//				}
//			}
//			ans[i] = count;
//			*cur = new CTreeNode(nums[i]);
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region merge_sort_manner
//the worst time complexity must be O(nlogn)
#include <algorithm>
class Solution {
private:
	void mergeCountSmaller(vector<int>& nums, vector<int>& indices,
						vector<int>& result, int left, int right, int right_end)
	{
		int idx1 = left, idx2 = right;
		int merge_right_count = 0;
		vector<int> new_idx;
		while (idx1 < right || idx2 < right_end)
		{
			if ((idx1 < right) && ((idx2 == right_end) || (nums[indices[idx1]] <= nums[indices[idx2]])))
			{
				result[indices[idx1]] += merge_right_count;
				new_idx.push_back(indices[idx1]);
				idx1++;
			}
			else
			{
				new_idx.push_back(indices[idx2]);
				merge_right_count++;
				idx2++;
			}
		}
		std::move(new_idx.begin(), new_idx.end(), indices.begin() + left);
	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		vector<int> result(n);
		vector<int> indices(n);
		for (int i = 0; i < n; i++) indices[i] = i;

		for (int step = 1; step <= n - 1; step <<= 1)
		{
			for (int left = 0; left + step < n; left += step << 1)
			{
				int right = left + step;
				int right_end = std::min(n, left + 2 * step);
				mergeCountSmaller(nums, indices, result, left, right, right_end);
			}

		}
		return result;
	}
};
#pragma endregion

void q0315_tester()
{
	Solution s;
	vector<int> q;
	vector<int> ans;

	q = { 5, 2, 6, 1 };
	ans = s.countSmaller(q);
	print(ans); //[2,1,1,0]


	q = { 2,0,1, };
	ans = s.countSmaller(q);
	print(ans); //[2,0,0]
}
