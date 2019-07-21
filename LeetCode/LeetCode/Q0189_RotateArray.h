#pragma once

#include "DebugUtils.h"

#pragma region O(n)_mem_consumption
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		int n = nums.size();
//		vector<int> ans(n);
//
//		for (int i = 0; i < n; i++)		
//			ans[(i + k) % n] = nums[i];
//		
//		nums = ans;
//	}
//};
#pragma endregion

#pragma region O(1)_mem_CyclicReplacements 
//class Solution {
//public:
//	template < typename T >
//	T GCD(T a, T b) {
//		if (b) while ((a %= b) && (b %= a));
//		return a + b;
//	}
//
//	void rotate(vector<int>& nums, int k) {
//		int n = nums.size();
//		int gcd = GCD(n, k);
//		int times = n / gcd;
//		int tmp;
//
//		for (int i = 0; i < gcd; i++)
//		{	
//			int j;
//			tmp = nums[i];			
//			for (j = i + k * (times-1); j > i ; j -= k)
//				nums[(j + k) % n] = nums[j % n];			
//			nums[(j + k) % n] = tmp;
//		}
//	}
//};
#pragma endregion

#pragma region O(1)_mem_CyclicReplacements_ver2
//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		int n = nums.size();
//		int count = 0;		
//
//		for (int start = 0; count < n; start++)
//		{
//			int current = start;
//			int prev = nums[start];
//			do
//			{
//				int next = (current + k) % n;
//				//rotation
//				int tmp = nums[next];
//				nums[next] = prev;
//				prev = tmp;				
//
//				//prepare for next round
//				current = next;
//				count++;
//			} while (current != start);
//		}
//	}
//};
#pragma endregion

#pragma region ReverseArrayManner
#include <algorithm>
class Solution {	
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 1) return;
		int true_k = k % nums.size(); //in case iterator would overflow.
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin()+ true_k);
		std::reverse(nums.begin()+ true_k, nums.end());
	}
};
#pragma endregion


void q0189_tester()
{
	Solution s;
	vector<int> q;

	q = { 1,2,3,4,5,6,7 };
	s.rotate(q, 3);
	print(q); //expect 5,6,7,1,2,3,4

	q = { -1,-100,3,99 };
	s.rotate(q, 2);
	print(q); //expect 3,99,-1,-100
}



