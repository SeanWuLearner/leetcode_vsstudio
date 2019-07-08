#pragma once

#include "DebugUtils.h"
#include <string>

#pragma region sort_string_method
//#include <algorithm>
//class Solution {
//public:
//	static bool compFunc(string a, string b)
//	{
//		return (a + b) > (b + a);
//			
//	}
//	string largestNumber(vector<int>& nums) {
//		if (nums.size() == 0)
//		return "";
//		
//		vector<string> numsstr;
//		for (auto i : nums)
//			numsstr.push_back(std::to_string(i));
//
//		std::sort(numsstr.begin(), numsstr.end(), compFunc);
//		
//		string ans;
//		for (auto s : numsstr)
//			ans.append(s);
//
//		if (ans[0] == '0')
//			ans = "0";
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region sort_with_num_faster
#include <algorithm>
class Solution {
public:
	static int getLen(int a)
	{
		int len = 0;
		do {
			a /= 10;
			len++;
		} while (a != 0);
		return len;
	}
	static bool compare(int a, int b)
	{
		int len_a = getLen(a);
		int len_b = getLen(b);

		unsigned int lead_a = a;
		unsigned int lead_b = b;

		while (len_b--)
			lead_a *= 10;
		lead_a += b;

		while (len_a--)
			lead_b *= 10;
		lead_b += a;

		return(lead_a > lead_b);
	}
	string largestNumber(vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), compare);

		string ans;
		for (auto i : nums)
			ans += std::to_string(i);

		if (ans[0] == '0')
			return "0";

		return ans;
	}
};
#pragma endregion

void q0179_tester()
{
	Solution s;
	vector<int> q;

	q = { 10, 2 };
	cout << s.largestNumber(q) << endl;  //expect : 210

	q = { 3, 30, 34, 5, 9 };
	cout << s.largestNumber(q) << endl;  //expect : 9534330

	q = { 128,12 };
	cout << s.largestNumber(q) << endl;  //expect : 12812

	q = { 824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247 };
	cout << s.largestNumber(q) << endl;  //expect : 9609938824824769735703560743981399												    												

	q = { 12,121 };
	cout << s.largestNumber(q) << endl;  //expect : 12121
}


