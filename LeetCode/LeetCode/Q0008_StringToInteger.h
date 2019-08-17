#pragma once

#include "DebugUtils.h"

#pragma region my_sol
//class Solution {
//public:
//	int myAtoi(string str) {
//		long result = 0;
//		int neg = 0;
//		bool digit = false;
//
//		for (auto c : str)
//		{			
//			if (c == '+' || c == ' ' || c == '-')
//			{
//				if (result != 0 || neg != 0 || digit)
//					break;
//				
//				if (c == '+')
//					neg = 1;
//
//				if (c == '-')
//					neg = -1;
//			}						
//			else if (c >= '0' && c <= '9')			
//			{		
//				digit = true;
//				result = (result * 10 + (c - '0'));
//				if (result > INT_MAX)
//					break;
//			}					
//			else
//				break;			
//		}
//		if (neg == -1)
//			result = -result;
//
//		if (result >= INT_MAX)
//			return INT_MAX;
//		else if (result <= INT_MIN)
//			return INT_MIN;
//		else
//			return result;
//	}
//};
#pragma endregion

#pragma region concise_sol
class Solution {
public:
	int myAtoi(string str) {
		long res = 0;
		bool neg = false;
		int i = 0;

		//stage 1: ignore whitespace
		while (str[i] == ' ') { i++; }

		//stage 2: sign
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				neg = true;
			i++;
		}

		//stage 3: digit
		while (i < str.size())
		{
			if (str[i] >= '0' && str[i] <= '9')
				res = res * 10 + (str[i] - '0');
			else
				break;

			if (res > INT_MAX)
				break;
			i++;
		}

		if (neg)
			res = -res;

		if (res > INT_MAX)
			return INT_MAX;
		else if (res < INT_MIN)
			return INT_MIN;
		else
			return res;
	}
};
#pragma endregion

void q0008_tester()
{
	Solution s;
	string q;

	q = "42";
	cout << s.myAtoi(q) << endl; // expect 42

	q = "   -42";
	cout << s.myAtoi(q) << endl; // expect -42

	q = "4193 with words";
	cout << s.myAtoi(q) << endl; // expect 4193

	q = "words and 987";
	cout << s.myAtoi(q) << endl; // expect 0

	q = "-91283472332";
	cout << s.myAtoi(q) << endl; // expect INT_MIN

	q = "+-2";
	cout << s.myAtoi(q) << endl; // expect 0

	q = "0-1";
	cout << s.myAtoi(q) << endl; // expect 0
}

