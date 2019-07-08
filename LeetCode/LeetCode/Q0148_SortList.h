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

#pragma region recursive_merge_sort 
//it use O(logN) mem actually
//class Solution {
//private:
//
//	ListNode* merge(ListNode* l1, ListNode* l2)
//	{
//		//fastest submission on leetcode
//		if (l1 == NULL) return l2;
//		if (l2 == NULL) return l1;
//
//		if (l1->val < l2->val)
//		{
//			l1->next = merge(l1->next, l2);
//			return l1;
//		}
//		else
//		{
//			l2->next = merge(l1, l2->next);
//			return l2;
//		}
//
//
//#if 0 //slower one
//		ListNode *res, *cur;
//		cur = res = new ListNode(0);
//
//		while (l1 != NULL && l2 != NULL)
//		{
//			if (l1->val < l2->val)
//			{
//				cur->next = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				cur->next = l2;
//				l2 = l2->next;
//			}
//			cur = cur->next;
//		}
//
//		if(l1 != NULL)
//			cur->next = l1;
//		if (l2 != NULL)
//			cur->next = l2; 
//
//		cur = res;
//		res = res->next;
//		delete cur;
//		return res;
//#endif
//	}
//
//public:
//	ListNode* sortList(ListNode* head) {				
//
//		if (head == NULL || head->next == NULL) //basic case
//			return head;
//
//		ListNode *fast, *slow, *prev_slow=NULL;
//		fast = slow = head;		
//
//		while (fast != NULL && fast->next != NULL)
//		{
//			prev_slow = slow;
//			slow = slow->next;
//			fast = fast->next->next;
//		}		
//		prev_slow->next = NULL; //cut in half
//
//		return merge(sortList(head), sortList(slow));						
//	}
//};
#pragma endregion

#pragma region iterative_const_mem_consumption_on_leetcode
///**
//* Merge sort use bottom-up policy,
//* so Space Complexity is O(1)
//* Time Complexity is O(NlgN)
//* stable sort
//*/
//class Solution {
//public:
//	ListNode *sortList(ListNode *head) {
//		if (!head || !(head->next)) return head;
//
//		//get the linked list's length
//		ListNode* cur = head;
//		int length = 0;
//		while (cur){
//			length++;
//			cur = cur->next;
//		}
//
//		ListNode dummy(0);
//		dummy.next = head;
//		ListNode *left, *right, *tail;
//		for (int step = 1; step < length; step <<= 1){
//			cur = dummy.next;
//			tail = &dummy;
//			while (cur){
//				left = cur;
//				right = split(left, step);
//				cur = split(right, step);
//				tail = merge(left, right, tail);
//			}
//		}
//		return dummy.next;
//	}
//private:
//	/**
//	* Divide the linked list into two lists,
//	* while the first list contains first n ndoes
//	* return the second list's head
//	*/
//	ListNode* split(ListNode *head, int n){
//		//if(!head) return NULL;
//		for (int i = 1; head && i < n; i++) head = head->next;
//
//		if (!head) return NULL;
//		ListNode *second = head->next;
//		head->next = NULL;
//		return second;
//	}
//	/**
//	* merge the two sorted linked list l1 and l2,
//	* then append the merged sorted linked list to the node head
//	* return the tail of the merged sorted linked list
//	*/
//	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
//		ListNode *cur = head;
//		while (l1 && l2){
//			if (l1->val > l2->val){
//				cur->next = l2;
//				cur = l2;
//				l2 = l2->next;
//			}
//			else{
//				cur->next = l1;
//				cur = l1;
//				l1 = l1->next;
//			}
//		}
//		cur->next = (l1 ? l1 : l2);
//		while (cur->next) cur = cur->next;
//		return cur;
//	}
//};
#pragma endregion

#pragma region sean_rephrase_iterative_merge_sort
class Solution {
public:
	ListNode * sortList(ListNode* head)
	{
		int len = 0;
		ListNode* dummy = head;
		//count len
		while (dummy != NULL)
		{
			len++;
			dummy = dummy->next;
		}

		//create a fixed head		
		dummy = new ListNode(0);
		dummy->next = head;

		ListNode *prev, *l1, *l2, *tail;
		for (int step = 1; step < len; step <<= 1)
		{
			prev = dummy->next;
			tail = dummy;
			while (prev != NULL) //while not stepping to the end of list
			{
				l1 = prev;
				l2 = split(l1, step);
				prev = split(l2, step);
				tail = merge(l1, l2, tail);
			}
		}

		head = dummy->next;
		delete dummy;
		return head;
	}
private:
	ListNode * split(ListNode* l, int step)
	{
		while (l != NULL && (--step) >= 1)	 //leave the last element to be cut
			l = l->next;

		if (l == NULL) return NULL;

		ListNode *ret = l;
		ret = ret->next;
		l->next = NULL; //cut the list
		return ret;
	}

	//return the next prev, which would be the last element of the merged list.
	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev)
	{
		ListNode *now = prev;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				now->next = l1;
				l1 = l1->next;
			}
			else
			{
				now->next = l2;
				l2 = l2->next;
			}
			now = now->next;
		}

		if (l1 != NULL)
			now->next = l1;
		else if (l2 != NULL)
			now->next = l2;

		//prepare the return node;
		while (now->next != NULL)
			now = now->next;
		return now;
	}
};
#pragma endregion

void q0148_tester()
{
	Solution s;
	vector<int> q;
	ListNode *head;

	q = { 4, 2, 1, 3 };
	head = ListNode::genListHead(q, -1);
	head = s.sortList(head);
	ListNode::printList(head); //expect 1->2->3->4

	q = { -1, 5, 3, 4, 0 };
	head = ListNode::genListHead(q, -1);
	head = s.sortList(head);
	ListNode::printList(head); //expect -1->0->3->4->5

}
