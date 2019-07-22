#pragma once

#include "DebugUtils.h"

#pragma region sean_naive_solution
//class Solution {
//private:
//	vector<string> ans_;
//	const char letter[2] = {'(', ')'};
//
//private:
//	void helper(string s, int l_cnt, int r_cnt, int balance, int max)
//	{		
//		if (l_cnt == 0 && r_cnt == 0)
//			return;
//
//		s += ' ';
//		for (int i = 0; i < sizeof(letter); i++)
//		{
//			s.back() = letter[i];			
//
//			if (letter[i] == ')')
//			{
//				if (balance == 0 || r_cnt == 0)
//					continue;
//
//				if (l_cnt == 0 && r_cnt == 1)
//					ans_.push_back(s + ")");
//				else
//					helper(s, l_cnt, r_cnt - 1, balance - 1, max);
//			}
//			else
//			{
//				if (balance == max || l_cnt == 0)
//					continue;
//				
//				if (l_cnt == 1 && r_cnt == 0)
//					ans_.push_back(s + ")");
//				else
//					helper(s, l_cnt - 1, r_cnt, balance + 1, max);
//			}			
//		}		
//	}
//public:
//	vector<string> generateParenthesis(int n) {
//		if (n == 1) return { "()" };
//		ans_.clear();		
//		helper("(", n-1, n-1, 1, n );
//		return ans_;
//	}
//};
#pragma endregion

#pragma region fancy_backtracing_code
class Solution {
private:
	vector<string> ans_;

	void backtrace(string s, int open, int close, int max)
	{
		if (s.length() == 2 * max)
		{
			ans_.push_back(s);
			return;
		}
			
		if (open < max)
			backtrace(s+"(", open + 1, close, max);
		if (close < open)
			backtrace(s+")", open, close + 1, max);
	}
public:
	vector<string> generateParenthesis(int n) 
	{
		ans_.clear();
		backtrace("", 0, 0, n);
		return ans_;
	}
};
#pragma endregion


void q0022_tester()
{
	Solution s;
	vector<string> ans;

	ans = s.generateParenthesis(3);
	print(ans);
}
