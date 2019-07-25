#pragma once

#include "DebugUtils.h"
#include <string>

#include <unordered_map>

#pragma region sean_edition
//class Solution {	
//public:
//	string fractionToDecimal(int numerator, int denominator)
//	{
//		if (denominator == 0) return "";
//		if (numerator == 0) return "0";
//
//		unordered_map<long, int> map;
//		string ans;
//		bool has_dotted = false;
//		int repeat_idx = -1;
//
//		if (numerator >= 0 ^ denominator >= 0)
//			ans += "-";
//
//		long num = labs(numerator), den = labs(denominator);
//
//		do
//		{
//			if (map.count(num) != 0)
//			{//repeation occur
//				repeat_idx = map[num];
//				break;
//			}
//			
//			ans += std::to_string(num / den);
//			map[num] = ans.size() - 1; 									
//			num %= den;
//
//			if (has_dotted == false && num != 0)
//			{
//				ans.push_back('.');
//				has_dotted = true;
//			}
//			num *= 10;
//		} while (num != 0);
//
//		//add parentheses
//		if (repeat_idx != -1)
//		{
//			ans.insert(repeat_idx, "(");
//			ans.push_back(')');
//		}
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region cleaner code
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		if (denominator == 0) return "";
		if (numerator == 0) return "0";

		string ans;
		ans += (numerator >= 0 ^ denominator >= 0) ? "-" : "";

		long num = labs(numerator), den = labs(denominator);

		//integer part
		ans += std::to_string(num / den);
		num %= den;
		if (num == 0)
			return ans;

		//fraction part
		unordered_map<long, int> map;	//it can use <int, int> instead also.	
		ans += ".";
		while (num != 0)
		{
			num *= 10;
			if (map.count(num) != 0)
			{//repeation occur
				ans.insert(map[num], "(");
				ans.push_back(')');
				return ans;
			}

			ans += std::to_string(num / den);
			map[num] = ans.size() - 1;
			num %= den;
		}

		return ans;
	}
};
#pragma endregion

void q0166_tester()
{
	Solution s;

	cout << s.fractionToDecimal(1, 2) << endl; // 0.5
	cout << s.fractionToDecimal(2, 1) << endl; // 2

	cout << s.fractionToDecimal(30, 2) << endl; // 15

	cout << s.fractionToDecimal(2, 3) << endl; // 0.(6)

	cout << s.fractionToDecimal(100, 3) << endl; // 33.(3)

	cout << s.fractionToDecimal(0, 3) << endl; // 0

	cout << s.fractionToDecimal(-1, INT_MIN) << endl; //0.0000000000000000000000000000001

}
