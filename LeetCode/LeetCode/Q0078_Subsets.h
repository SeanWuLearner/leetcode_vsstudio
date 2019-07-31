#pragma once

#include "DebugUtils.h"

#pragma region backtrace_with_recursion
class Solution {
private: 
	vector<vector<int>> ans_;

	void helper(vector<int> &nums, int idx, vector<int> cur_set)
	{
		ans_.push_back(cur_set);
		cur_set.push_back(0);
		for (int i = idx; i < nums.size(); i++)
		{
			cur_set.back() = nums[i];
			helper(nums, i + 1, cur_set);
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		ans_.clear();
		helper(nums, 0, {});
		return ans_;
	}
};
#pragma endregion

#pragma region bit-wise manipulation
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		int range = 1 << nums.size();
//		vector<vector<int>> ans;
//		vector<int> set;
//		for (int i = 0; i < range; i++)
//		{
//			int j = i;
//			int idx = 0;
//			set.clear();
//
//			while (j != 0)
//			{
//				if (j & 0x1)
//					set.push_back(nums[idx]);
//
//				idx++;
//				j >>= 1;
//			}
//			ans.push_back(set);
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region iteration_over_combination
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans = { {} };

		for (int i = 0; i < nums.size(); i++)
		{
			int size_ans = ans.size();
			for (int j = 0; j < size_ans; j++)
			{
				vector<int> set = ans[j];
				set.push_back(nums[i]);
				ans.push_back(set);
			}
		}
		return ans;
	}
};
#pragma endregion

void q0078_tester()
{
	Solution s;
	vector<int> q;
	vector<vector<int>> ans;

	q = { 1,2,3 };
	ans = s.subsets(q);
	print(ans);

/* expect
	[
		[3],
		[1],
		[2],
		[1,2,3],
		[1,3],
		[2,3],
		[1,2],
		[]
	]
*/
}
