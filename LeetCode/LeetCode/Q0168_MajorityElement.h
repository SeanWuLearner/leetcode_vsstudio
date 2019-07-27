#pragma once

#include "DebugUtils.h"

#pragma region hash_map method
//#include <unordered_map>
//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		unordered_map<int, int> cnt;
//		int target = nums.size() / 2;
//
//		for (auto i : nums)
//		{
//			cnt[i] = (cnt.count(i) == 0) ? 1 : cnt[i] + 1;
//			if (cnt[i] > target)
//				return i;
//		}
//		return 0;
//	}
//};
#pragma endregion

#pragma region Boyer-Moore Voting Algorithm
class Solution {
public:
	int majorityElement(vector<int>& nums) {

		int candidate, count = 0;

		for (auto i : nums)
		{
			if (count == 0)
				candidate = i;

			count += (i == candidate) ? 1 : -1;
		}
		return candidate;
	}
};
#pragma endregion

void q0168_tester()
{
	Solution s;

	vector<int> q;

	q = { 3, 2, 3 };
	cout << s.majorityElement(q) << endl; //3

	q = { 2, 2, 1, 1, 1, 2, 2 };
	cout << s.majorityElement(q) << endl; //2


}
