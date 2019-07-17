#pragma once

#include "DebugUtils.h"
#include "ListNode.h"

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