#pragma once

#include "DebugUtils.h"

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		
		for(int i = 0 ; i< board.size() ; i++)
			for (int j = 0; j < board[0].size(); j++)
			{
				int cnt = 0;
				int k_start = (i == 0) ? 0 : -1;
				int k_end = (i == board.size() - 1) ? 0 : 1;
				int l_start = (j == 0) ? 0 : -1;
				int l_end = (j == board[0].size() - 1) ? 0 : 1;
				for (int k = k_start; k <= k_end ; k++)				
					for (int l = l_start; l <= l_end; l++)
					{
						if (k == 0 && l == 0) continue;
						if (board[i + k][j + l] & 0x1) cnt++;
					}									

				if (board[i][j] & 0x1)
				{
					if(cnt == 2 || cnt == 3) board[i][j] |= 0x2;
				}
				else
				{
					if (cnt == 3) board[i][j] |= 0x2;
				}
			}
				
		for (auto &i : board)
			for (auto &j : i)
				j >>= 1;
								
	}
};

void q0289_tester()
{
	Solution s;

	vector<vector<int>> q = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 1, 1},
		{0, 0, 0}
	};

	s.gameOfLife(q);
	print(q);

/* expect
		[0,0,0],
		[1,0,1],
		[0,1,1],
		[0,1,0]
*/
}
