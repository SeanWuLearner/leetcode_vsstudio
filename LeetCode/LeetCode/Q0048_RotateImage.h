#pragma once

#include "DebugUtils.h"

#pragma region with_transpose
//class Solution {
//public:
//	void rotate(vector<vector<int>>& matrix) {
//		//reverse row
//		std::reverse(matrix.begin(), matrix.end());  
//
//		//transpose
//		for (int i = 0; i < matrix.size(); i++)
//			for (int j = 0; j < i; j++)
//			{
//				std::swap(matrix[i][j], matrix[j][i]);
//			}
//	}
//};
#pragma endregion

#pragma region swap_4_elements_at_a_time
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int tmp;
		for (int x = 0; x < n / 2; x++)
			for (int y = x; y < n - x - 1; y++)
			{
				tmp = matrix[x][y];
				matrix[x][y] = matrix[n - 1 - y][x];
				matrix[n - 1 - y][x] = matrix[n - 1 - x][n - 1 - y];
				matrix[n - 1 - x][n - 1 - y] = matrix[y][n - 1 - x];
				matrix[y][n - 1 - x] = tmp;
			}
	}
};
#pragma endregion

void q0048_tester()
{
	Solution s;
	vector<vector<int>> m;

	m = {
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};
	s.rotate(m);
	print(m);

	//expect 
	//	[7, 4, 1],
	//	[8, 5, 2],
	//	[9, 6, 3]

	m = {
		{ 5, 1, 9, 11 },
		{ 2, 4, 8, 10 },
		{ 13, 3, 6, 7 },
		{ 15, 14, 12, 16 }
	};
	s.rotate(m);
	print(m);

	//expect
	//	[15, 13, 2, 5],
	//	[14, 3, 4, 1],
	//	[12, 6, 8, 9],
	//	[16, 7, 10, 11]

}


