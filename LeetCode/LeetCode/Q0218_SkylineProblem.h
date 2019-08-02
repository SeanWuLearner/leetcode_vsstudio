#pragma once
#include "DebugUtils.h"

#pragma region wrong_answer...
//#include <set>
//#include <map>
//#include <functional>
//#include <algorithm>
//class Solution {		
//public:
//	enum Idx{
//		LI = 0,
//		RI = 1,
//		HI = 2
//	};
//	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//		multiset<int, std::greater<int>> max_height{ 0 };
//		multimap<unsigned int, int> right_tbl{ { UINT_MAX, 0 } }; //<left, height> init pair for easing the condition...
//		int cur_max = INT_MIN;
//		vector<vector<int>> ans;
//
//		for (auto it = buildings.begin(); it != buildings.end() || right_tbl.size() > 1;)
//		{
//			auto rit = right_tbl.begin();
//			unsigned int cur_x = (it == buildings.end()) ? (*rit).first : min((*rit).first, (unsigned int)(*it)[LI]);
//
//			while (it!=buildings.end() && (*it)[LI] == cur_x)
//			{
//				max_height.insert((*it)[HI]);
//				right_tbl.insert({ (*it)[RI], (*it)[HI] });
//				it++;
//			}
//
//			while (right_tbl.size() > 1 && (*rit).first == cur_x)
//			{				
//				max_height.erase((*rit).second); //FATAL: it erase multiple element at once...
//				right_tbl.erase(rit, next(rit));
//				rit = right_tbl.begin();
//			}
//			
//			auto hit = max_height.begin();
//			if (ans.empty() || ans.back()[1] != *hit)							
//				ans.push_back({ (int)cur_x, *hit });			
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region using_priority_queue
//#include <queue>
//class Solution {
//public:
//	enum Idx{
//		LI = 0,
//		RI = 1,
//		HI = 2
//	};
//	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//		vector <vector<int>> ans;
//		priority_queue<pair<int, int>> max_heap; //<height, right>
//		int i = 0, len = buildings.size();
//		int cur_x, cur_h;
//
//		while (i < len || max_heap.empty() == false)
//		{			
//			if (max_heap.empty() || i < len && buildings[i][LI] <= max_heap.top().second)  //edge case: still need to push first while building1.L == building2.R
//			{
//				cur_x = buildings[i][LI];
//				while (i < len && cur_x == buildings[i][LI])
//				{
//					max_heap.emplace(buildings[i][HI], buildings[i][RI]);
//					i++;
//				}
//			}
//			else
//			{
//				cur_x = max_heap.top().second;
//				while (max_heap.empty() == false && cur_x >= max_heap.top().second)				
//					max_heap.pop();				
//			}
//
//			cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
//			if (ans.empty() || cur_h != ans.back()[1])
//				ans.push_back({cur_x, cur_h});
//		}
//		return ans;
//	}
//};
#pragma endregion

#pragma region divide_and_conquer_on_geeksforgeeks
#include <algorithm>
class Solution {
private:
	typedef vector<vector<int>> VInt2D;
	enum Idx {
		IL = 0,
		IR = 1,
		IH = 2
	};

	void mergeSkyline(VInt2D& v1, VInt2D& v2, VInt2D& result)
	{
		int m = v1.size(), n = v2.size();
		int i = 0, j = 0;
		int h1 = 0, h2 = 0, x, max_val;

		while (i < m || j < n)
		{
			if (j==n || (i<m && v1[i][0] < v2[j][0]))
			{
				x = v1[i][0];
				h1 = v1[i][1];
				i++;
			}
			else if (i==m || (j<n && v1[i][0] > v2[j][0]))
			{
				x = v2[j][0];
				h2 = v2[j][1];
				j++;
			}
			else
			{
				x = v1[i][0];
				h1 = v1[i][1];
				h2 = v2[j][1];				
				i++; j++;
			}

			max_val = max(h1, h2);
			if (result.empty() || result.back()[1] != max_val)
				result.push_back({ x, max_val });
		}

	}

	void getSkylineHelper(VInt2D& buildings, int l, int h, VInt2D& result)
	{
		if (l == h)
		{
			result.push_back({ buildings[l][IL], buildings[l][IH] });
			result.push_back({ buildings[l][IR], 0 });
			return;
		}

		int mid = (l + h) >> 1;
		VInt2D res_l, res_r;
		getSkylineHelper(buildings, l, mid, res_l);
		getSkylineHelper(buildings, mid+1, h, res_r);
		mergeSkyline(res_l, res_r, result);
	}
public:

	vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
	{
		if (buildings.empty()) return {};
		vector<vector<int>> ans;
		getSkylineHelper(buildings, 0, buildings.size() - 1, ans);
		return ans;
	}
};
#pragma endregion

void q0218_tester()
{
	Solution s;
	vector<vector<int>> ans;
	vector<vector<int>> q;
	q = {
		{ 2, 9, 10 },
	{ 3, 7, 15 },
	{ 5, 12, 12 },
	{ 15, 20, 10 },
	{ 19, 24, 8 }
	};

	ans = s.getSkyline(q);
	print(ans); // expect [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]

	//q = {
	//	{ 0,2,3 },
	//{ 2,5,3 }
	//};
	//ans = s.getSkyline(q);
	//print(ans); // expect [ [0,3] [5,0] ]




}
