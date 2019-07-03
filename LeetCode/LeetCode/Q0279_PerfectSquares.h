#pragma once

#include "DebugUtils.h"

#pragma region BFS_to_least_squares
/#include <cmath>
//#include <queue>
//class Solution {			
//public:
//	int numSquares(int n) {
//		if (n == 0) 
//			return 0;
//
//		int table_size = (int)std::sqrt((double)n);
//		vector<int> square_table = vector<int>(table_size+1);
//		for (int i = 1; i <= table_size; i++)
//			square_table[i] = i * i;
//
//		queue<pair<int, int>> q;   //q<target, cntOfSquareNumber>
//		q.push({ n, 0 });
//		pair<int, int> now;
//		while (q.empty() == false)
//		{
//			now = q.front();
//			q.pop();
//
//			for (int i = 1; i < square_table.size() && square_table[i] <= now.first; i++)
//			{
//				int last = now.first - square_table[i];
//				if (last == 0) 
//					return now.second + 1;
//				else
//					q.push({ last, now.second + 1 });
//			}
//		}
//		return -1; //impossible case
//	}
//};
#pragma endregion

#pragma region mathematical_solution_on_leetcode
//class Solution
//{
//private:
//	int is_square(int n)
//	{
//		int sqrt_n = (int)(sqrt(n));
//		return (sqrt_n*sqrt_n == n);
//	}
//
//public:
//	// Based on Lagrange's Four Square theorem, there 
//	// are only 4 possible results: 1, 2, 3, 4.
//	int numSquares(int n)
//	{
//		// If n is a perfect square, return 1.
//		if (is_square(n))
//		{
//			return 1;
//		}
//
//		// The result is 4 if and only if n can be written in the 
//		// form of 4^k*(8*m + 7). Please refer to 
//		// Legendre's three-square theorem.
//		while ((n & 3) == 0) // n%4 == 0  
//		{
//			n >>= 2;
//		}
//		if ((n & 7) == 7) // n%8 == 7
//		{
//			return 4;
//		}
//
//		// Check whether 2 is the result.
//		int sqrt_n = (int)(sqrt(n));
//		for (int i = 1; i <= sqrt_n; i++)
//		{
//			if (is_square(n - i * i))
//			{
//				return 2;
//			}
//		}
//
//		return 3;
//	}
//};
#pragma endregion

#pragma region submission_4ms_on_leetcode
//class Solution {
//public:
//	int numSquares(int n) {
//		if (n <= 0)
//		{
//			return 0;
//		}
//
//		// cntPerfectSquares[i] = the least number of perfect square numbers 
//		// which sum to i. Since cntPerfectSquares is a static vector, if 
//		// cntPerfectSquares.size() > n, we have already calculated the result 
//		// during previous function calls and we can just return the result now.
//		static vector<int> cntPerfectSquares({ 0 });
//
//		// While cntPerfectSquares.size() <= n, we need to incrementally 
//		// calculate the next result until we get the result for n.
//		while (cntPerfectSquares.size() <= n)
//		{
//			int m = cntPerfectSquares.size();
//			int cntSquares = INT_MAX;
//			for (int i = 1; i*i <= m; i++)
//			{
//				cntSquares = min(cntSquares, cntPerfectSquares[m - i * i] + 1);
//			}
//
//			cntPerfectSquares.push_back(cntSquares);
//		}
//		return cntPerfectSquares[n];
//	}
//};
#pragma endregion

#pragma region sean_rephrase_4ms_solution
#include <algorithm>
class Solution {
public:
	int numSquares(int n) {
		vector<int> ans{ 0 }; //init with 1 element.

		for (int i = 1; i <= n; i++)
		{
			int num = INT_MAX;
			for (int j = 1; j*j <= i; j++)
			{
				num = min(num, ans[i - j * j] + 1);
			}
			//cout << "num= " << i << ", ans= " << num << endl;
			ans.push_back(num);
		}
		return ans[n];
	}
};
#pragma endregion


void q0279_tester() 
{
	Solution s;

	cout << s.numSquares(12) << endl; //expect : 3, because 4+4+4
	cout << s.numSquares(13) << endl; //expect : 2, because 4+9
	cout << s.numSquares(16) << endl; //expect : 1, because 16
}
