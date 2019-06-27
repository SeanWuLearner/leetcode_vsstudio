#pragma once

#include "DebugUtils.h"

#pragma region sean_1st_edition
//class Solution {
//private:
//	vector<bool> loop_checker_;
//	vector<bool> vertices_checker_;
//	vector<vector<int>> path_;
//
//	void buildPath(int vertices, vector<vector<int>>& table)
//	{
//		path_ = vector<vector<int>>(vertices);
//		for (auto edge : table)		
//			path_[edge[0]].push_back(edge[1]);		
//	}
//
//	bool hasLoop(int vertex)
//	{
//		vertices_checker_[vertex] = true;
//
//		if (loop_checker_[vertex] == true)
//			return true;
//		else
//			loop_checker_[vertex] = true; //set loop_check while entering.
//
//		for (int i : path_[vertex])
//		{
//			if (hasLoop(i) == true)
//				return true;
//		}
//		loop_checker_[vertex] = false;  //clear loop_check while leaving.
//		return false;
//	}
//public:
//	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
//	{
//		if (numCourses == 0 || prerequisites.size() == 0)
//			return true;
//
//		buildPath(numCourses, prerequisites);
//		vertices_checker_ = vector<bool>(numCourses);
//		loop_checker_ = vector<bool>(numCourses);
//		for (int i = 0; i < numCourses; i++)
//		{
//			//don't have to revisited the traveled vertices.
//			if (vertices_checker_[i] == true)
//				continue;
//			
//			//clear loop_checker_ in every loop.
//			std::fill(loop_checker_.begin(), loop_checker_.end(), false);
//
//			if (hasLoop(i) == true)
//				return false;
//		}
//		return true;
//	}
//};
#pragma endregion

#pragma region sean_rewrite_genius_ver
#include <queue>
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<vector<int>> limit_table(numCourses);
		vector<int> cnt(numCourses); //count of prerequisites courses.

									 //build limit_table.
		for (const auto &p : prerequisites)
		{
			limit_table[p[1]].push_back(p[0]);
			cnt[p[0]]++;
		}

		//start the puzzle from the course without limitation.
		queue<int> q;
		for (int i = 0; i < numCourses; i++)
			if (cnt[i] == 0)
				q.push(i);

		while (q.empty() != true)
		{
			int limit = q.front();
			q.pop();
			numCourses--;

			//decrease all the reference count
			for (int c : limit_table[limit])
			{
				cnt[c]--;
				if (cnt[c] == 0)
					q.push(c);
			}
		}
		return (numCourses == 0);
	}
};
#pragma endregion

#pragma region genius_ver_from_leetcode
//#include <queue>
//class Solution {
//public:
//	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
//	{
//		vector<vector<int>> graph(numCourses);
//		vector<int> in(numCourses, 0);
//
//		for (const auto & p : prerequisites)
//		{
//			graph[p[1]].push_back(p[0]);
//			in[p[0]]++;
//		}
//
//		queue<int> q;
//		for (int i = 0; i < in.size(); i++)
//		{
//			if (in[i] == 0)
//				q.push(i);
//		}
//
//		while (!q.empty())
//		{
//			auto front = q.front();
//			q.pop();
//			numCourses--;
//
//			for (auto child : graph[front])
//			{
//				in[child]--;
//				if (in[child] == 0)
//				{
//					q.push(child);
//				}
//			}
//		}
//
//		return numCourses == 0;
//	}
//};
#pragma endregion

void q0207_tester()
{
	Solution s;

	int num = 2;
	vector<vector<int>> r{ { 0, 1 },{ 1, 0 } };
	cout << s.canFinish(num, r) << endl;  //expect 'false'

	num = 2;
	r = { { 0, 1 } };
	cout << s.canFinish(num, r) << endl;  //expect 'true'

	return;
}

