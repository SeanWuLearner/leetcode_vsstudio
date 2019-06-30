#pragma once

#include "DebugUtils.h"
#include "stack"
#include <algorithm>

#pragma region sean_1st_edition
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& heights) 
//	{
//		stack<int> stk;
//		int max=0, h, area;
//		int i;
//
//		for (i = 0; i < heights.size(); i++)
//		{
//			if (stk.empty() || heights[stk.top()] <= heights[i])
//			{
//				stk.push(i);
//			}			
//			else
//			{
//				while (stk.empty()==false && heights[i] < heights[stk.top()] )
//				{
//					h = heights[stk.top()];
//					stk.pop();
//					while (stk.empty() == false && h == heights[stk.top()])
//						stk.pop();
//
//					if (stk.empty() == false)
//						area = h * (i - stk.top() - 1);
//					else
//						area = h * i;
//
//					if (area > max)
//						max = area;
//				}
//				stk.push(i);
//			}
//		}
//
//		//dealing the remaing part in stak.
//		while (stk.empty() == false)
//		{
//			h = heights[stk.top()];
//			stk.pop();
//			while (stk.empty() == false && h == heights[stk.top()])
//				stk.pop();
//
//			if (stk.empty() == false)
//				area = h * (i - stk.top() - 1);
//			else
//				area = h * i;
//
//			if (area > max)
//				max = area;
//		}
//
//		return max;
//	}
//};
#pragma endregion

#pragma region leetcode_4ms_ans
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& heights) {
//		int maxArea = 0, thisArea, n = heights.size();
//		for (int i = 0; i<n; i++) {
//			if (i + 1<n && heights[i + 1] >= heights[i])
//				continue;
//			int minHeight = heights[i];
//			for (int j = i; j >= 0; j--) {
//				minHeight = min(minHeight, heights[j]);
//				maxArea = max(maxArea, minHeight*(i - j + 1));
//			}
//		}
//		return maxArea;
//	}
//};
#pragma endregion
#pragma region leetcode_8ms_ans
//class Solution {
//public:
//	int largestRectangleArea(vector<int>& heights) {
//		if (heights.empty()) return 0;
//
//		vector<int> indexes;
//		indexes.push_back(-1);
//		int n = heights.size();
//		int res = 0;
//
//		for (int i = 0; i < n; i++) {
//			while (indexes.back() != -1 && heights[i] < heights[indexes.back()]) {
//				int cur = indexes.back(); //use heights[cur] as rectangle's height
//				indexes.pop_back(); //after removing cur, indexes.back() is the nearest index with height < heights[cur]
//				int width = i - indexes.back() - 1; //it works even indexes.back() == -1 after pop_back()
//				res = max(res, heights[cur] * width);
//			}
//			indexes.push_back(i);
//		}
//
//		//there may be indexes unprocessed. for example, the whole heights is increasing
//		while (indexes.back() != -1) {
//			int cur = indexes.back(); //use heights[cur] as rectangle's height
//			indexes.pop_back(); //after removing cur, indexes.back() is the nearest index with height < heights[cur]
//								// int width = cur - indexes.back();  //BUG
//			int width = n - indexes.back() - 1;
//			res = max(res, heights[cur] * width);
//		}
//
//		return res;
//	}
//};
#pragma endregion
#pragma region quick_alternative_to_find_boundary
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (n == 0)
			return 0;

		vector<int> bound_l(n);
		vector<int> bound_r(n);

		bound_l[0] = -1;
		bound_r[n - 1] = n;

		int j;
		for (int i = 1; i < n; i++)
		{
			j = i - 1;

			while (j >= 0 && heights[j] >= heights[i])
			{
				j = bound_l[j];
			}

			bound_l[i] = j;
		}

		for (int i = n-2; i>=0; i--)
		{
			j = i + 1;

			while (j <= n-1 && heights[j] >= heights[i])
			{
				j = bound_r[j];
			}

			bound_r[i] = j;
		}

		int ret = -1;
		for (int i = 0; i < n; i++)
			ret = max(ret, heights[i] * (bound_r[i] - bound_l[i] - 1));

		return ret;
	}
};
#pragma endregion
void q0084_tester()
{
	Solution s;
	vector<int> q;

	//q = { 2,1,5,6,2,3 };
	//cout << s.largestRectangleArea(q) << endl; //expect 10

	//q = { 1,1 };
	//cout << s.largestRectangleArea(q) << endl; //expect 2

	//q = { 4,2,0,3,2,4,3,4 };
	//cout << s.largestRectangleArea(q) << endl; //expect 10

	//q = { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3 };
	//cout << s.largestRectangleArea(q) << endl; //expect 14

	q = { 2,3 };
	cout << s.largestRectangleArea(q) << endl; //expect 4 
}
