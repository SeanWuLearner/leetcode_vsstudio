#pragma once

#include "DebugUtils.h"

#pragma region balance_run_time_mem_as_O(squareN)
#include <unordered_map>
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

		unordered_map<int, int> sum_cnt;
		int sum;
		int ret = 0;

		for (auto a : A)
			for (auto b : B)
			{
				sum = a + b;
				if (sum_cnt.count(sum) == 0)
					sum_cnt[sum] = 1;
				else
					sum_cnt[sum]++;
			}

		for (auto c : C)
			for (auto d : D)
			{
				sum = -(c + d);
				if (sum_cnt.count(sum) != 0)
					ret += sum_cnt[sum];
			}

		return ret;
	}
};
#pragma endregion

void q0454_tester()
{
	Solution s;
	vector<int> A, B, C, D;

	A = { 1, 2 };
	B = { -2, -1 };
	C = { -1, 2 };
	D = { 0, 2 };
	//cout << s.fourSumCount(A, B, C, D) << endl; //expect 2

	A = { -1, -1 };
	B = { -1, 1 };
	C = { -1, 1 };
	D = { 1, -1 };
	cout << s.fourSumCount(A, B, C, D) << endl; //expect 6
}
