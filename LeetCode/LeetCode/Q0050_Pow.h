#pragma once

#include "DebugUtils.h"

#pragma region double_manner
//class Solution {
//public:
//	double myPow(double x, int n) {		
//		bool is_neg = false;
//		
//		long ln = n;
//		if (n < 0)
//		{
//			is_neg = true;
//			ln = -ln;
//		}
//
//		double ans = 1;		
//		while (ln != 0)
//		{
//			long times = 1;
//			double tmp = x;
//			while((times << 1) < ln)
//			{
//				tmp *= tmp;
//				times <<= 1;
//			}
//			ans *= tmp;
//			ln -= times;
//		}
//		
//		//handle reciprocal case
//		if (is_neg)		
//			ans = 1 / ans;		
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region bit_manipulation
class Solution {
public:
	double myPow(double x, int n) {		
		long abs_n = n;
		if (n < 0)
		{
			x = 1 / x;
			abs_n = -n;
		}		

		double ans = 1;

		while (abs_n != 0)
		{
			if (abs_n & 0x1)
				ans *= x;
			x *= x;
			abs_n >>= 1;
		}
		return ans;
	}
};

#pragma endregion

void q0050_tester()
{
	Solution s;

	cout << s.myPow(2.0, 10) << endl; //1024.0
	cout << s.myPow(2.1, 3) << endl; //9.26100
	cout << s.myPow(2.0, -2) << endl; //0.24


}
