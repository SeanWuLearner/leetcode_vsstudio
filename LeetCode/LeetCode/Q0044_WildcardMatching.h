#pragma once

#include "DebugUtils.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		int i = 0, j = 0;
		int starj = -1, stari;

		while (i < m)
		{			
			if (j < n && (p[j] == '?' || p[j] == s[i]))
			{
				i++; j++;
			}
			else if (j < n && p[j] == '*')
			{
				starj = ++j;
				stari = i;
			}
			else if (starj != -1)  // it will reach here, if j >=n
			{
				j = starj;
				i = ++stari;
			}
			else
				return false;
		}

		while (j < n)
		{
			if (p[j++] != '*')
				return false;
		}
		return true;
	}
};

void q0044_tester()
{
	Solution sol;
	string s, p;

	s = "aa";
	p = "a";
	cout << sol.isMatch(s, p) << endl; //return false

	s = "aa";
	p = "*";
	cout << sol.isMatch(s, p) << endl; //return true

	s = "cb";
	p = "?a";
	cout << sol.isMatch(s, p) << endl; //return false
	
	s = "cb";
	p = "?b";
	cout << sol.isMatch(s, p) << endl; //return true

	s = "abceb";
	p = "*a*b";
	cout << sol.isMatch(s, p) << endl; //return true

	s = "aaaaaaaaaaaaaaac";
	p = "*aaaaaaaaaaaaaaa*b";
	cout << sol.isMatch(s, p) << endl; //return false
	
		
}
