#pragma once

#pragma once

#include "DebugUtils.h"
#include "ListNode.h"

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


