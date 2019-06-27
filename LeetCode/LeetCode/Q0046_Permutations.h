#pragma once


#include "DebugUtils.h"

#pragma region using_stack
//class Solution {
//private:
//	vector<vector<int>> ans_set_;
//	vector<bool> checker_;
//	vector<int> *nums_;
//
//	void permute_recur(int idx, vector<int> ans)
//	{
//		ans.push_back(nums_->at(idx));
//		if (ans.size() == nums_->size())
//			ans_set_.push_back(ans);
//
//		checker_[idx] = true;
//		for (size_t i = 0; i < nums_->size(); i++)
//		{
//			if (checker_[i] == true)
//				continue;
//
//			permute_recur(i, ans);
//		}
//		checker_[idx] = false;
//	};
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//
//		checker_ = vector<bool>(nums.size());
//		nums_ = &nums;
//		vector<int> ans;
//
//		for (size_t i = 0; i < nums_->size(); i++)
//		{
//			permute_recur(i, ans);
//		}
//		return ans_set_;
//	}
//};
#pragma endregion

#pragma region genius_in_place_swapping
class Solution {
	void helper(vector<int> &nums, int idx, vector<vector<int>> &ans)
	{
		if (idx == nums.size())
			ans.push_back(nums);

		for (int i = idx; i < nums.size(); i++)
		{			
			std::swap(nums[idx], nums[i]);
			helper(nums, idx+1, ans);
			std::swap(nums[idx], nums[i]); //swap back
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> ans;		
		helper(nums, 0, ans);		
		return ans;
	}
};
#pragma endregion

void q0046_tester()
{
	Solution s;
	vector<vector<int>> ans;
	vector<int> q;

	q = { 1,2,3, 4 };
	ans = s.permute(q);
	print(ans);
}

