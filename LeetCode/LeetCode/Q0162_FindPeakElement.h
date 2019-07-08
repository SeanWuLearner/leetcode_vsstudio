#pragma once

#include "DebugUtils.h"

#pragma region O(n)_method
//class Solution {
//public:
//	int findPeakElement(vector<int>& nums) {
//		int prev, now, next;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			now = nums[i];
//			if (i == 0)
//				prev = INT_MIN;
//			else
//				prev = nums[i - 1];
//
//			if (i == nums.size() - 1)				
//				next = INT_MIN;
//			else
//				next = nums[i + 1];			
//
//			if (now > prev && now > next)
//				return i;
//		}
//		return 0;
//	}
//};
#pragma endregion

#pragma region binary_search_manner
class Solution {
public:
	int findPeakElement(vector<int>& nums) {

		int mid, l = 0, r = nums.size();
		while (true)
		{
			mid = (l + r) / 2;

			if (mid - 1 >= 0 && nums[mid - 1] > nums[mid])
				r = mid - 1;
			else if (mid + 1 < nums.size() && nums[mid + 1] > nums[mid])
				l = mid + 1;
			else
				return mid;
		}
	}
};
#pragma endregion


void q0162_tester()
{
	Solution s;
	vector<int> q;

	//q = { 1, 2, 3, 1 }; 
	//cout << s.findPeakElement(q) << endl; //expect 2

	//q = { 1, 2, 1, 3, 5, 6, 4 };
	//cout << s.findPeakElement(q) << endl; //expect 1 or 5

	//q = { 1, 2, 3, 4 };
	//cout << s.findPeakElement(q) << endl; //expect 3

	//q = { 4, 3, 2, 1 };
	//cout << s.findPeakElement(q) << endl; //expect 0

	//q = { 1, 2, 3, 4 , 5};
	//cout << s.findPeakElement(q) << endl; //expect 4

	//q = { 5, 4, 3, 2, 1 };
	//cout << s.findPeakElement(q) << endl; //expect 0

	q = { 2, 1 };
	cout << s.findPeakElement(q) << endl; //expect 0
}
