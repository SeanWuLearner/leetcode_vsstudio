
#pragma once

#include "DebugUtils.h"

#pragma region both_extremums_manner
//#include <algorithm>
//class Solution {
//public:
//	int maxProduct(vector<int>& nums) {
//		int ans = nums[0];
//		int imin, imax;
//
//		imin = imax = ans;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] < 0)
//				std::swap(imax, imin);
//
//			imax = std::max(imax*nums[i], nums[i]);
//			imin = std::min(imin*nums[i], nums[i]);
//
//			ans = std::max(ans, imax);
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region left_right_accumulate_prod
#include <algorithm>
class Solution {
public:
	int maxProduct(vector<int>& nums) {		
		int imax = INT_MIN;
		int left = 0, right = 0;
		int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			left = (left == 0) ? nums[i] : left * nums[i];
			right = (right == 0) ? nums[n - 1 - i] : right * nums[n - 1 - i];			
			imax = std::max(imax, std::max(left, right));			
		}
		return imax;
	}
};
#pragma endregion

void q0152_tester()
{
	Solution s;
	vector<int> q;
	
	q = { 2,3,-2,4 };
	cout << s.maxProduct(q) << endl; //expect 6

	q = { -2,0,-1 };
	cout << s.maxProduct(q) << endl; //expect 0
}



