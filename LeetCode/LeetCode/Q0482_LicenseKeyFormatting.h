
#pragma once
#include "DebugUtils.h"
#include <string>

#pragma region my_straight_forward_sol
//class Solution {
//public:
//	string licenseKeyFormatting(string S, int K) {
//		int num_char = 0;
//		for (auto c : S)
//			if (c != '-')
//				num_char++;
//
//		int cnt = num_char % K;
//		if (cnt == 0) cnt = K;
//		string ans;
//		for (int i = 0 ; i<S.length() ; i++)
//		{
//			if (S[i] != '-')
//			{
//				ans.push_back(toupper(S[i]));
//				if (--cnt == 0)
//				{
//					ans.push_back('-');
//					cnt = K;
//				}
//			}
//		}
//		if (ans.back() == '-')
//			ans.pop_back();
//		return ans;
//	}
//};
#pragma endregion

#pragma region elegant_manner_on_leetcode
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string ans;

		for (auto c = S.rbegin() ; c!= S.rend(); c++)
			if (*c != '-')
			{
				if (ans.size() % (K + 1) == K)
					ans += '-';
				ans += toupper(*c);
			}
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};
#pragma endregion

void q0482_tester()
{
	Solution s;
	
	string q;

	q = "5F3Z-2e-9-w";
	cout << s.licenseKeyFormatting(q, 4)<<endl; //5F3Z-2E9W

	q = "2-5g-3-J";
	cout << s.licenseKeyFormatting(q, 2)<<endl; //2-5G-3J

	q = "a-a-a-a-";
	cout << s.licenseKeyFormatting(q, 1) << endl; //A-A-A-A
	
}
