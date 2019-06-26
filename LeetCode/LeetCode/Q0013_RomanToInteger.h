#pragma once

#include "DebugUtils.h"
#include <string>
#include <unordered_map>

#pragma region sean_1st_edition
class Solution {
private:
	unordered_map<char, int> mTable = {
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 }
	};
public:
	int romanToInt(string s) {
		int prev = 10000;
		int now;
		int sum = 0;

		if (s.size() == 0)
			return 0;

		for (auto c : s)
		{
			now = mTable.at(c);
			if (prev < now)
			{
				sum += now - prev * 2;
			}
			else
			{
				sum += now;
			}
			prev = now;
		}
		return sum;
	}
};
#pragma endregion

#pragma region reverse_alternative_from_leetcode
class Solution {
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> T = { { 'I' , 1 },
		{ 'V' , 5 },
		{ 'X' , 10 },
		{ 'L' , 50 },
		{ 'C' , 100 },
		{ 'D' , 500 },
		{ 'M' , 1000 } };
		int sum = T[s.back()];
		for (int i = s.size() - 2; i >= 0; i--)
		{
			if (T[s[i]] < T[s[i + 1]])
				sum -= T[s[i]];
			else
				sum += T[s[i]];
		}
		return sum;
	}
};

#pragma endregion

void q0013_tester()
{
	Solution s;
	string q = "XII";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 12

	q = "XXVII";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 27

	q = "III";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 3

	q = "IV";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 4

	q = "IX";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 9

	q = "LVIII";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 58

	q = "MCMXCIV";
	cout << q << "==" << s.romanToInt(q) << endl; //expect 1994
}