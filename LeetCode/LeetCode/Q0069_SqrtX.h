
#pragma once

#include "DebugUtils.h"

#pragma region step_by_twice_approach
//class Solution {
//public:
//	int mySqrt(int x) {
//		unsigned int ans = 0;
//		long long i;
//
//		while (true)
//		{
//			i = 1;
//			while ((ans + i)*(ans + i) <= x)
//			{
//				i <<= 1;
//			}
//			if (i == 1)
//				break; // answer found: (ans+1) ^ 2 is greater than x
//			ans += i >> 1;
//		}		
//		return ans;
//	}
//};
#pragma endregion

#pragma region binary_search_manner

/*
### Hints for binary search ###
Q1.is there any difference between
    mid = (L + R) << 1;
    mid = L + ((R - L) << 1);
A1.NO.we should pick the easy one.

Q2.what is our answer ? mid ? right ? left ?
A2.The mid is stick to the left hand side due to the mid is computed by.
    mid = (L + R) / 2. under this circurtance,
    1. if the right is the one violate the condition(L <= R)
        then, right is the answer because the mid is less than our expect
        target.
    2. if the left is the one to violate the condition(L <= R)
        then, right is still the answer because L across the restriction
        actively.
*/

class Solution {
public:
	int mySqrt(int x) {
		long long res, mid = 0, low = 0, high = x;			

		while (low <= high)
		{
			mid = (high + low) / 2;
			res = mid * mid;
			if (res == x)
				return mid;
			else if (res < x) 
				low = mid + 1;											
			else
				high = mid - 1;
		}
		return high;
	}
};
#pragma endregion

void q0069_tester()
{
	Solution s;

	cout << s.mySqrt(4) << endl; //expect 2
	cout << s.mySqrt(8) << endl; //expect 2
	cout << s.mySqrt(2147395600) << endl; //expect 46340
	cout << s.mySqrt(1) << endl; //expect 1

	//int mid1, mid2;
	////cout << "(i+j)/2 manner" << endl;
	//for(int i = 0 ; i < 100 ; i++)	
	//{
	//	for (int j = i; j < 100; j++)
	//	{
	//		mid1 = (i + j) >> 1;
	//		mid2 = i + ((j - i) >> 1);
	//		if (mid1 != mid2)
	//			printf("diff hit, while(%d, %d)\r\n", i, j);
	//	}
	//	//cout << endl;
	//}	

}



