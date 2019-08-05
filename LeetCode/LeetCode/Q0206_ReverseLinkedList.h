#pragma once

#include "DebugUtils.h"
#include "ListNode.h"

#pragma region iteration
//class Solution {
//public:
//	ListNode * reverseList(ListNode* head) {
//		ListNode *node1 = head, *node2, *node3;
//
//		node2 = (node1 == NULL) ? NULL : node1->next;
//		node3 = (node2 == NULL) ? NULL : node2->next;
//
//		if (node1!=NULL) 
//			node1->next = NULL;
//
//		while (node2 != NULL)
//		{
//			node2->next = node1;
//			node1 = node2;
//			node2 = node3;
//			node3 = (node3 == NULL) ? NULL : node3->next;
//		}
//		head = node1;
//		return head;
//
//	}
//};
#pragma endregion

#pragma region iteration_concise_ver
//class Solution {
//public:
//	ListNode * reverseList(ListNode* head) {		
//		ListNode *prev = NULL, *cur=head, *next=NULL;
//		while (cur != NULL)
//		{
//			next = cur->next;
//			cur->next = prev;
//			prev = cur;
//			cur = next;
//		}		
//		return prev;
//	}
//};
#pragma endregion

#pragma region recursion
//class Solution {
//private:
//	ListNode** do_reverse(ListNode* head, ListNode** ans)
//	{
//		if (head->next == NULL)
//		{
//			*ans = head;
//			return &head->next;
//		}
//
//		ListNode **headnext = do_reverse(head->next, ans);
//		*headnext = head;
//		return &head->next;
//	}
//public:
//	ListNode * reverseList(ListNode* head) {
//		if (head == NULL) return NULL;
//		ListNode *ans;
//		ListNode **headnext = do_reverse(head, &ans);		
//		*headnext = NULL;
//
//		return ans;
//	}
//};
#pragma endregion

#pragma region recursion_concise_ver
class Solution {
private:
	ListNode* do_reverse(ListNode* cur, ListNode* new_next)
	{
		if (cur == NULL)					
			return new_next;
		
		ListNode *next = cur->next;
		cur->next = new_next;
		return do_reverse(next, cur);
	}
public:
	ListNode * reverseList(ListNode* head) {
		return do_reverse(head, NULL);
	}
};
#pragma endregion

void q0206_tester()
{
	Solution s;

	vector<int> qv;
	ListNode* ans;

	qv = { 1,2,3,4,5 };
	ListNode *q = ListNode::genListHead(qv);
	ans = s.reverseList(q);
	ListNode::printList(ans);

	qv = { 1,2 };
	q = ListNode::genListHead(qv);
	ans = s.reverseList(q);
	ListNode::printList(ans);

	qv = { 1 };
	q = ListNode::genListHead(qv);
	ans = s.reverseList(q);
	ListNode::printList(ans);
}
