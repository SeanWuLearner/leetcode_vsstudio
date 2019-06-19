#pragma once

#include <map>
#include <unordered_map>
#include <iostream>
#include "DebugUtils.h"

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		unordered_map<int, int>::iterator iter;
		vector<int> ans;

		for (int i = 0; i < nums.size(); i++)
		{
			iter = m.find(target - nums.at(i));
			if (iter == m.end())
				m[nums.at(i)] = i;
			else
			{
				ans.push_back(iter->second);
				ans.push_back(i);				
				return ans;
			}
		}
		return ans;
	}
};


void q0001_tester() 
{
	Solution s;
	vector<int> quest{ 2,11, 7, 5 };

	vector<int> ans = s.twoSum(quest, 9);
	print(ans);
	return;
}