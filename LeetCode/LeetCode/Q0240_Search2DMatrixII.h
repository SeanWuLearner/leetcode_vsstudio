#pragma once

#include "DebugUtils.h"


#pragma region best_solution
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		
//		int m = matrix.size();
//		if (m == 0)
//			return false;
//		
//		int n = matrix[0].size();
//
//		int i=0, j=n-1;
//		while (i<m && j>=0)
//		{
//			if (matrix[i][j] == target)
//				return true;
//			else if (matrix[i][j] > target) 
//				j--; //shift left
//			else 
//				i++; //shift down
//		}
//		return false;
//	}
//};
#pragma endregion

#pragma region BinarySearchManner_TimeLimitExceeded
class Solution {
private:

	bool search(vector<vector<int>> &matrix, int target, pair<int, int> upper_left, pair<int, int> bottom_right)
	{
		cout << "( " << upper_left.first << " , " << upper_left.second << "), ( " << bottom_right.first << " , " << bottom_right.second << " )" << endl;

		if (upper_left.first > bottom_right.first || upper_left.second > bottom_right.second)
			return false;

		int mid_r = (bottom_right.first + upper_left.first) / 2;
		int mid_c = (bottom_right.second + upper_left.second) / 2;

		if (matrix[mid_r][mid_c] == target)
			return true;
		else if (matrix[mid_r][mid_c] > target)
		{
			return (search(matrix, target, upper_left, { mid_r - 1, mid_c - 1 }) ||
				search(matrix, target, { mid_r, upper_left.second }, { bottom_right.first, mid_c - 1 }) ||
				search(matrix, target, { upper_left.first, mid_c }, { mid_r - 1, bottom_right.second })
				);
		}
		else
		{
			return (search(matrix, target, { mid_r + 1, upper_left.second }, { bottom_right.first, mid_c }) ||
				search(matrix, target, { upper_left.first, mid_c + 1 }, { mid_r, bottom_right.second }) ||
				search(matrix, target, { mid_r + 1, mid_c + 1 }, bottom_right)
				);
		}
	}

public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		return search(matrix, target, { 0, 0 }, { matrix.size() - 1, matrix[0].size() - 1 });
	}
};
#pragma endregion


void q0240_tester()
{
	Solution s;
	vector<vector<int>> q;

	q = {
		{ 1, 4, 7, 11, 15 },
	{ 2, 5, 8, 12, 19 },
	{ 3, 6, 9, 16, 22 },
	{ 10, 13, 14, 17, 24 },
	{ 18, 21, 23, 26, 30 }
	};

	//cout << s.searchMatrix(q, 5) << endl; //true
	cout << s.searchMatrix(q, 20) << endl; //false
}
