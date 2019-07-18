#pragma once

#include "DebugUtils.h"

#pragma region with_O(m*n)_mem
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		vector<vector<int>> grid(m, vector<int>(n, 1));
//
//		for (int i = grid.size() - 2; i >= 0; i--)
//			for (int j = grid[0].size() - 2; j >= 0; j--)
//				grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
//		
//		return grid[0][0];
//	}
//};
#pragma endregion

#pragma region with_O(n)_mem
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> grid(n, 1);

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				grid[j] += grid[j - 1];				

		return grid[n-1];
	}
};
#pragma endregion


void q0062_tester()
{
	Solution s;

	cout << s.uniquePaths(3, 2) << endl; //expect 3
	cout << s.uniquePaths(7, 3) << endl; // expect 28

}
