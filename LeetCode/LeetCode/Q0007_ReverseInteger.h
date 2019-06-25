#pragma once


#include "DebugUtils.h"

#include <climits>

class Solution {
public:
	int reverse(int x) {
		long long ret = 0;

		while (x != 0)
		{
			ret *= 10;
			ret += (x % 10);
			x /= 10;
		}
		if (ret > INT_MAX || ret < INT_MIN)
			return 0;
		else
			return (int)ret;
	}
};

void q0007_tester()
{
	Solution s;

	cout << s.reverse(123) << endl;
}
