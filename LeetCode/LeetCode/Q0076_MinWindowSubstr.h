#pragma once
#include "DebugUtils.h"
#include <string>

#pragma region optimized_sliding_window
//#include <queue>
//#include <unordered_map>
//class Solution {
//public:
//	string minWindow(string s, string t) {		
//		unordered_map<char, int> req_list;
//		int req_num = 0;
//
//		//build req list
//		for (auto c : t)
//		{
//			if (req_list.count(c) == 0)
//			{
//				req_num++;
//				req_list[c] = 1;
//			}
//			else
//				req_list[c] ++;							
//		}
//
//		queue<int> shift_map;
//		int min_idx, min_size = INT_MAX;
//		int right=0, left=0;		
//				
//		while (right < s.size())
//		{
//			//shift right until satisfied
//			while (right < s.size() && req_num != 0)
//			{
//				if (req_list.count(s[right]) != 0)
//				{
//					shift_map.push(right);
//					if (--req_list[s[right]] == 0)
//						req_num--;
//				}
//				right++;
//			}
//
//			if (req_num != 0)
//				break; //cannot get satisfation anymore						
//
//			//shift left until unsatisfied
//			while ((!shift_map.empty()) && req_num == 0)
//			{				
//				left = shift_map.front();				
//				//update min_idx and min_size			
//				if (right - left < min_size)
//				{
//					min_size = right - left;
//					min_idx = left;
//					if (min_size == t.size())
//						break; //no need to search further, because it's shortest already.
//				}
//
//				if (++req_list[s[left]] == 1)
//					req_num++;
//				shift_map.pop();
//			}
//		}
//		if (min_size == INT_MAX)
//			return "";
//		else
//			return s.substr(min_idx, min_size);
//	}
//};
#pragma endregion


#pragma region forget_about_optimization_actually_fastest_sol
class Solution {
public:
	string minWindow(string s, string t) {
		int req_list[128] = { 0 };
		int req_num = 0;

		for (auto c : t)
		{
			if (req_list[c] == 0)
				req_num++;
			req_list[c]++;
		}

		int left = 0, right = 0;
		int min_idx, min_size = INT_MAX;
		int n = s.size();
		while (true)
		{
			if (req_num != 0)
			{
				if (right == n) break;

				if (--req_list[s[right++]] == 0)
					req_num--;
			}
			else
			{
				if (right - left < min_size)
				{
					min_size = right - left;
					min_idx = left;
				}

				if (++req_list[s[left++]] == 1)
					req_num++;
			}
		}

		if (min_size == INT_MAX)
			return "";
		return s.substr(min_idx, min_size);
	}
};
#pragma endregion

void q0076_tester()
{
	Solution s;

	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl; // expect : BANC
	cout << s.minWindow("ab", "b") << endl; // expect : b
	cout << s.minWindow("aa", "aa") << endl; // expect : aa
	cout << s.minWindow("bba", "ab") << endl; // expect : ba

}
