#pragma once

#include "DebugUtils.h"

#pragma region O(n)mem
//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int n = gas.size();
//		vector<int> profit(n);
//		
//		for (int i = 0; i < n; i++)
//			profit[i] = gas[i] - cost[i];
//
//		int sum = 0;
//		int min = INT_MAX;
//		int min_idx = -1;
//
//		for (int i = 0; i < n; i++)
//		{
//			sum += profit[i];
//			if (sum < min)
//			{
//				min = sum;
//				min_idx = i;
//			}
//		}
//
//		if (sum < 0)
//			return -1;
//		else
//			return (min_idx == n - 1) ? 0 : min_idx + 1;
//	}
//};
#pragma endregion

#pragma region O(1)mem_fastest_solution_on_leetcode
//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int cur_gas = 0;
//		int n = gas.size();
//		int min = INT_MAX;
//		int min_idx;
//
//		for (int i = 0; i < n; i++)
//		{
//			cur_gas += gas[i] - cost[i];
//			if (cur_gas < min)
//			{
//				min = cur_gas;
//				min_idx = i;
//			}
//		}
//		if (cur_gas < 0)
//			return -1;
//		else
//			return (min_idx + 1) % n;
//	}
//};
#pragma endregion

#pragma region idea_to_find_the_non_neg_start
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int sum = 0;
		int start = 0;
		int tank = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			tank += gas[i] - cost[i];
			if (tank < 0)
			{
				sum += tank;
				tank = 0;
				start = i + 1;
			}
		}
		sum += tank;

		return (sum < 0) ? -1 : start % gas.size();
	}
};
#pragma endregion


void q0134_tester()
{
	Solution s;

	vector<int> gas;
	vector<int> cost;

	gas = { 1,2,3,4,5 };
	cost = { 3,4,5,1,2 };
	cout << s.canCompleteCircuit(gas, cost) << endl; //expect 3
	
	gas = { 2,3,4 };
	cost = { 3,4,3 };
	cout << s.canCompleteCircuit(gas, cost) << endl; //expect -1
}



