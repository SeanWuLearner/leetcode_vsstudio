#pragma once

#include "DebugUtils.h"

#pragma region using_multiset
//#include <set>
//class MedianFinder {
//private:
//	multiset<int> data;
//	multiset<int>::iterator it_l;
//	multiset<int>::iterator it_r;
//
//public:
//	/** initialize your data structure here. */
//	MedianFinder() {
//	}
//
//	void addNum(int num) {
//		int n = data.size();
//		data.insert(num);
//		if (n == 0)	 //initial case
//			it_l = it_r = data.begin();		
//		else if (data.size() % 2 != 0)  //odd nums case		
//			if (num < *it_l)
//				it_l--;
//			else
//				it_r++;		
//		else //even nums case		
//			if (num < *it_l)
//				it_r--;
//			else if (num >= *it_r) // include '=' here is becase it will insert the identical new comer to behind.
//				it_l++;
//			else
//			{
//				it_l++;
//				it_r--;
//			}		
//	}
//
//	double findMedian() {
//		return (*it_l + *it_r) / 2.0;
//	}
//};
#pragma endregion

#pragma region using_multiset_one_pointer
//#include <set>
//class MedianFinder {
//private:
//	multiset<int> data;
//	multiset<int>::iterator it_r;	
//
//public:
//	/** initialize your data structure here. */
//	MedianFinder() {
//	}
//
//	void addNum(int num) {
//		int n = data.size();
//		data.insert(num);
//		if (n == 0)	 //initial case
//			it_r = data.begin();
//		else if (num < *it_r)
//			it_r = (n & 1) ? it_r : prev(it_r);
//		else
//			it_r = (n & 1) ? next(it_r) : it_r;			
//	}
//
//	double findMedian() {
//		return (*it_r + *next(it_r, (data.size() % 2) - 1)) *0.5;
//	}
//};
#pragma endregion

#pragma region two_heap_manner
#include <queue>
class MedianFinder {
	priority_queue<int> bottom;
	priority_queue<int, vector<int>, greater<int>> top;
public:

	void addNum(int num) {
		if (bottom.size() == 0)
			bottom.push(num);
		else if (num <= bottom.top())
		{
			bottom.push(num);
			if (bottom.size() > top.size() + 1)
			{
				top.push(bottom.top());
				bottom.pop();
			}
		}
		else
		{
			top.push(num);
			if (bottom.size() < top.size())
			{
				bottom.push(top.top());
				top.pop();
			}
		}

		#pragma region brief manner but time costy
		////insert and keep two side sorted.
		//bottom.push(num);
		//top.push(bottom.top());
		//bottom.pop();		

		////balance
		//if (top.size() > bottom.size())
		//{
		//	bottom.push(top.top());
		//	top.pop();
		//}
		#pragma endregion
	}

	double findMedian() {
		if ((top.size() + bottom.size()) % 2 == 0)
			return (top.top() + bottom.top()) *0.5;
		else
			return bottom.top();
	}
};
#pragma endregion

void test_helper(vector<string> s, vector<int> arg)
{
	MedianFinder* obj = new MedianFinder();
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == "MedianFinder")
		{
			obj = new MedianFinder();
			cout << "null, ";
		}
		else if (s[i] == "addNum")
		{
			obj->addNum(arg[i]);
			cout << "null, ";
		}
		else if (s[i] == "findMedian")
		{
			cout << obj->findMedian() << ", ";
		}
	}
}

void q0295_tester()
{
	
	////test case 1
	//MedianFinder* obj = new MedianFinder();
	//obj->addNum(1);
	//obj->addNum(2);
	//cout << obj->findMedian() << endl; //output 1.5
	//obj->addNum(3);
	//cout << obj->findMedian() << endl; //output 2

	vector<string> s;
	vector<int> args;
	s = { "MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian" };
	args = { {}, {6}, {}, {10}, {}, {2}, {}, {6}, {}, {5}, {}, {0}, {}, {6}, {}, {3}, {}, {1}, {}, {0}, {}, {0}, {} };
	test_helper(s, args); //expect [null,null,6.0,null,8.0,null,6.0,null,6.0,null,6.0,null,5.5,null,6.0,null,5.5,null,5.0,null,4.0,null,3.0]
	
}



