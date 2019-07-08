#pragma once

#include "DebugUtils.h"

#pragma region swap_the_order_bin
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {

		//nums.push_back(0);

		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}

		for (int i = 0; i < n; i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};
#pragma endregion


#pragma region hash_the_occurance_times
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {		
//
//		nums.push_back(0);
//		int n = nums.size();
//
//		//clear unwanted num
//		for (auto &i : nums)
//			if (i < 0 || i >= n)
//				i = 0;
//
//		//count the freq of occurance of num (mul by n)
//		for (int i = 0; i < nums.size(); i++)
//			if (nums[i] != 0)
//				nums[nums[i] % n] += n;
//		
//		//find missing one
//		for (int i = 1; i < nums.size(); i++)
//			if (nums[i] / n == 0)
//				return i;
//
//		return nums.size();
//	}
//};
#pragma endregion

void q0041_tester()
{
	Solution s;
	vector<int> q;

	q = { 1, 2, 0 };
	cout << s.firstMissingPositive(q) << endl; //output: 3

	q = { 3, 4, -1, 1 };
	cout << s.firstMissingPositive(q) << endl; //output: 2

	q = { 7, 8, 9, 11, 12 };
	cout << s.firstMissingPositive(q) << endl; //output: 1

	q = { 1 };
	cout << s.firstMissingPositive(q) << endl; //output: 2

	q = { 1, 1 };
	cout << s.firstMissingPositive(q) << endl; //output: 2
}
