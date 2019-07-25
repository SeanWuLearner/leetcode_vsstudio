#pragma once

#include "DebugUtils.h"

#pragma region using_stl_directly
//#include <algorithm>
//#include <functional>
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) 
//	{		
//		std::nth_element(nums.begin(), next(nums.begin(), k-1), nums.end(), std::greater<int>());		
//		return nums[k-1];
//	}
//};
#pragma endregion

#pragma region Partition_manner_from_quicksort
class Solution {
private:
	int partition(vector<int>& nums, int left, int right)
	{
		int pivot = nums[right], l = left, r = right - 1;
		while (l <= r)
		{
			if (nums[l] < pivot && nums[r] > pivot)
				std::swap(nums[l++], nums[r--]);

			if (nums[l] >= pivot)
				l++;

			if (nums[r] <= pivot)
				r--;
		}
		std::swap(nums[right], nums[l]);
		return l;
	}
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		int n = nums.size();
		int idx, left = 0, right = n - 1;
		while (true)
		{
			idx = partition(nums, left, right);
			if (idx == k - 1)
				return nums[k - 1];
			else if (idx < k - 1)
				left = idx + 1;
			else
				right = idx - 1;

		}
	}
};
#pragma endregion

void q0215_tester()
{
	Solution s;

	vector<int> q;
	q = { 3, 2, 1, 5, 6, 4 };
	cout << s.findKthLargest(q, 2) << endl;  //output : 5

	q = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	cout << s.findKthLargest(q, 4) << endl; //output : 4
}
