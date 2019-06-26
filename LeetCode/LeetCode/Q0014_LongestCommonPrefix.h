#pragma once

#include "DebugUtils.h"
#include <string>

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int c_len = 0;

		if (strs.size() == 0)
			return string();

		if (strs.size() == 1)
			return strs[0];

		for (char c : strs[0])
		{
			for (int i = 1; i < strs.size(); i++)
			{
				if ((strs[i].size() <= c_len))
					return strs[0].substr(0, c_len);

				if (strs[i].at(c_len) != c)
					return strs[0].substr(0, c_len);
			}
			c_len++;
		}
		return strs[0];
	}
};

void q0014_tester() {
	Solution s;
	vector<string> q{ "flower", "flow", "flight" };
	cout << s.longestCommonPrefix(q) << endl;  //expect 'fl'

	q = { "dog", "racecar", "car" };
	cout << s.longestCommonPrefix(q) << endl;  //expect ''

	q = { "aaa", "aa", "aaa" };
	cout << s.longestCommonPrefix(q) << endl;  //expect 'aa'

}
