#pragma once

#include <vector>
#include <iostream>

using namespace std;


template<typename T>
void print(const vector<T> &v)
{
	for (const auto &i : v)
	{
		cout << i << ", ";
	}
	cout << endl;
}

template<typename T>
void print(const vector<vector<T>> &v)
{
	for (const auto &i : v)
	{
		print(i);
	}
}
