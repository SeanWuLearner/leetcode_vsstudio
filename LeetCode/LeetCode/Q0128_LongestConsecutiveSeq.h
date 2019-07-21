
#pragma once

#include "DebugUtils.h"

#pragma region sorting_manner
//#include <algorithm>
//#include <set>
//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		set<int> rec;
//		for (auto i : nums)
//			rec.insert(i);
//
//		int max = 0;
//		int counter = 0;
//		int prev = *(rec.begin()) + 1; //init it NOT consecutive on purpose. 
//		for (auto i : rec)
//		{
//			if (prev + 1 == i)			
//				counter++;			
//			else
//			{
//				max = std::max(max, counter);
//				counter = 1;
//			}
//			prev = i;			
//		}
//		max = std::max(max, counter);
//
//		return max;
//	}
//};
#pragma endregion

#pragma region hash_set_manner
#include <algorithm>
#include <unordered_set>
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> rec;

		for (auto i : nums)
			rec.insert(i);

		int counter, max = 0;
		for (auto i : nums)
		{
			if (rec.count(i - 1) != 0)
				continue; //skip if it is not the head of streak.

			counter = 0;
			while (rec.count(i + counter) != 0)
				counter++;
			max = std::max(max, counter);
		}
		return max;
	}
};
#pragma endregion


void q0128_tester()
{
	Solution s;
	vector<int> q{ 100, 4, 200, 1, 3, 2 };
	cout << s.longestConsecutive(q) << endl; // expect 4
}


