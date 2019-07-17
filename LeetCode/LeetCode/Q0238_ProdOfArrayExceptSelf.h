#pragma once

#include "DebugUtils.h"
#include <array>

#pragma region orinary_method
//class Solution {
//public:
//	vector<int> productExceptSelf(vector<int>& nums) {
//		int n = nums.size();
//		if (n <= 1) return{};
//
//		vector<int> left(n, 0);
//		vector<int> right(n, 0);
//		vector<int> ans(n, 0);
//		int prod;
//		
//		//build left array
//		prod = 1;
//		for (int i = 0; i < n - 1; i++)
//			left[i] = prod = nums[i] * prod;
//
//		//build right array
//		prod = 1;
//		for (int i = n - 1; i > 0; i--)
//			right[i] = prod = nums[i] * prod;		
//
//		//form the ans
//		for (int i = 0; i < n; i++)
//			if (i == 0)
//				ans[i] = right[i + 1];
//			else if (i == n - 1)
//				ans[i] = left[i - 1];
//			else
//				ans[i] = right[i + 1] * left[i - 1];
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region minize_mem_consumption
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return{};

		vector<int> ans(n, 1);
		int prod;

		//build left array
		prod = 1;
		for (int i = 1; i < n; i++)
			ans[i] = nums[i - 1] * ans[i - 1];

		//form the ans
		prod = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			ans[i] = ans[i] * prod;
			prod *= nums[i];
		}
		return ans;
	}
};
#pragma endregion 

void q0238_tester()
{
	Solution s;
	vector<int> q;
	vector<int> a;

	q = { 1, 2, 3, 4 };
	a = s.productExceptSelf(q);
	print(a); //expect {24,12,8,6}
}
