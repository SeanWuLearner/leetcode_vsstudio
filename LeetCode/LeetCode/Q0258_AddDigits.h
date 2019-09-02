#pragma once

#include "DebugUtils.h"

#pragma region ordinary_iteration
//class Solution {
//public:
//	int addDigits(int num) {
//		int sum = 0;
//
//		while (num >= 10)
//		{
//			while (num != 0)
//			{
//				sum += num % 10;
//				num /= 10;
//			}
//			num = sum;
//			sum = 0;
//		}
//		return num;
//	}
//};
#pragma endregion

#pragma region digital_root
class Solution {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};
#pragma endregion


void q0258_tester()
{
	Solution s;
	cout << s.addDigits(38) << endl; //expect 2

	cout << s.addDigits(10) << endl; //expect 1
}
