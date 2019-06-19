#pragma once

#include "DebugUtils.h"
#include <algorithm>


using namespace std;

class Solution {
public:
	// practice again
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ans;
		int target_2sum;		

		if (nums.size() < 3)
			return ans;
		sort(nums.begin(), nums.end());
		
		if (nums[0] > 0 || nums[nums.size() - 1] < 0)
			return ans;

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i != 0 && nums[i-1] == nums[i])
				continue;			

			target_2sum = -nums[i];

			if (target_2sum < 0)
				return ans;		

			int pre_j;
			int pre_k;

			int j = i + 1;
			int k = nums.size() - 1;

			while (j < k)
			{
				int sum2 = nums[j] + nums[k];
				bool move_j = false;
				bool move_k = false;

				if (sum2 == target_2sum)
				{
					ans.push_back({ nums[i], nums[j], nums[k] });
					move_j = move_k = true;
				}
				else if (sum2 < target_2sum)
					move_j = true;				
				else				
					move_k = true;
				
				if (move_j)
				{					
					j++;
					while (j < k && nums[j] == nums[j - 1])
						j++;
				}
				if(move_k)
				{
					k--;
					while (j < k && nums[k] == nums[k + 1])
						k--;
				}				
			}		
		}
		return ans;
	}
};

void q0015_tester()
{
	Solution s;
	vector<int> v{ -1, 0, 1, 2, -1, -4 };   //expect ans [-1, 0, 1] , [-1, -1, 2]
	vector<vector<int>> ans = s.threeSum(v); 
	print(ans);
}