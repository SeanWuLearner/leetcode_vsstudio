#pragma once

#include "DebugUtils.h"

#pragma region DFS_manner
class Solution {
private:
	void mark_neighbor(vector<vector<char>>& grid, int i, int j)
	{
		if (grid[i][j] == '1')
		{
			grid[i][j] = '2';
			if (i > 0)
				mark_neighbor(grid, i - 1, j);
			if (i < grid.size() - 1)
				mark_neighbor(grid, i + 1, j);
			if (j > 0)
				mark_neighbor(grid, i, j - 1);
			if (j < grid[0].size() - 1)
				mark_neighbor(grid, i, j + 1);
		}

	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		if (m == 0) return 0;
		int n = grid[0].size();
		int count = 0;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
					count++;
				mark_neighbor(grid, i, j);
			}

		return count;
	}
};
#pragma endregion


void q0200_tester()
{
	Solution s;
	vector<vector<char>> q;

	q = {
		{ '1', '1', '1', '1', '0' },
	{ '1', '1', '0', '1', '0' },
	{ '1', '1', '0', '0', '0' },
	{ '0', '0', '0', '0', '0' }
	};

	cout << s.numIslands(q) << endl; // 1


	q = {
		{ '1', '1', '0', '0', '0' },
	{ '1', '1', '0', '0', '0' },
	{ '0', '0', '1', '0', '0' },
	{ '0', '0', '0', '1', '1' }
	};
	cout << s.numIslands(q) << endl; // 3


	q = {
		{ '1', '1', '1' },
	{ '0', '1', '0' },
	{ '1', '1', '1' }
	};
	cout << s.numIslands(q) << endl; // 1

}

