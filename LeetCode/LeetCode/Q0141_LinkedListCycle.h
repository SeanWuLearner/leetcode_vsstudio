#pragma once

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
	static ListNode* genListHead(const vector<int> &list, int pos)
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

			if (cur_pos == pos) //reserve the pointer for loop back later			
				loop = cur;

			prev = cur;
			cur_pos++;
		}

		if (pos != -1)
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
			cout << head->val << ", ";

			head = head->next;
		}
		cout << "]" << endl;
	}
} ListNode;

#pragma region break_link_method
//class Solution {
//public:
//	bool hasCycle(ListNode *head) {
//		ListNode *dummy = new ListNode(123); //only the addr matters
//		ListNode *prev;
//
//		while (head != nullptr)
//		{
//			if (head == dummy)
//				return true;
//
//			prev = head;
//			head = head->next;
//			prev->next = dummy;
//		}
//		return false;
//	}
//};
#pragma endregion

#pragma region two_pointer_manner
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *fast;
		ListNode *slow;

		fast = slow = head;

		while (slow != nullptr && fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)
				fast = fast->next;
			else
				return false;

			if (slow == fast)
				return true;
		}
		return false;
	}
};
#pragma endregion

void q0141_tester()
{
	Solution s;
	vector<int> list;
	int pos;

	list = { 3, 2, 0, -4 };
	pos = 1;
	ListNode* head = ListNode::genListHead(list, pos);
	cout << s.hasCycle(head) << endl;  //expect 'true'
	ListNode::freeList(head);

	list = { 1 };
	pos = -1;
	head = ListNode::genListHead(list, pos);
	cout << s.hasCycle(head) << endl;  //expect 'false'
	ListNode::freeList(head);

	return;
}


