#pragma once

#include "DebugUtils.h"

#pragma region O_nlogn_sorting
//#include <functional>
//#include <unordered_map>
//#include <map>
//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		
//		unordered_map<int, int> cnt_tbl;
//		for (auto &i : nums)
//			if (cnt_tbl.count(i) == 0)
//				cnt_tbl[i] = 1;
//			else
//				cnt_tbl[i]++;
//
//		//build a ordered inverse map
//		multimap<int, int, std::greater<int>> order_tbl;
//		for (auto &i : cnt_tbl)
//			order_tbl.insert({ i.second, i.first });
//
//		vector<int> ans;
//		for (auto &i : order_tbl)		
//			if (k-- == 0)
//				break;
//			else
//				ans.push_back(i.second);		
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region bucket_sorting
#include <unordered_map>
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {

		unordered_map<int, int> cnt_tbl;
		for (auto &i : nums)
			if (cnt_tbl.count(i) == 0)
				cnt_tbl[i] = 1;
			else
				cnt_tbl[i]++;

		vector<vector<int>> bucket(nums.size() + 1);
		for (auto &i : cnt_tbl)
			bucket[i.second].push_back(i.first);

		vector<int> ans;
		for (auto it = bucket.rbegin(); it != bucket.rend() && ans.size() < k; it++)	
			if((*it).size() != 0)			
				ans.insert(ans.end(), (*it).begin(), (*it).end());								

		return ans;
	}
};
#pragma endregion

void q0347_tester()
{
	Solution s;

	vector<int> q;
	vector<int> ans;

	q = { 1, 1, 1, 2, 2, 3 };
	ans = s.topKFrequent(q, 2); //ans: 1, 2
	print(ans);

	q = { 1 };
	ans = s.topKFrequent(q, 1); // ans: 1
	print(ans);

}
