#pragma once

#include "DebugUtils.h"

#pragma region straightforward_bit_manipuation
//class Solution {
//public:
//	uint32_t reverseBits(uint32_t n) {
//		uint32_t ans = 0;
//		int times = 32;
//
//		while (times--)
//		{
//			ans <<= 1;
//			if (n & 0x1)
//				ans |= 0x1;
//			n >>= 1;
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region two_pointer_manner
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t lhs = 0x80000000, rhs = 0x1;
		uint32_t ans = 0;
		while (lhs > rhs)
		{
			if (n & lhs)
				ans |= rhs;
			if(n & rhs)
				ans |= lhs;

			lhs >>= 1;
			rhs <<= 1;
		}
		return ans;
	}
};
#pragma endregion

void q0190_tester()
{
	Solution s;
	cout << s.reverseBits(43261596) << endl; //expect 964176192
	cout << s.reverseBits(4294967293) << endl; //expect 3221225471
}



