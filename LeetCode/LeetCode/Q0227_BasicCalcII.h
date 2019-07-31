#pragma once

#include "DebugUtils.h"
#include <string>

#pragma region two_vector_manner
//class Solution {
//public:
//	int calculate(string s) {
//		vector<int> nums;
//		vector<char> op;
//		string sint;
//
//		for (auto it = s.begin(); it != s.end(); it++)
//		{
//			if (*it >= '0' && *it <= '9')
//			{
//				sint += *it;
//			}
//							
//			if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || (it + 1) == s.end())
//			{
//				nums.push_back(stoi(sint));
//				sint.clear();
//
//				//perform MUL and DIV first
//				if (op.empty() == false && (op.back() == '*' || op.back() == '/'))
//				{
//					int op2 = nums.back();
//					nums.pop_back();
//					int op1 = nums.back();
//					nums.pop_back();
//
//					if (op.back() == '*')
//						nums.push_back(op1 * op2);
//					else
//						nums.push_back(op1 / op2);
//
//					op.pop_back();
//				}
//
//				if (it+1 != s.end())
//					op.push_back(*it);
//			}
//		}
//		
//		//2nd round, deal with ADD / SUB
//		int ans = nums[0];
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (op[i - 1] == '+')
//				ans += nums[i];
//			else
//				ans -= nums[i];
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region one_stack_manner
//#include <stack>
//#include <ctype.h>
//class Solution {
//public:
//	int calculate(string s) {
//		vector<int> nums;
//		int num = 0;
//		char sign = '+'; //the first op
//		int tmp;
//		
//		for (auto it = s.begin(); it != s.end(); it++)
//		{
//			if (isdigit(*it))			
//				num = num * 10 + (*it - '0');
//			
//			if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || (it + 1) == s.end())
//			{
//				if (sign == '+')
//					nums.push_back(num);
//				if (sign == '-')
//					nums.push_back(-num);
//				if (sign == '*')
//				{
//					tmp = nums.back();
//					nums.pop_back();
//					nums.push_back(tmp * num);
//				}					
//				if (sign == '/')
//				{
//					tmp = nums.back();
//					nums.pop_back();
//					nums.push_back(tmp / num);
//				}					
//				num = 0;
//				sign = *it;
//			}
//		}
//
//		//deal with ADD/SUB
//		int ans=0;
//		for (auto i : nums)		
//			ans += i;
//				
//		return ans;
//	}
//};
#pragma endregion

#pragma region genius_const_mem
#include <sstream>
#include <iostream>
class Solution {
public:
	int calculate(string s) {
		istringstream ss{ "+" + s + "+" };
		int total = 0, term = 0, term2;
		char op;

		while (ss >> op)
		{
			if (op == '+' || op == '-')
			{
				total += term;
				ss >> term;
				term = (op == '-') ? -term : term;
			}
			else
			{
				ss >> term2;
				if (op == '*')
					term *= term2;
				else
					term /= term2;
			}
		}
		return total;
	}
};
#pragma endregion

void q0227_tester()
{
	Solution s;

	cout << s.calculate("3+2*2") << endl; //7
	cout << s.calculate(" 3/2") << endl; //1
	cout << s.calculate(" 3+5 / 2 ") << endl; //5
	cout << s.calculate("0") << endl; //0

}
