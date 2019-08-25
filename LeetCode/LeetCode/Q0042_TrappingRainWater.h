#pragma once

#include "DebugUtils.h"

#pragma region my_naive_stack_manner
//#include <algorithm>
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int n = height.size();
//		if (n <= 2) return 0;
//		vector<pair<int, int>> stk;
//		int area = 0;
//
//		//let go first upward trend => stop at the first downward
//		stk.push_back({ height[0], 0 });
//		int i = 1;
//		for (; i < n; i++)
//		{			
//			if (height[i] < stk.back().first)
//			{
//				stk.push_back({ height[i], i });
//				break;
//			}				
//			stk.push_back({ height[i], i });			
//		}
//
//		//start processing
//		i++;
//		for (; i < n; i++)
//		{
//			int bottom = stk.back().first;
//			while (height[i] > bottom && stk.empty() == false)
//			{
//				pair<int, int> prev = { bottom, i + 1 }; //bottom for start the while loop easily, i+1 would make sure area remain the same if stk empty.					
//				while (stk.empty()==false && prev.first <= bottom)
//				{					
//					prev = stk.back();
//					stk.pop_back();
//				} 
//				
//				int calc_height = std::min(height[i], prev.first);
//				if (calc_height > bottom)
//				{
//					area += (calc_height - bottom) * (i - prev.second - 1);
//					bottom = calc_height; // new bottom
//				}				
//				
//				if (prev.first > height[i])
//					stk.push_back(prev);
//			}
//			stk.push_back({ height[i], i });
//		}
//
//		return area;
//	}
//};
#pragma endregion

#pragma region concise_stack
#include <algorithm>
class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> stk;
		int area = 0;

		for (int i = 0; i < height.size(); i++)
		{
			while (stk.empty() == false && height[stk.back()] < height[i])
			{
				int bottom = stk.back();
				stk.pop_back();
				if (stk.empty() == true)
					break;
				int bounded_high = std::min(height[stk.back()], height[i]) - height[bottom];
				area += bounded_high * (i - stk.back() - 1);
			}
			stk.push_back(i);
		}
		return area;
	}
};
#pragma endregion

#pragma region DP
//#include <algorithm>
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int n = height.size();
//		if (n == 0) return 0;
//		vector<int> max_left(n), max_right(n);
//
//		//compute max_left		
//		max_left[0] = height[0];
//		for (int i = 1; i < n; i++)
//			max_left[i] = std::max(max_left[i - 1], height[i]);
//
//		//compute max_right
//		max_right[n - 1] = height[n - 1];
//		for (int i = n-2; i >= 0; i--)
//			max_right[i] = std::max(max_right[i + 1], height[i]);
//
//		//compute area
//		int area = 0;
//		for (int i = 1; i < n - 1; i++)
//			area += min(max_left[i], max_right[i]) - height[i];
//			//area += max(min(max_left[i - 1], max_right[i + 1]) - height[i], 0 );
//
//		return area;
//	}
//};
#pragma endregion

#pragma region two_pointer_genius_manner
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int left_max = 0, right_max = 0;
//		int n = height.size();
//		int left = 0, right = n - 1;
//		int area = 0;
//		while (left < right)
//		{
//			//move the smaller side, raise the bar (left_max, right_max) as slow as possible.
//			if (height[left] < height[right])
//			{
//				if (height[left] > left_max)
//					left_max = height[left];
//				else
//					area += left_max - height[left];
//				left++;
//			}
//			else 
//			{
//				if (height[right] > right_max)
//					right_max = height[right];
//				else
//					area += right_max - height[right];
//				right--;
//			}
//		}
//		return area;
//	}
//};
#pragma endregion

void q0042_tester()
{
	Solution s;
	vector<int> q;


	q = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << s.trap(q) << endl; // 6

	q = { 4,2,3 };
	cout << s.trap(q) << endl; // 1

	q = { 2,1,0,2 };
	cout << s.trap(q) << endl; // 3
}
