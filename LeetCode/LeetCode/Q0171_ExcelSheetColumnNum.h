
#pragma once
#include "DebugUtils.h"
#include <string>

#pragma region my_solution
//class Solution {
//public:
//	int titleToNumber(string s) {
//		long radix = 1;
//		long sum = 0;
//		for (auto c = s.rbegin(); c != s.crend(); c++)
//		{
//			sum += (*c - 'A' + 1) * radix;
//			radix *= 26;
//		}
//		return static_cast<int>(sum);
//	}
//};
#pragma endregion

#pragma region my_solution
class Solution {
public:
	int titleToNumber(string s) {		
		int result = 0;
		for (auto c : s)
		{
			result = result * 26 + c - 'A' + 1;
		}
		return static_cast<int>(result);
	}
};
#pragma endregion

void q0171_tester()
{
	Solution s;

	string q;

	q = "A";
	cout << s.titleToNumber(q) << endl; //1

	q = "AB";
	cout << s.titleToNumber(q) << endl; //28

	q = "CFDGSXM";
	cout << s.titleToNumber(q) << endl; //704
}
