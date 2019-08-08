#pragma once
#include "DebugUtils.h"
#include <string>

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int i = INT_MAX, j = INT_MAX;
		for (auto n : nums)
		{
			if (n <= i)
				i = n;
			else if (n <= j)
				j = n;
			else
				return true;
		}
		return false;
	}
};

void q0334_tester()
{
	Solution s;
	vector<int> q;

	q = { 1, 2, 3, 4, 5 };
	cout << s.increasingTriplet(q) << endl; // true

	q = { 5, 4, 3, 2, 1 };
	cout << s.increasingTriplet(q) << endl; //flase;

}
