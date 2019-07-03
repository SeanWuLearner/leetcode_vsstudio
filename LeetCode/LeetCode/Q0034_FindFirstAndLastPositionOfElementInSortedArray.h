#pragma once

#include "DebugUtils.h"

#pragma region sean_1st_version
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) 
//	{		
//		if (nums.size() == 0)
//			return { -1,-1 };
//
//		int l = 0, r = nums.size() - 1;
//		int mid = (r + l) / 2;
//		int hit = -1;
//
//		//binary search first
//		while (l < r)
//		{			
//			if (nums[mid] == target)
//			{
//				hit = mid;
//				break;
//			}
//			else if (nums[mid] < target)				
//				l = mid + 1; //don't have to perform boundary check here because L go right, R go left, it will fail the l < r before buffer overrun.
//			else
//				r = mid -1; //don't have to perform boundary check here because the same reason..
//			mid = (r + l) / 2; 
//		}
//		
//		if (l == r && nums[l] == target)
//			return { l,l };
//
//		if (hit == -1)		
//			return { -1,-1 };
//			
//
//		//extend L
//		l = mid;
//		while (l-1 >= 0 && nums[l-1] == target)
//			l--;		
//
//		//extend R
//		r = mid;
//		while (r+1 < nums.size() && nums[r+1] == target)
//			r++;
//		
//		return { l, r };		
//	}
//};
#pragma endregion

#pragma region leetcode_least_mem_consumption
//
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1;
//		vector<int> res(2, -1);
//		if (nums.size() == 0)
//			return res;
//		while (left < right) {
//			int mid = left + (right - left) / 2;
//			if (nums[mid] < target)
//				left = mid + 1;
//			else
//				right = mid;
//		}
//		if (nums[left] != target)
//			return res;
//		res[0] = left;
//		right = nums.size() - 1;
//		while (left < right) {
//			int mid = left + (right - left) / 2 + 1;
//			if (nums[mid] > target)
//				right = mid - 1;
//			else
//				left = mid;
//		}
//		res[1] = right;
//
//		return res;
//	}
//};
#pragma endregion

#pragma region paraphrase_sample_binary_search_answer
class Solution {
	int find_insetion_idx(const vector<int>& nums, int target, bool find_left)//bool find_right)
	{
		/*the different init value to var h ONLY make the difference while (l = h), ie. nums.size()=1.*/
		int l = 0, h = nums.size(); //error: nums.size()-1 
		int mid;

		while (l < h)
		{
			mid = (l + h) / 2;

			if (nums[mid] > target || (find_left && nums[mid] == target))
				h = mid;
			else
				l = mid + 1;

			/*  this will stock while nums=[1, 3], target = 2
			if (nums[mid] < target || (find_right && nums[mid] == target))
			l = mid;
			else
			h = mid - 1;
			*/
		}

		return l;
	}

public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		if (nums.size() == 0)
			return{ -1,-1 };

		int l = find_insetion_idx(nums, target, true);
		if (l == nums.size() || nums[l] != target)
			return{ -1, -1 };

		return{ l, find_insetion_idx(nums, target, false) - 1 };

	}
};
#pragma endregion


void q0034_tester()
{
	Solution s;
	vector<int> q;
	int tar;
	vector<int> ans;

	q = { 5,7,7,8,8,10 };
	tar = 8;
	ans = s.searchRange(q, tar);
	print(ans); //expect 3,4

	tar = 6;
	ans = s.searchRange(q, tar);
	print(ans); // expect -1,-1

	q = { 1 };
	tar = 1;
	ans = s.searchRange(q, tar);
	print(ans); //expect [0,0]

	q = { 1,4 };
	tar = 4;
	ans = s.searchRange(q, tar);
	print(ans); //expect [1, 1]
}