#pragma once
#include "DebugUtils.h"

#pragma region brilliant_O(n)_mem_consumption
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int flag = 1;
		for (int i = 0; i<9 && flag; i++) {
			bool table_row[10] = { 0 }, table_col[10] = { 0 }, table_blo[10] = { 0 };
			for (int j = 0; j<9; j++) {
				if (board[i][j] != '.') {
					if (table_row[(board[i][j] - '0')] == 0)
						table_row[(board[i][j] - '0')] = 1;
					else {
						flag = 0;
						break;
					}
				}

				if (board[j][i] != '.') {
					if (table_col[(board[j][i] - '0')] == 0)
						table_col[(board[j][i] - '0')] = 1;
					else {
						flag = 0;
						break;
					}
				}

				if ((board[(i * 3 + j / 3) % 9][(i / 3) * 3 + j % 3]) != '.') {
					if (table_blo[(board[(i * 3 + j / 3) % 9][(i / 3) * 3 + j % 3] - '0')] == 0)
						table_blo[(board[(i * 3 + j / 3) % 9][(i / 3) * 3 + j % 3] - '0')] = 1;
					else {
						flag = 0;
						break;
					}
				}
			}
		}

		if (flag)
			return 1;
		else
			return 0;


	}
};
#pragma endregion

#pragma region sean_edition
//class Solution {
//public:
//	bool isValidSudoku(vector<vector<char>>& board) {				
//		int row_check[9][9] = {0};
//		int col_check[9][9] = {0};
//		int cube_check[9] = { 0 };
//		int num;
//
//		for (int base_r = 0; base_r < 9; base_r += 3)
//		{
//			for (int base_c = 0; base_c < 9; base_c += 3)
//			{
//				memset(cube_check, 0, sizeof(cube_check));
//				for (int i = base_r; i < base_r + 3; i++)
//				{
//					for (int j = base_c; j < base_c + 3; j++)
//					{
//						if (board[i][j] == '.')
//							continue;
//						num = board[i][j] - '0' - 1;  //range : 0~8 , which maps to 1~9
//
//						//cube check
//						if (cube_check[num] != 0)
//							return false;
//						else
//							cube_check[num] = 1;
//
//						//row check
//						if (row_check[num][i] != 0)
//							return false;
//						else
//							row_check[num][i] = 1;
//
//						//col check
//						if (col_check[num][j] != 0)
//							return false;
//						else
//							col_check[num][j] = 1;
//					}
//				}
//			}
//		}
//		return true;
//	}
//};
#pragma endregion

void q0036_tester()
{
	Solution s;
	vector<vector<char>> b;

	b = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};
	cout << s.isValidSudoku(b) << endl; //expect: true

	b = {
		{ '8', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	cout << s.isValidSudoku(b) << endl; //expect: false

}
