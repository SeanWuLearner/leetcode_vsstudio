#pragma once

#include "DebugUtils.h"

//using minus sign to determind whether repeat 
#include "stdlib.h" 
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans;

		for (int i = 0; i < n; i++)
		{
			if (nums[abs(nums[i]) - 1] < 0)
				ans.push_back(abs(nums[i]));
			else
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
		}

		return ans;
	}
};

void q0442_tester()
{
	Solution s;
	vector<int> q;

	q = { 4, 3, 2, 7, 8, 2, 3, 1 };
	print(s.findDuplicates(q)); // [2,3]


	q = { 10, 2, 5, 10, 9, 1, 1, 4, 3, 7 };
	print(s.findDuplicates(q)); // [10,1]
}
