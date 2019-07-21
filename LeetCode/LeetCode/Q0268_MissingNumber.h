#pragma once

#include "DebugUtils.h"

#pragma region using_sum
//class Solution {
//public:
//	int missingNumber(vector<int>& nums) {
//		int sum = (nums.size() * (nums.size() + 1)) >> 1;
//
//		for (int i : nums)
//			sum -= i;
//		return sum;
//	}
//};
#pragma endregion

#pragma region using_XOR
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int ans = nums.size();
		for (int i = 0; i < nums.size(); i++)		
			ans = ans ^ i ^ nums[i];
				
		return ans;
	}
};
#pragma endregion

void q0268_tester()
{
	Solution s;
	vector<int> q;

	q = { 3,0,1 };
	cout << s.missingNumber(q) << endl; //output 2
	q = { 9,6,4,2,3,5,7,0,1 };
	cout << s.missingNumber(q) << endl; //output 8
}



