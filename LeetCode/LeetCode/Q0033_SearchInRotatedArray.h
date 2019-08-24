#pragma once

#include "DebugUtils.h"

#pragma region my_naive_find_head_and_search
//class Solution {
//private:
//	int findHead(vector<int>& nums, int idx)
//	{
//		int l, m, r;
//		int n = nums.size();
//		l = (idx == 0) ? nums[n - 1] : nums[idx - 1];
//		m = nums[idx];
//		r = (idx == nums.size() - 1) ? nums[0] : nums[idx + 1];
//
//		if (m > l && m > r)
//			return idx + 1;
//		else if (m < l && m < r)
//			return idx;
//		else
//			return -1;
//	}
//
//public:
//	int search(vector<int>& nums, int target) {
//		int n = nums.size();
//		if (n == 0) return -1;
//		int mid, left = 0, right = n - 1;
//		int idx_head = -1;
//		
//		//binary search the head of sorted array.
//		if (n == 1)
//			idx_head = 0;
//		while (idx_head == -1)
//		{
//			mid = (left + right) >> 1;
//			idx_head = findHead(nums, mid);
//			if (nums[left] > nums[mid]) //find left
//				right = mid - 1;
//			else //find right					
//				left = mid + 1;
//		}
//
//		//head found! perform the binary search for our target
//		left = 0; right = n - 1;
//		int shifted_mid;
//		while (left <= right)
//		{
//			mid = (left + right) >> 1;
//			shifted_mid = (mid + idx_head) % n;			
//			if (nums[shifted_mid] == target)
//				return shifted_mid;
//			else if (nums[shifted_mid] > target) // find left			
//				right = mid  - 1;
//			else //find right
//				left = mid + 1;
//		}		
//		return -1;
//	}
//};
#pragma endregion

#pragma region find_head_concisely
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		int n = nums.size();		
//		int mid, left = 0, right = n - 1;
//		int idx_head = -1;
//
//		//binary search the head of sorted array.
//		while (left < right)
//		{
//			mid = (left + right) / 2;
//			if (nums[mid] > nums[right]) left = mid + 1;
//			else right = mid;
//		}
//		idx_head = left;
//
//		//head found! perform the binary search for our target
//		left = 0; right = n - 1;
//		int shifted_mid;
//		while (left <= right)
//		{
//			mid = (left + right) / 2;
//			shifted_mid = (mid + idx_head) % n;
//			if (nums[shifted_mid] == target)
//				return shifted_mid;
//			else if (nums[shifted_mid] > target) // find left			
//				right = mid - 1;
//			else //find right
//				left = mid + 1;
//		}
//		return -1;
//	}
//};
#pragma endregion

#pragma region smart_one_pass_solution
/*consider whether target is on the same side of mid
if same side => perform the ordinary binary search
if different side => move according to the relationship between target and [n-1]
*/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int mid, lo = 0, hi = n - 1;

		while (lo < hi)
		{
			mid = (lo + hi) / 2;

			//if same side, ordinary binary search
			if ((nums[mid] - nums[n - 1]) * (target - nums[n - 1]) > 0)
			{
				if (target > nums[mid])
					lo = mid + 1;
				else
					hi = mid;
			}
			//if they are on opposite sides
			else if (target > nums[n - 1])
				hi = mid;
			else
				lo = mid + 1;
		}

		if (n == 0 || nums[lo] != target)
			return -1;
		else
			return lo;
	}
};
#pragma endregion

void q0033_tester()
{
	Solution s;
	vector<int> q;


	q = { 4, 5, 6, 7, 0, 1, 2 };
	cout << s.search(q, 0) << endl; //expect 4

	cout << s.search(q, 3) << endl; //expect -1

	q = { 1 };
	cout << s.search(q, 0) << endl; //expect -1


}
