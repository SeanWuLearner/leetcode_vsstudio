#pragma once

#include "DebugUtils.h"

#pragma region DP_manner
//#include <unordered_set>
//class Solution {
//public:
//	bool wordBreak(string s, vector<string>& wordDict) {
//		int n = s.size();
//		vector<bool> dp(n + 1, false);
//		unordered_set<string> dict;
//
//		//build map
//		for (auto &s : wordDict)
//			dict.insert(s);
//		
//		dp[0] = true;
//		for (int i = 1; i <= n; i++)
//		{
//			//for (int j = 0 ; j < i ; j++) //slower
//			for (int j = i-1; j >= 0; j--) //faster
//			{				
//				//if (dp[j] && dict.count(s.substr(j, i - j)) != 0) //slower
//				if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) //faster
//				{
//					dp[i] = true;
//					break;
//				}													
//			}
//		}
//
//		return dp[n];
//	}
//};
#pragma endregion

#pragma region BFS_manner
#include <unordered_set>
#include <queue>
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		queue<int> bfs;
		unordered_set<string> dict;
		unordered_set<int> visited;

		//build map
		for (auto &s : wordDict)
			dict.insert(s);

		bfs.push(0);
		while (bfs.empty() == false)
		{
			int start = bfs.front();
			bfs.pop();
			if (visited.find(start) == visited.end()) //avoid replicated visit.
			{
				visited.insert(start);
				for (int i = start; i < n; i++)
				{
					if (dict.find(s.substr(start, n - i)) != dict.end())
					{
						bfs.push(start + (n - i));
						if (start + (n - i) == n)
							return true;
					}
				}
			}
		}
		return false;
	}
};
#pragma endregion


void q0139_tester()
{
	Solution s;
	string q;
	vector<string> dict;

	q = "leetcode";
	dict = { "leet", "code" };	
	cout << s.wordBreak(q, dict) << endl; //true

	q = "applepenapple";
	dict = { "apple", "pen" };
	cout << s.wordBreak(q, dict) << endl; //true

	q = "catsandog";
	dict = { "cats", "dog", "sand", "and", "cat" };
	cout << s.wordBreak(q, dict) << endl; //false

	q = "goalspecial";
	dict = { "go", "goal", "goals", "special" };
	cout << s.wordBreak(q, dict) << endl; //true

}
