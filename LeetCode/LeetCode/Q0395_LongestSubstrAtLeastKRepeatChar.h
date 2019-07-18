#pragma once

#include "DebugUtils.h"

#pragma region devide_and_conquer_manner(poor efficiency...)
//#include <algorithm>
//class Solution {
//private:
//	int helper(string &s, int start, int end, int k)
//	{
//		vector<int> counter(26, 0);
//		
//		for (int i = start; i < end; i++)
//			counter[s[i] - 'a']++;
//
//		int max = INT_MIN;
//		for (int i = 0; i < 26; i++)		
//			if (counter[i] > 0 && counter[i] < k) //first bad char happen			
//				for (int j = start; j < end; j++)			
//					if (s[j] == i + 'a')
//					{
//						int left = helper(s, start, j, k);
//						int right = helper(s, j + 1, end, k);
//						return std::max(left, right);
//					}			
//		return end - start;
//	}
//
//public:
//	int longestSubstring(string s, int k) {
//		return helper(s, 0, s.size(), k);
//	}
//};
#pragma endregion

#pragma region two_pointer_manner
#include <algorithm>
class Solution {
private:
	int helper(string &s, int k, int tar_type_num)
	{
		int start = 0, end = 0;
		int type_num = 0, meet_type_num = 0;		
		int max = 0;
		int counter[26] = { 0 };		

		while (end < s.size())
		{
			//forward end anyway
			int c_idx = s[end] - 'a';
			counter[c_idx]++;
			if (counter[c_idx] == 1)
				type_num++;
			if (counter[c_idx] == k)
				meet_type_num++;
			end++;

			//forward start if type_num is excess.
			while (type_num > tar_type_num)
			{
				c_idx = s[start] - 'a';
				if (counter[c_idx] == k) meet_type_num--;
				if (counter[c_idx] == 1) type_num--;
				counter[c_idx]--;
				start++;
			}

			if (type_num == tar_type_num && meet_type_num == tar_type_num)
				max = std::max(max, end - start);
		}
		return max;
	}
public:
	int longestSubstring(string s, int k) {
		int max = 0;
		for (int i = 1; i <= 26; i++)
			max = std::max(max, helper(s, k, i));

		return max;
	}
};
#pragma endregion

void q0395_tester()
{
	Solution s;

	cout << s.longestSubstring("aaabb", 3) << endl; //output 3
	cout << s.longestSubstring("ababbc", 2) << endl; //output 5

	cout << s.longestSubstring("ababacb", 3) << endl; //output 0
	
	
}
