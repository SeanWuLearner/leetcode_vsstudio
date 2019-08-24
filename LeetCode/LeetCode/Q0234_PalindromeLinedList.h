#pragma once

#include "DebugUtils.h"

#pragma region my_ans
//#include "ListNode.h"
//class Solution {
//public:
//	bool isPalindrome(ListNode* head) {
//		int n = 0;
//
//		//count the length of list
//		ListNode *cur, *prev, *next;
//		for (cur = head; cur != NULL; cur = cur->next, n++);
//
//		//reverse the first half
//		int half = n / 2;
//		prev = NULL;
//		cur = head;
//		next = (head == NULL) ? NULL : head->next;
//		while (half--)
//		{
//			cur->next = prev;
//			prev = cur;
//			cur = next;
//			next = next->next;
//		}
//		ListNode *lhs = prev;
//		ListNode *rhs;
//
//		if (n % 2) //odd
//			rhs = (cur == NULL) ? NULL : cur->next;
//		else //even
//			rhs = cur;
//
//		//check if plindrome
//		half = n / 2;
//		while (half--)
//		{
//			if (lhs->val != rhs->val)
//				return false;
//			lhs = lhs->next;
//			rhs = rhs->next;
//		}
//		return true;
//	}
//};
#pragma endregion

#pragma region two_phase_ans
/* phase 1: reverse the 1st half while finding the middle
phase 2: compare the reversed fisrt with second half*/
#include "ListNode.h"
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *rev = NULL;
		ListNode *slow = head, *fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			ListNode *tmp = rev;
			rev = slow;
			slow = slow->next;
			rev->next = tmp;
		}
		if (fast != NULL) //odd case, move one more step of rhs
			slow = slow->next;
		while (slow != NULL)
		{
			if (slow->val != rev->val)
				return false;
			slow = slow->next;
			rev = rev->next;
		}

		return true;
	}
};
#pragma endregion

void q0234_tester()
{
	Solution s;
	vector<int> q;
	ListNode *head;

	q = { 1, 2 };
	head = ListNode::genListHead(q);
	cout << s.isPalindrome(head) << endl; // return false


	q = { 1, 2, 2, 1 };
	head = ListNode::genListHead(q);
	cout << s.isPalindrome(head) << endl; // return true





}
