#pragma once

#include "DebugUtils.h"
#include <stack>

class Solution {
public:
	bool isValid(string s) {
		stack<char> tracer;
		tracer.push('d'); // push a dummy element in case of dealing with right parenthesis first.

		for (auto c : s)
		{
			switch (c) {
			case '(':
			case '[':
			case '{':
				tracer.push(c);
				break;
			case ')':
				if (tracer.top() != '(')
					return false;
				tracer.pop();
				break;			
			case ']':
				if (tracer.top() != '[')
					return false;
				tracer.pop();
				break;				
			case '}':
				if (tracer.top() != '{')
					return false;
				tracer.pop();
				break;
			}
		}		
		return (tracer.size() == 1); //valid if only dummy element left.

	}
};

void q0020_tester()
{
	Solution s;
	
	cout << s.isValid("]") << endl;
	//cout << s.isValid("()") << endl; //expect 'true'
	//cout << s.isValid("()[]{}") << endl; //expect 'true'
	//cout << s.isValid("(]") << endl; //expect 'false'
	//cout << s.isValid("([)]") << endl; //expect 'false'
	//cout << s.isValid("{[]}") << endl; //expect 'true'
	
}