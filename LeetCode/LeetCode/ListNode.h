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
	static ListNode* genListHead(const vector<int> &list, int loop_pos = -1)  //give loop_pos = -1 if no loop at all.
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