#include "stdafx.h"
#include "DebugUtils.h"


void print(const vector<int> &v)
{
	for (const auto &i : v)
	{
		cout << i << ", ";
	}
	cout << endl;
}

void print(const vector<vector<int>> &v)
{
	for (const auto &i : v)
	{
		print(i);
	}
}