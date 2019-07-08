#pragma once

#include "DebugUtils.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <unordered_set>
typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x, ListNode *next = NULL) : val(x), next(next) {}
	static ListNode* genListHead(const vector<int> &list, int loop_pos)
	{
		ListNode* head = nullptr;
		ListNode* prev = nullptr, *cur;
		ListNode* loop = nullptr;
		int cur_pos = 0;

		if (list.size() == 0)
			return nullptr;

		for (const auto &i : list)
		{
			cur = new ListNode(i);

			if (prev != nullptr)
				prev->next = cur;

			if (cur_pos == 0)
				head = cur;

			if (cur_pos == loop_pos) //reserve the pointer for loop back later			
				loop = cur;

			prev = cur;
			cur_pos++;
		}

		if (loop_pos != -1)
			prev->next = loop;

		return head;
	}
	static void freeList(ListNode* head)
	{
		unordered_set<ListNode*> repeat_check;

		if (head == nullptr)
			return;

		ListNode* cur = head;
		ListNode* prev;

		do {
			if (repeat_check.count(cur) != 0)
				return;

			prev = cur;
			cur = cur->next;
			repeat_check.insert(prev);
			delete prev;
		} while (cur != nullptr);
	}
	static void printList(ListNode* head)
	{
		unordered_set<ListNode*> repeat_check;

		cout << "[ ";
		while (head != nullptr)
		{
			if (repeat_check.count(head) != 0)
			{
				cout << head->val << "(rep)...";
				break;
			}
			repeat_check.insert(head);
			cout << head->val << "-> ";

			head = head->next;
		}
		cout << "]" << endl;
	}
} ListNode;


class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		
		ListNode *dummy = new ListNode(0);
		ListNode *front, *back;

		dummy->next = head;
		back = front = dummy;
		while (n--)
			front = front->next;		

		while (front->next != NULL)
		{
			front = front->next;
			back = back->next;
		}

		//use front ptr to store the node to be delete
		front = back->next;
		back->next = back->next->next;
		delete front;
		return dummy->next;
	}
};

void q0019_tester() {
	Solution s;
	ListNode *ans;
	vector<int> l;
	ListNode *head;
	
	l = { 1,2,3,4,5 };
	head = ListNode::genListHead(l, -1);
	ans = s.removeNthFromEnd(head, 2);
	ListNode::printList(ans);

	l = { 1 };
	head = ListNode::genListHead(l, -1);
	ans = s.removeNthFromEnd(head, 1);  
	ListNode::printList(ans); //expect []

	l = { 1,2 };
	head = ListNode::genListHead(l, -1);
	ans = s.removeNthFromEnd(head, 2);  
	ListNode::printList(ans); //expect [2]


}