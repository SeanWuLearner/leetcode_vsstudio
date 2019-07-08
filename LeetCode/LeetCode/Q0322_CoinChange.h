#pragma once

#include "DebugUtils.h"

#pragma region sean_bottom_up_solution
//#include <algorithm>
//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		vector<int> least(amount + 1, amount + 1);
//		int res;
//
//		least[0] = 0;
//
//		//sort(coins.begin(), coins.end());
//
//		for (int i = 1; i <= amount; i++)
//		{
//			for (int j = coins.size() - 1; j >= 0; j--)
//			{
//				res = i - coins[j];
//				if (res >= 0 && res < least.size())
//					least[i] = min(least[i], least[res] + 1);
//			}
//		}
//
//		if (least[amount] > amount)
//			return -1;
//		else
//			return least[amount];
//	}
//};
#pragma endregion



#pragma region fastest_solution_on_leetcode
//#include <algorithm>
//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		// backtracking will cause TLE unless having good optimization
//		/*
//		if(amount < 0 || coins.empty()) return -1;
//		vector<int> sub;
//		int res = INT_MAX;
//		backtrack(coins, amount, 0, sub, res);
//		return res == INT_MAX ? -1 : res;  */
//
//		// optimized backtracking (tricky)
//		if (amount < 0 || coins.empty()) return -1;
//		sort(coins.begin(), coins.end());
//		vector<int> sub;
//		int res = INT_MAX;
//		backtrack(coins, amount, coins.size() - 1, 0, res);
//		return res == INT_MAX ? -1 : res;
//
//
//		// best solution: DP
//
//
//	}
//
//	void backtrack(vector<int>& coins, int amount, int start, int cur, int& res){
//		if (start < 0) return;
//		if (amount % coins[start] == 0){
//			res = min(res, cur + amount / coins[start]);
//			return;
//		}
//		for (int i = amount / coins[start]; i >= 0; --i){
//			if (cur + i >= res - 1) break;  //  if(cur + i >= res) also works
//			backtrack(coins, amount - i * coins[start], start - 1, cur + i, res);
//		}
//	}
//
//	void backtrack(vector<int>& coins, int amount, int start, vector<int>& sub, int& res){
//		int sum = 0;
//		for (int i = 0; i < sub.size(); ++i){
//			sum += sub[i];
//		}
//		if (sum == amount){
//			if (sub.size() < res)
//				res = sub.size();
//			return;
//		}
//		else if (sum > amount){
//			return;
//		}
//		else {
//			for (int i = start; i < coins.size(); ++i){
//				if (coins[i] > amount)
//					continue;
//				sub.push_back(coins[i]);
//				backtrack(coins, amount, i, sub, res);
//				sub.pop_back();
//			}
//		}
//	}
//};
#pragma endregion

#pragma region DFS_solution_on_leetcode
#include <algorithm>
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// sort(coins.begin(), coins.end(), [](int A, int B){return A > B;});
		// sort(coins.begin(), coins.end());
		sort(coins.begin(), coins.end(), greater<int>());
		DFS(coins, amount, 0, 0);
		if (min == INT_MAX) {
			return -1;
		}
		else {
			return min;
		}
	}

	void DFS(vector<int>& c, int sum, int begin, int count) {
		if (sum == 0) {
			min = count;
		}
		else {
			for (int i = begin; i < c.size() && count + sum / c[i] < min; i++) {
				if (sum >= c[i]) {
					DFS(c, sum - c[i], i, count + 1);
				}
			}
		}
	}

private:
	int min = INT_MAX;

};
#pragma endregion

void q0322_tester()
{
	Solution s;
	vector<int> q;

	q = { 1, 2, 5 };
	//cout << s.coinChange(q, 11) << endl; //expect: 3

	q = { 2 };
	//cout << s.coinChange(q, 3) << endl; //expect: -1

	q = { 1, 2147483647 };
	//cout << s.coinChange(q, 2) << endl; //expect: 2

	q = { 186, 419, 83, 408 };
	cout << s.coinChange(q, 6249) << endl;  //expect: 20
}
