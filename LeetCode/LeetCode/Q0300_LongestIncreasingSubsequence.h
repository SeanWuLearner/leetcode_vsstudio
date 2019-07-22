
#pragma once

#include "DebugUtils.h"

#pragma region ordinary recursive
//class Solution {
//private:
//	template<typename T>
//	T max(T a, T b)
//	{
//		return (a > b) ? a : b;
//	}
//
//	int helper(vector<int>& nums, int prev, int idx)
//	{
//		if (idx >= nums.size())
//			return 0;
//
//		int taken = 0;
//		if (nums[idx] > prev)
//			taken = helper(nums, nums[idx], idx + 1) + 1;
//		int no_taken = helper(nums, prev, idx + 1);
//		return max(taken, no_taken);
//	}
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		return helper(nums, INT_MIN, 0);
//	}
//};
#pragma endregion

#pragma region recursive with mem table
//#include <algorithm>
//class Solution {
//private:
//	vector<vector<int>> memo_;
//	int max_;	
//
//	int helper(vector<int>& nums, int prev, int idx)
//	{
//		if (idx >= nums.size())
//			return 0;	
//		
//		if (memo_[prev + 1][idx] >= 0)
//			return memo_[prev + 1][idx];
//
//		int taken = 0;
//		if (prev == -1 || nums[idx] > nums[prev])
//			taken = helper(nums, idx, idx + 1) + 1;
//		int no_taken = helper(nums, prev, idx + 1);
//		memo_[prev + 1][idx] = std::max(taken, no_taken);
//		//printf("(%d, %d) = %d\r\n", prev, idx, memo_[prev + 1][idx]);
//		return memo_[prev + 1][idx];
//	}
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		int n = nums.size();
//		memo_ = vector<vector<int>>(n + 1, vector<int>(n, -1));		
//		return helper(nums, -1, 0);
//	}
//};
#pragma endregion

#pragma region DP_with_O(n^2) run time
//#include <algorithm>
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {		
//		int n = nums.size();
//		if (n == 0)
//			return 0;
//		
//		int max = 1;
//		vector<int> dp(n, 1);
//
//		for (int i = 1; i < n; i++)
//		{
//			for (int j = 0; j <= i - 1; j++)
//			{
//				if (nums[i] > nums[j])
//					dp[i] = std::max(dp[j] + 1, dp[i]);
//			}		
//			if (dp[i] > max)
//				max = dp[i];
//		}
//		return max;
//	}
//};
#pragma endregion

#pragma region DP_with_O(nlogn) run time
#include <algorithm>
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = lower_bound(dp.begin(), dp.end(), nums[i]);

			if (it == dp.end())
				dp.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return dp.size();
	}
};
#pragma endregion

void q0300_tester()
{
	Solution s;
	vector<int> q;

	q = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << s.lengthOfLIS(q) << endl; //expect 4, because [2,3,7,101]

	q = { 2, 2 };
	cout << s.lengthOfLIS(q) << endl; //expect 1

	q = { 1, 3, 6, 7, 9, 4, 10, 5, 6 };
	cout << s.lengthOfLIS(q) << endl; //expect 6

}

