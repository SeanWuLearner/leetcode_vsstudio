#pragma once

#include "DebugUtils.h"
#include "ListNode.h"


#pragma region using_prioritized_data_structure
//#include <map>
//class Solution {
//public:
//	ListNode* mergeKLists(vector<ListNode*>& lists) {
//		multimap<int, int> sort_buf;  //<val, list_idx>
//		int empty_cnt = 0;
//		ListNode *ans_head = new ListNode(0);
//		ListNode *cur = ans_head;
//
//		//initial round, insert 1 node from each list
//		for (int i = 0; i < lists.size(); i++)
//			if (lists[i] != NULL)			
//				sort_buf.insert(pair<int, int>(lists[i]->val, i));
//			else
//				empty_cnt++;
//
//		//drain all the node in the lists
//		int idx;
//		while (empty_cnt != lists.size())
//		{
//			auto it = sort_buf.begin();
//			idx = (*it).second;
//			cur->next = lists[idx]; 
//			cur = cur->next;
//			sort_buf.erase(it);
//			
//			//forward the list and insert a new one
//			lists[idx] = lists[idx]->next;
//			if (lists[idx] != NULL)
//				sort_buf.insert(pair<int, int>(lists[idx]->val, idx));
//			else
//				empty_cnt++;
//		}
//
//		//flush the rest nodes.
//		for (auto it = sort_buf.begin(); it != sort_buf.end(); it++)
//		{
//			idx = (*it).second;
//			cur->next = lists[idx];
//			cur = cur->next;
//		}		
//		return ans_head->next;		
//	}
//};
#pragma endregion

#pragma region fastest_solution_MergeWithDivideAndConquer
class Solution {
private:
	ListNode * merge2Lists(ListNode *l1, ListNode *l2)
	{
		ListNode *head = new ListNode(-1);
		ListNode *cur = head;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		if (l1 != NULL)
			cur->next = l1;
		else
			cur->next = l2;

		cur = head->next;
		delete head;
		return cur;
	}
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		int step = 1;

		if (lists.size() == 0)
			return NULL;

		while (step < lists.size())
		{
			for (int i = 0; i + step < lists.size(); i += step << 1)
				lists[i] = merge2Lists(lists[i], lists[i + step]);
			step <<= 1;
		}
		return lists[0];
	}
};
#pragma endregion

void q0023_tester()
{
	Solution s;
	ListNode* ans;
	vector<ListNode*> q;
	q.emplace_back(ListNode::genListHead({ 1, 4, 5 }, -1));
	q.emplace_back(ListNode::genListHead({ 1, 3, 4 }, -1));
	q.emplace_back(ListNode::genListHead({ 2, 6 }, -1));

	//for (auto i : q)
	//	ListNode::printList(i);

	ans = s.mergeKLists(q);
	ListNode::printList(ans); //expect 1->1->2->3->4->4->5->6


	q.clear();
	q.emplace_back(ListNode::genListHead({ 1 }, -1));
	q.emplace_back(ListNode::genListHead({ 0 }, -1));
	ans = s.mergeKLists(q);
	ListNode::printList(ans); //expect 0->1
}
