#pragma once

#include "DebugUtils.h"

#pragma region my_one_pass
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		bool have_stock = false;
//		int profit = 0;
//		int buy_price;
//		int i;
//		for (i = 0; i< ((int)prices.size()) - 1; i++)
//		{
//			if (have_stock == false && prices[i] < prices[i + 1])
//			{
//				buy_price = prices[i];
//				have_stock = true;
//			}
//			else if (have_stock == true && prices[i] > prices[i + 1])
//			{
//				profit += prices[i] - buy_price;
//				have_stock = false;
//			}
//		}
//		if (have_stock)
//			profit += prices[i] - buy_price;
//
//		return profit;
//	}
//};
#pragma endregion 

#pragma region incredible_one_pass
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int profit = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (prices[i] < prices[i + 1])
				profit += prices[i + 1] - prices[i];
		}
		return profit;
	}
};
#pragma endregion 

void q0122_tester()
{
	Solution s;
	vector<int> q;


	q = { 7,1,5,3,6,4 };
	cout << s.maxProfit(q) << endl; // 7

	q = { 1,2,3,4,5 };
	cout << s.maxProfit(q) << endl; // 4

	q = { 7,6,4,3,1 };
	cout << s.maxProfit(q) << endl; // 0

	q = {};
	cout << s.maxProfit(q) << endl; // 0
}
