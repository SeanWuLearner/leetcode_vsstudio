#pragma once

#include "DebugUtils.h"
#include <vector>
#include <climits>
#include <algorithm>

#pragma region seanwu_1st_summit
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		int m = nums1.size(), n = nums2.size();
//		int i1 = m / 2;
//		int i2 = ((m + n) / 2) - i1;
//		bool cond1, cond2;
//
//		while (true)
//		{
//			cond1 = (i2==0 || i1==m)? true : (nums1[i1] >= nums2[i2 - 1]);
//			cond2 = (i1==0 || i2==n)? true : (nums2[i2] >= nums1[i1 - 1]);
//			if (cond1 && cond2)
//				break;
//			else if (cond1)
//			{
//				if (i2 != n) i2++;
//				if (i1 != 0) i1--;							
//			}
//			else
//			{
//				if (i1 != m) i1++;
//				if (i2 != 0) i2--;
//			}
//		}
//
//		int small1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
//		int big1 = (i1 == m) ? INT_MAX : nums1[i1];
//		int small2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
//		int big2 = (i2 == n) ? INT_MAX : nums2[i2];
//
//		if ((m + n) % 2 == 0) //even case
//			return (max(small1, small2) + min(big1, big2))/ 2.0 ;
//		else  //odd case
//			return min(big1, big2);		
//	}
//};
#pragma endregion

#pragma region recursive_manner_from_others
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size();
		int l2 = nums2.size();

		return (findMedianSortedArraysCore(nums1, 0, nums2, 0, (l1 + l2 + 1) / 2)
			+ findMedianSortedArraysCore(nums1, 0, nums2, 0, (l1 + l2 + 2) / 2)) / 2.0;
	}

private:	
	int findMedianSortedArraysCore(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int K) {
		if (start1 >= nums1.size())
			return nums2[start2 + K - 1];
		if (start2 >= nums2.size())
			return nums1[start1 + K - 1];

		if (K == 1)
			return nums1[start1] > nums2[start2] ? nums2[start2] : nums1[start1];

		if ((start1 + K / 2 - 1) >= nums1.size())
			return findMedianSortedArraysCore(nums1, start1, nums2, start2 + K / 2, K - K / 2);
		if ((start2 + K / 2 - 1) >= nums2.size())
			return findMedianSortedArraysCore(nums1, start1 + K / 2, nums2, start2, K - K / 2);

		int mid1 = nums1[start1 + K / 2 - 1];
		int mid2 = nums2[start2 + K / 2 - 1];

		if (mid1 >= mid2)
			return findMedianSortedArraysCore(nums1, start1, nums2, start2 + K / 2, K - K / 2);
		else
			return findMedianSortedArraysCore(nums1, start1 + K / 2, nums2, start2, K - K / 2);
	}
};
#pragma endregion

void q0004_tester()
{
	Solution s;

	vector<int> t1{ 1,3 };
	vector<int> t2{ 2 };
	cout << s.findMedianSortedArrays(t1, t2) << endl;

	t1 = { 1, 2 };
	t2 = { 3, 4 };
	cout << s.findMedianSortedArrays(t1, t2) << endl;

	t1 = { 1,2,3};
	t2 = { 4 };
	cout << s.findMedianSortedArrays(t1, t2) << endl;

}
