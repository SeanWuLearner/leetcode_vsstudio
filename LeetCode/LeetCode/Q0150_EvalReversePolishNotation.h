#pragma once

#include "DebugUtils.h"

#pragma region ordinary_stack_implementation
//#include <stack>
//#include <string>
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> stk;
//		int op1, op2;
//
//		for (auto s : tokens)
//		{
//			if(s[s.size()-1] >= '0' && s[s.size() - 1] <= '9')
//				stk.push(std::stoi(s));
//			else
//			{
//				op2 = stk.top();
//				stk.pop();
//				op1 = stk.top();
//				stk.pop();
//
//				if (s == "+")
//					stk.push(op1 + op2);
//				else if (s == "-")
//					stk.push(op1 - op2);
//				else if (s == "*")
//					stk.push(op1 * op2);
//				else if (s == "/")
//					stk.push(op1 / op2);
//			}			
//		}
//		return stk.top();
//	}
//};
#pragma endregion 

#pragma region stack_with_lambda
#include <stack>
#include <string>
#include <unordered_map>
#include <functional>
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		int op1, op2;

		unordered_map<string, function<int(int, int)>> map = 
		{
			{ "+", [](int a, int b) {return a + b; } },
			{ "-", [](int a, int b) {return a - b; } },
			{ "*", [](int a, int b) {return a * b; } },
			{ "/", [](int a, int b) {return a / b; } }
		};

		for (auto s : tokens)
		{
			if (map.count(s) != 0)
			{
				op2 = stk.top();
				stk.pop();
				op1 = stk.top();
				stk.pop();
				stk.push(map[s](op1, op2));
			}
			else			
				stk.push(std::stoi(s));				
		}
		return stk.top();
	}
};
#pragma endregion 

void q0150_tester()
{
	Solution s;
	vector<string> q;

	q = { "2", "1", "+", "3", "*" };
	cout << s.evalRPN(q) << endl; //output : 9

	q = { "4", "13", "5", "/", "+" };
	cout << s.evalRPN(q) << endl; //output : 6

	q = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	cout << s.evalRPN(q) << endl; //output : 22
}



