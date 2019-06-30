#pragma once

#include "DebugUtils.h"

#pragma region sean_1st_edition
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		vector<int> ans;
//		int state = 1; //start from 1, I will perform the stage 0 by myself.
//		int n, m;
//		int x, y;
//
//		if (matrix.size() == 0)
//			return ans;
//
//		n = matrix.size() - 1;
//		m = matrix[0].size() - 1;
//
//		for (auto i : matrix[0])
//			ans.push_back(i);
//
//
//		x = m;
//		y = 0;
//		while ((!(state % 2 == 0 && m == 0)) && (!(state % 2 == 1 && n == 0)))
//		{			
//			if (state == 0) // X+
//			{	
//				for (int i = 0; i < m; i++)
//					ans.push_back(matrix[y][++x]);
//				m--;
//			}
//			else if (state == 1) //Y+
//			{
//				for (int i = 0; i < n; i++)				
//					ans.push_back(matrix[++y][x]);
//				n--;
//			}
//			else if (state == 2) //X-
//			{
//				for (int i = 0; i < m; i++)
//					ans.push_back(matrix[y][--x]);
//				m--;
//			}
//			else if (state == 3) //Y-
//			{
//				for (int i = 0; i < n; i++)
//					ans.push_back(matrix[--y][x]);
//				n--;
//			}
//			state = (state == 3) ? 0 : state + 1;
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region leetcode_0ms_submission
//class Solution {
//public:
//
//	void add(vector<vector<int>>& matrix, vector<int>& result, int x1, int x2, int y1, int y2)
//	{
//		if (x1 > x2 || y1 > y2)
//			return;
//		if (x1 == x2 && y1 == y2)
//		{
//			result.push_back(matrix[x1][y1]);
//			return;
//		}
//		if (x1 == x2)
//		{
//			for (int i = y1; i <= y2; i++)
//				result.push_back(matrix[x1][i]);
//			return;
//		}
//		if (y1 == y2)
//		{
//			for (int i = x1; i <= x2; i++)
//				result.push_back(matrix[i][y2]);
//			return;
//		}
//		for (int i = y1; i < y2; i++)
//			result.push_back(matrix[x1][i]);
//		for (int i = x1; i < x2; i++)
//			result.push_back(matrix[i][y2]);
//		for (int i = y2; i > y1; i--)
//			result.push_back(matrix[x2][i]);
//		for (int i = x2; i > x1; i--)
//			result.push_back(matrix[i][y1]);
//		add(matrix, result, x1 + 1, x2 - 1, y1 + 1, y2 - 1);
//	}
//
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		if (matrix.size() == 0)
//			return vector<int>();
//		vector<int> result;
//		add(matrix, result, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
//		return result;
//	}
//};
#pragma endregion

#pragma region leetcode_4ms_submission
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int row = matrix.size();
		if (row == 0) {
			return ans;
		}

		int column = matrix[0].size();
		int x = 0, y = 0;

		int k = 0;
		while (x<row&&y<column) {
			while (y<column) {
				ans.push_back(matrix[x][y]);
				y++;
			}
			y--;
			x++;

			if (x >= row) {
				break;
			}

			while (x<row) {
				ans.push_back(matrix[x][y]);
				x++;
			}
			x--;
			y--;

			if (y<k) {
				break;
			}
			while (y >= k) {
				ans.push_back(matrix[x][y]);
				y--;
			}
			y++;
			x--;
			while (x >= k + 1) {
				ans.push_back(matrix[x][y]);
				x--;
			}
			x++;
			y++;

			k++;
			row--;
			column--;
		}
		return ans;
	}
};
#pragma endregion

void q0054_tester()
{
	Solution s;
	vector<vector<int>> q{
		{ 1, 2, 3, },
	{ 4, 5, 6, },
	{ 7, 8, 9, }
	};
	print(s.spiralOrder(q)); // output: 1, 2, 3, 6, 9, 8, 7, 4, 5

	q = {
		{ 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 }
	};
	print(s.spiralOrder(q)); //Output: [1,2,3,4,8,12,11,10,9,5,6,7]
}
