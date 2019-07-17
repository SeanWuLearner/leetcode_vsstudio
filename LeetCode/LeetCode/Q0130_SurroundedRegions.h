#pragma once

#include "DebugUtils.h"

#pragma region propagate_border_0
class Solution {
private:
	void propagateBorderZero(vector<vector<char>>& board, int i, int j)
	{
		if (board[i][j] != 'O')
			return;
		else
		{
			board[i][j] = 'V';
			if (i > 0)
				propagateBorderZero(board, i - 1, j);
			if (i < board.size() - 1)
				propagateBorderZero(board, i + 1, j);
			if (j > 0)
				propagateBorderZero(board, i, j - 1);
			if (j < board[0].size() - 1)
				propagateBorderZero(board, i, j + 1);
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;

		for (int i = 0; i < board.size(); i++)
		{
			propagateBorderZero(board, i, 0);
			propagateBorderZero(board, i, board[0].size() - 1);
		}

		for (int i = 1; i < board[0].size() - 1; i++)
		{
			propagateBorderZero(board, 0, i);
			propagateBorderZero(board, board.size() - 1, i);
		}

		for (auto &i : board)
			for (auto &j : i)
				if (j == 'O')
					j = 'X';

		for (auto &i : board)
			for (auto &j : i)
				if (j == 'V')
					j = 'O';
	}
};
#pragma endregion

#pragma region wrong_ans
//wrong ans because '?' will eventually wrap the element which should leave 'O'.
//class Solution {
//private:	
//	bool checkAndFlip(vector<vector<char>> &board, int i, int j)
//	{
//		if (i == 3 && j == 2)
//			cout << "a" << endl;
//
//		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
//			return true; //NOT surrounded.
//
//		if (board[i][j] == 'X')
//			return false;
//
//		if (board[i][j] == 'V') 
//			return true; //NOT surrounded.
//
//		if (board[i][j] == '?')
//			return false; //NOT sure yet. 
//
//		//case 'O'
//		board[i][j] = '?'; //avoid revisiting the node.
//		if (checkAndFlip(board, i-1, j) || 
//			checkAndFlip(board, i+1, j) ||
//			checkAndFlip(board, i, j-1) ||
//			checkAndFlip(board, i, j+1))
//		{
//			board[i][j] = 'V';
//			return true;
//		}
//
//		//surrounded 'O' case
//		board[i][j] = 'X';
//		return false;				
//		
//	}
//public:
//	void solve(vector<vector<char>>& board) {
//		
//		if (board.size() == 0)
//			return;
//		
//		for (int i = 0; i < board.size(); i++)
//			for (int j = 0; j < board[0].size(); j++)
//			{
//				if (board[i][j] == 'O')
//					checkAndFlip(board, i, j);
//			}
//
//		//post processing
//		for (auto &i : board)
//			for (auto &j : i)
//				if (j == 'V')
//					j = 'O';
//	}
//};
#pragma endregion

void q0130_tester()
{
	Solution s;
	vector<vector<char>> b;

	b = {
		{ 'X', 'X', 'X', 'X' },
	{ 'X', 'O', 'O', 'X' },
	{ 'X', 'X', 'O', 'X' },
	{ 'X', 'O', 'X', 'X' },
	};
	//s.solve(b);
	//print(b);
	/* expect:
	X X X X
	X X X X
	X X X X
	X O X X
	*/


	b = {
		{ 'O', 'X', 'O', 'O', 'O', 'X' },
	{ 'O', 'O', 'X', 'X', 'X', 'O' },
	{ 'X', 'X', 'X', 'X', 'X', 'O' },
	{ 'O', 'O', 'O', 'O', 'X', 'X' },
	{ 'X', 'X', 'O', 'O', 'X', 'O' },
	{ 'O', 'O', 'X', 'X', 'X', 'X' }
	};

	/*
	expect[
	["O","X","O","O","O","X"],
	["O","O","X","X","X","O"],
	["X","X","X","X","X","O"],
	["O","O","O","O","X","X"],
	["X","X","O","O","X","O"],
	["O","O","X","X","X","X"]]
	*/

	s.solve(b);
	print(b);
}
