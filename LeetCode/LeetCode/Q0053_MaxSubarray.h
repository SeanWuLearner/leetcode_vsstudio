
#pragma once
#include "DebugUtils.h"

#pragma region my_complicate_ans
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> left_acc(n);
//		vector<int> right_acc(n);
//
//		//form left acc array
//		int last = 0;
//		for (int i = 0; i < n; i++)
//		{
//			left_acc[i] = (last + nums[i] > nums[i]) ? last + nums[i] : nums[i];
//			last = left_acc[i];
//		}
//
//		//from right acc array
//		last = 0;
//		for (int i = n-1; i >= 0; i--)
//		{
//			right_acc[i] = (last + nums[i] > nums[i]) ? last + nums[i] : nums[i];
//			last = right_acc[i];
//		}
//
//		//find the maximum which combine these two array.
//		int ans = INT_MIN; //empty subarray is not accectable.(if it is acceptable, then we should init ans as 0)
//		for (int i = 0; i < n; i++)
//		{
//			int sum = (i == n - 1 || right_acc[i + 1] < 0)? left_acc[i] : left_acc[i] + right_acc[i + 1];
//			if (sum > ans)
//				ans = sum;			 
//		}
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region most concise DP manner
#include <algorithm>
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int curMax = nums[0], preMax = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			preMax = std::max(preMax + nums[i], nums[i]);
			curMax = std::max(curMax, preMax);
		}
		return curMax;
	}
};
#pragma endregion

void q0053_tester()
{
	Solution s;

	vector<int> q;
	
	q = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << s.maxSubArray(q) << endl;  //output 6, because [4,-1,2,1]

	q = {-1};
	cout << s.maxSubArray(q) << endl;  //output -1

	q = { -1, -2 };
	cout << s.maxSubArray(q) << endl;  //output -1


}
