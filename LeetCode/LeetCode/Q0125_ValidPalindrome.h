#pragma once

#include "DebugUtils.h"
#include <ctype.h>

#pragma region sean_1st_edtion
//class Solution {
//public:
//	bool isPalindrome(string s) {
//		int l = 0, r = s.length()-1;
//		if (l == r)
//			return true;
//		
//		while (l < r)
//		{
//			while (l < r && isalnum(s[l]) == false)
//				l++;
//
//			while (l < r && isalnum(s[r]) == false)
//				r--;
//
//			if (l >= r)
//				break;
//			else
//				if (tolower(s[l]) != tolower(s[r]))
//					return false;
//
//			l++;
//			r--;
//		}
//
//		return true;
//	}
//};
#pragma endregion

#pragma region rephrase_briefly
class Solution {
public:
	bool isPalindrome(string s) {
		int l = 0, r = s.length() - 1;
		if (l == r)
			return true;

		while (l < r)
		{
			if (!isalnum(s[l])) { l++; continue; }
			if (!isalnum(s[r])) { r--; continue; }
			if (tolower(s[l]) != tolower(s[r]))
				return false;

			l++;
			r--;
		}

		return true;
	}
};
#pragma endregion

void q0125_tester()
{
	Solution s;
	//cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl; //expect: true
	//cout << s.isPalindrome("race a car") << endl; //expect: false
	//cout << s.isPalindrome("0P") << endl; //expect: false
	cout << s.isPalindrome(".,") << endl; //expect: true

}
