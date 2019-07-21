#pragma once

#include "DebugUtils.h"

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;

		int n = s1.size();
		if (s1.size() != s2.size() || (n == 1 && s1 != s2))
			return false;

		//additiona check : faster or slower?
		int counter[26] = { 0 };
		for (int i = 0; i < s1.size(); i++)
		{
			counter[s1[i] - 'a']++;
			counter[s2[i] - 'a']--;
		}

		for (auto i : counter)
			if (i != 0)
				return false;

		for (int i = 1; i < n; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
				return true;
		}
		return false;
	}
};

void q0087_tester()
{
	Solution s;

	cout << s.isScramble("great", "rgeat") << endl; //expect true
	cout << s.isScramble("abcde", "caebd") << endl; //expect false
	cout << s.isScramble("bab", "abb") << endl; //expect true
	cout << s.isScramble("bba", "abb") << endl; //expect true

}
