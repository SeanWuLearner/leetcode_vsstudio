#pragma once

#include "DebugUtils.h"
#include <algorithm>

class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int max = -1;
		int area;

		while (l < r)
		{
			area = min(height.at(l), height.at(r)) * (r - l);
			if (area > max)
				max = area;

			if (height.at(l) < height.at(r))
				l++;
			else
				r--;
		}
		return max;
	}
};

void q0011_tester() {
	Solution s;
	vector<int> q{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << s.maxArea(q) << endl;  //expect 49
}
