
#pragma once
#include "DebugUtils.h"

#pragma region DFS
//class Solution {
//private:	
//	vector<vector<int>> max_map_; //0 indicate not computed. others represent the computed result.
//	int m_, n_;
//
//	template<typename T>
//	T max(T a, T b)
//	{
//		if (a > b)
//			return a;
//		else
//			return b;
//	}
//
//	int longestPathLen(vector<vector<int>>& matrix, int i, int j)
//	{
//		if (max_map_[i][j] != 0)
//			return max_map_[i][j];
//
//		int max_val = 1; 
//
//		if (i + 1 < m_ && matrix[i + 1][j] > matrix[i][j])
//			max_val = max(max_val, 1 + longestPathLen(matrix, i + 1, j));
//
//		if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
//			max_val = max(max_val, 1 + longestPathLen(matrix, i - 1, j));
//
//		if (j + 1 < n_ && matrix[i][j + 1] > matrix[i][j])
//			max_val = max(max_val, 1 + longestPathLen(matrix, i, j + 1));
//
//		if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
//			max_val = max(max_val, 1 + longestPathLen(matrix, i, j - 1));
//
//		max_map_[i][j] = max_val;
//		//printf("%d, %d = %d\r\n", i, j, max_val);
//		return max_val;
//	}
//
//public:
//	int longestIncreasingPath(vector<vector<int>>& matrix) {
//		m_ = matrix.size();
//		if (m_ == 0) return 0;
//		
//		n_ = matrix[0].size();		
//		max_map_ = vector<vector<int>>(m_, vector<int>(n_));
//
//		int max_val = -1;
//		int n;
//		for (int i = 0; i < m_; i++)
//			for (int j = 0; j < n_; j++)
//			{
//				n = longestPathLen(matrix, i, j);
//				if (n > max_val)
//					max_val = n;
//			}
//
//		return max_val;
//	}
//};
#pragma endregion

#pragma region DFS_with_elegant_coding
class Solution {
private:
	const static int dir[4][2];
	vector<vector<int>> max_map_; //0 indicate not computed. others represent the computed result.
	int m_, n_;

	template<typename T>
	T max(T a, T b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	
	int longestPathLen(vector<vector<int>>& matrix, int i, int j)
	{
		if (max_map_[i][j] != 0)
			return max_map_[i][j];
		int max_val = 1;

		for (auto& k : dir)
		{
			int x = i + k[0], y = j + k[1];
			if (x<0 || x>m_-1 || y<0 || y>n_-1 || matrix[x][y] <= matrix[i][j]) 
				continue;
			max_val = max(max_val, 1+ longestPathLen(matrix, x, y));
		}		
		max_map_[i][j] = max_val;		
		return max_val;
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m_ = matrix.size();
		if (m_ == 0) return 0;

		n_ = matrix[0].size();
		max_map_ = vector<vector<int>>(m_, vector<int>(n_));

		int max_val = -1;
		int n;
		for (int i = 0; i < m_; i++)
			for (int j = 0; j < n_; j++)
			{
				n = longestPathLen(matrix, i, j);
				if (n > max_val)
					max_val = n;
			}

		return max_val;
	}
};
const int Solution::dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
#pragma endregion

void q0329_tester()
{
	Solution s;
	vector<vector<int>> q;

	q = {
		{ 9, 9, 4 },
		{ 6, 6, 8 },
		{ 2, 1, 1 }
	};
	cout << s.longestIncreasingPath(q) << endl; //expect 4

	//q = {
	//	{ 3,4,5 },
	//{ 3,2,6 },
	//{ 2,2,1 }
	//};
	//cout << s.longestIncreasingPath(q) << endl; //expect 4
}
