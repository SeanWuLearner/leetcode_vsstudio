
#pragma once

#include "DebugUtils.h"
#include <algorithm>
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int min_price = prices[0];
		int max_profit = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < min_price)
				min_price = prices[i];
			else if (prices[i] - min_price > max_profit)
				max_profit = prices[i] - min_price;

			//if (prices[i] > min_price)
			//	max_profit = std::max(max_profit, prices[i] - min_price);
			//else
			//	min_price = prices[i];
		}
		return max_profit;
	}
};

void q0121_tester()
{
	Solution s;
	vector<int> q;

	q = { 7, 1, 5, 3, 6, 4 };
	cout << s.maxProfit(q) << endl; //expect: 5, where 6-1 = 5

	q = { 7, 6, 4, 3, 1 };
	cout << s.maxProfit(q) << endl; //expect: 0
}



