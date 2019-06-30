#pragma once

#include "DebugUtils.h"

class Solution {
public:
	vector<vector<int>> generate(int numRows) 
	{
		if (numRows == 0)
			return {};
		
		vector<vector<int>> ans(numRows);		
		for (auto it = ans.begin() ; it != ans.end() ; it++)
		{
			*it = vector<int>(it - ans.begin() + 1);
		}

		for (int i = 0; i < numRows; i++)
		{
			ans[i][i] = 1;
			ans[i][0] = 1;
		}

		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
			}
		}
		return ans;
	}
};

void q0118_tester()
{
	Solution s;
	vector<vector<int>> ans;

	ans = s.generate(5);
	print(ans); 
	/* expect 
		[1],
		[1,1],
		[1,2,1],
		[1,3,3,1],
		[1,4,6,4,1]
	*/
}
