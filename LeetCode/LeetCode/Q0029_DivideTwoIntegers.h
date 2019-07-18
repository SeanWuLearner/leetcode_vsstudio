#pragma once

#include "DebugUtils.h"

#pragma region sean_1st_edition
//sean: I realize it would be buggy while INT_MIN occurs if don't use LONG LONG. That include many other answers on leetcode.
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		bool sign = false;
//
//		long long lldividend = dividend, lldivisor = divisor;
//
//		if (dividend < 0)
//		{
//			sign = !sign;
//			lldividend = -lldividend;
//		}
//
//		if (divisor < 0)
//		{
//			sign = !sign;
//			lldivisor = -lldivisor;
//		}
//			
//		long long mul_div;
//		long long ans = 0;
//		long long quo;
//
//		while (lldividend >= lldivisor)
//		{
//			quo = 1;
//			mul_div = lldivisor;
//
//			while (mul_div <= lldividend)
//			{
//				quo <<= 1;
//				mul_div <<= 1;
//			}
//			ans += quo >> 1;
//			lldividend -= mul_div >> 1;
//		}
//
//
//
//		if (sign)			
//			ans = -ans;
//		
//		if (ans < INT_MIN || ans > INT_MAX)
//			return INT_MAX;
//		else
//			return ans;
//	}
//};
#pragma endregion

#pragma region least_mem_consumption_on_leetcode
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return 0;
		bool sign = (dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0);
		int l = 0, r = 31;
		long long d = divisor;
		long long n = dividend;
		if (d < 0) d = -d;
		if (n < 0) n = -n;
		while (l < r) {
			int k = (l + r + 1) / 2;
			long long res = d << k;
			if (res > n) r = k - 1;
			else if (res <= n) l = k;
		}
		long long ans = 0;
		while (n >= d) {
			if (n >= (d << l)) {
				ans += 1LL << l;
				n -= d << l;
			}
			else {
				l--;
			}
		}
		if (!sign) ans = -ans;
		if (ans >= (1LL << 31)) ans = (1LL << 31) - 1; // e.g., -2147483648 / -1
		return ans;
	}

	// More concise code in python
	// def divide(self, dividend, divisor):
	//     sig = (dividend < 0) == (divisor < 0)
	//     a, b, res = abs(dividend), abs(divisor), 0
	//     while a >= b:
	//         x = 0
	//         while a >= b << (x + 1): x += 1
	//         res += 1 << x
	//         a -= b << x
	//     return min(res if sig else -res, 2147483647)
};
#pragma endregion

void q0029_tester()
{
	Solution s;
	cout << s.divide(10, 3) << endl; //expect 3
	cout << s.divide(7, -3) << endl; //expect -2
	cout << s.divide(INT_MIN, -1) << endl; //expect 2^31 - 1
	cout << s.divide(INT_MIN, -2) << endl; //expect 	


}
