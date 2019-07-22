#pragma once

#include "DebugUtils.h"

#pragma region odinary solution
//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		if (n == 0)
//			return false;
//
//		while (n != 1)
//		{
//			if (n % 3 != 0)
//				return false;
//			n /= 3;
//		}
//		return true;
//	}
//};
#pragma endregion

#pragma region genius modular method
//class Solution {
//public:
//	bool isPowerOfThree(int n) {
//		if (n <= 0) return false;
//		return 1162261467 % n == 0;  //maxPowerOfThree = 1162261467
//	}
//};
#pragma endregion

#pragma region cheating method
#include <set>
class Solution {
public:
	bool isPowerOfThree(int n) {
		set<int> power{ 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 };
		return power.find(n) != power.end();
	}
};
#pragma endregion


void Q0326_tester()
{
	Solution s;	

	cout << s.isPowerOfThree(27) << endl; // output: true
	cout << s.isPowerOfThree(0) << endl; // output: false
	cout << s.isPowerOfThree(9) << endl; // output: true
	cout << s.isPowerOfThree(45) << endl; // output: false
}

