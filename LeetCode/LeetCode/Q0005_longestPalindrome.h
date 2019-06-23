#pragma once

#include "DebugUtils.h"
#include <string>

#pragma region sean.wu_1st_edition
class Solution {
private:
	vector<vector<int>> len_table_;
	pair<int, int> max_idx_;
	int max_;

	template <typename T>
	T max(const T &a, const T &b)
	{
		return (a > b) ? a : b;
	}

	int findLongestPalidromeLen(const string &s, int i, int j)
	{
		int ret;

		if (i > j || i < 0 || j >= s.length())
			return 0;

		if (len_table_[i][j] != -1)
			return len_table_[i][j];
		else
		{
			if (i == j)
				ret = 1;			
			else if (s[i] == s[j] && findLongestPalidromeLen(s, i + 1, j - 1) == (j-i-1))
				ret = findLongestPalidromeLen(s, i + 1, j - 1) + 2;
			else
				ret = max(findLongestPalidromeLen(s, i, j - 1), findLongestPalidromeLen(s, i + 1, j));
			
			len_table_[i][j] = ret;
			if (ret > max_)
			{
				max_ = ret;
				max_idx_ = { i, j };
			}
			return ret;
		}
	}
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len <= 1)
			return s;

		//initial test variables
		len_table_ = vector<vector<int>>(len, vector<int>(len, -1));
		max_ = -1;
		
		findLongestPalidromeLen(s, 0, len - 1);
		return s.substr(max_idx_.first, max_idx_.second - max_idx_.first + 1);
	}
};
#pragma endregion

#pragma region sean.wu_1st_edition_recursive_to_iterative
//TODO
#pragma endregion


#pragma region sean.wu_2nd_edition
//class Solution {
//public:
//	string longestPalindrome(string s) 
//	{
//		pair<int, int> max_idx;
//		int max = -1;
//		int i, j, len;
//
//		if (s.length() <= 1)
//			return s;
//
//		//loop for even palindrome
//		for (size_t k = 0; k < s.length()-1; k++)
//		{
//			i = k; j = k + 1; len = 0;
//			while (i >= 0 && j < s.length())
//			{
//				if (s[i] == s[j])
//				{
//					len += 2;
//					if (len > max)
//					{
//						max = len;
//						max_idx = { i, j };
//					}
//					i--;
//					j++;
//				}
//				else
//					break;
//			}			
//		}
//
//		//loop for odd palindrome		
//		for (size_t k = 1; k < s.length() - 1; k++)
//		{
//			i = k-1; j = k + 1; len = 1;
//			while (i >= 0 && j < s.length())
//			{
//				if (s[i] == s[j])
//				{
//					len += 2;
//					if (len > max)
//					{
//						max = len;
//						max_idx = { i, j };
//					}
//					i--;
//					j++;
//				}
//				else
//					break;
//			}
//		}
//		return s.substr(max_idx.first, max_idx.second - max_idx.first + 1);
//	}
//};
#pragma endregion

#pragma region Genius_version
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.empty()) return "";
//		if (s.size() == 1) return s;
//		int min_start = 0, max_len = 1;
//		for (int i = 0; i < s.size();) {
//			if (s.size() - i <= max_len / 2) break;
//			int j = i, k = i;
//			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
//			i = k + 1;
//			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
//			int new_len = k - j + 1;
//			if (new_len > max_len) { min_start = j; max_len = new_len; }
//		}
//		return s.substr(min_start, max_len);
//	}
//};
#pragma endregion

void q0005_tester() {
	Solution s;
	cout << s.longestPalindrome("bbaab") << endl;
}