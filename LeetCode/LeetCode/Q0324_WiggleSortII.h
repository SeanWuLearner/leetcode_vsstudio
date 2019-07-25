#pragma once

#include "DebugUtils.h"

#pragma region O(N) mem for sort out the ans
#include <algorithm>
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		//find median
		auto mid_it = nums.begin() + n / 2;

		//refer to Q0215 for implementation
		std::nth_element(nums.begin(), mid_it, nums.end());

		int big = 1, small = (n % 2 == 0) ? n - 2 : n - 1;
		vector<int> ans(n);

		for (int i = 0; i < n; i++)
		{
			if (nums[i] < *mid_it)
			{
				ans[small] = nums[i];
				small -= 2;
			}
			else if (nums[i] > *mid_it)
			{
				ans[big] = nums[i];
				big += 2;
			}
		}

		while (small >= 0)
		{
			ans[small] = *mid_it;
			small -= 2;
		}

		while (big < n)
		{
			ans[big] = *mid_it;
			big += 2;
		}

		nums = ans;
	}
};
#pragma endregion

#pragma region //nth_element + color_sort + 3way_partition methods TIME: O_n, MEM: O_1
//#include <algorithm>
//class Solution {
//public:
//	void wiggleSort(vector<int>& nums) {
//		int n = nums.size();
//		//find median
//		int mid_idx = n >> 1;
//
//		//refer to Q0215 for implementation
//		std::nth_element(nums.begin(), nums.begin() + mid_idx, nums.end());
//
//		//color idx: for example, for n=6, it will generate 1,3,5,2,4,6 in order.
//		#define NUMS_COLOR(i) nums[ (1 + i * 2) % (n | 1) ]
//		
//		int left = 0, i = 0, right = n - 1;
//		int mid = nums[mid_idx];
//		while (i <= right)
//		{
//			if (NUMS_COLOR(i) < mid)
//				std::swap(NUMS_COLOR(i), NUMS_COLOR(right--));
//			else if (NUMS_COLOR(i) > mid)
//				std::swap(NUMS_COLOR(i++), NUMS_COLOR(left++));			
//			else
//				i++;
//		}
//	}
//};
#pragma endregion

void Q0324_tester()
{
	Solution s;
	vector<int> q;

	q = { 1, 5, 1, 1, 6, 4 };
	s.wiggleSort(q);
	print(q);

	q = { 1, 3, 2, 2, 3, 1 };
	s.wiggleSort(q);
	print(q);

	q = { 1, 1, 2, 1, 2, 2, 1 };
	s.wiggleSort(q);
	print(q);

	q = { 1, 3, 2, 2, 3, 1 };
	s.wiggleSort(q);
	print(q);

}
