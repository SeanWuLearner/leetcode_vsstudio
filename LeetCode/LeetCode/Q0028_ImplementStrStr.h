

#pragma once

#include "DebugUtils.h"

#pragma region DFS_Manner
//class Solution {
//public:
//	int strStr(string haystack, string needle)
//	{
//		if (needle.empty() == true) return 0;
//
//		int j = 0;
//		int match_idx = -1;
//		for (int i = 0; i < haystack.size(); i++)
//		{
//			if (haystack[i] == needle[j])
//			{
//				if (match_idx == -1)
//					match_idx = i;
//
//				if (++j >= needle.size())
//					return match_idx;
//			}
//			else
//			{
//				if (match_idx != -1)
//				{
//					i = match_idx;
//					j = 0;
//					match_idx = -1;
//				}
//			}
//		}
//		return -1;
//	}
//};
#pragma endregion

#pragma region DFS_brief_ver
//class Solution {
//public:
//	int strStr(string haystack, string needle)
//	{
//		if (needle.empty() == true) return 0;		
//		if (haystack.size() < needle.size()) return -1;
//		for (int i = 0; ; i++)		
//			for (int j = 0; ; j++)
//			{
//				if (j == needle.size()) return i;
//				if (i + j == haystack.size()) return -1;
//				if (haystack[i + j] != needle[j]) break;				
//			}													
//	}
//};
#pragma endregion

#pragma region KMP_method
/*
size(haystack) = n, sizeof(needle) = m
Time : O(n+m)
Mem : O(m)
*/
class Solution {

private:
	vector<int>* buildKmpTable(string &s)
	{
		int n = s.size();
		vector<int> *tbl = new vector<int>(n, 0);
		if (n == 0) return tbl;
		for (int i = 1, j = 0; i < n;)
		{
			if (s[i] != s[j])
			{
				if (j == 0)
					(*tbl)[i++] = 0;
				else
					j = (*tbl)[j - 1];
			}
			else
				(*tbl)[i++] = ++j;

		}
		return tbl;
	}

public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty() == true) return 0;
		vector<int> *backward_tbl = buildKmpTable(needle);

		int i = 0, j = 0, starti = -1;
		for (int i = 0, j = 0; i < haystack.size();)
		{
			if (haystack[i] == needle[j])
				i++, j++;

			if (j == needle.size())
				return i - j;

			if (i < haystack.size() && haystack[i] != needle[j])
				j ? j = (*backward_tbl)[j - 1] : i++;
		}
		return -1;
	}
};
#pragma endregion

void q0028_tester()
{
	Solution s;

	cout << s.strStr("hello", "ll") << endl; // 2

	cout << s.strStr("heaabc", "ab") << endl; // 3

	cout << s.strStr("aaaaa", "bba") << endl; // -1
	cout << s.strStr("aaa", "aaaa") << endl; // -1

	cout << s.strStr("ABCdsabcdsabcdsah", "dsabcdsah") << endl; //8 

	cout << s.strStr("aabaaabaaac", "aabaaac") << endl; //4


}
