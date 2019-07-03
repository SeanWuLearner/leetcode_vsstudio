#pragma once

#include "DebugUtils.h"


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next = NULL, Node* _random = NULL) {
		val = _val;
		next = _next;
		random = _random;
	}
};

#pragma region map_cache_method
//#include <unordered_map>
//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		if (head == NULL)
//			return NULL;
//
//		unordered_map<Node*, Node*> cache;  //<orig, new>
//
//		//pass1 clone all the node but random pointer AND build the map
//		Node *now = head;
//		Node *clone_head = NULL, *clone_now, *clone_prev = NULL;
//		while (now != NULL)
//		{
//			clone_now = new Node(0, NULL, NULL);					
//			clone_now->val = now->val;
//			if (clone_prev != NULL)			
//				clone_prev->next = clone_now;			
//			else
//				clone_head = clone_now;
//
//			cache[now] = clone_now;
//
//			//forward
//			clone_prev = clone_now;			
//			now = now->next;
//		}
//
//		//pass 2 : link the random ptr
//		now = head;
//		clone_now = clone_head;
//		while (now != NULL)
//		{
//			if (now->random != NULL)
//			{
//				clone_now->random = cache[now->random];
//			}
//
//			//forward
//			now = now->next;
//			clone_now = clone_now->next;
//		}
//
//		return clone_head;
//	}
//};
#pragma endregion


#pragma region solution_without_map
/*Interweave the copied node into original nodes, and this would form
a natural map for us. But it still need 2-pass in case the random
ptr point to the node which haven't been cloned.
*/

class Solution {
public:
	Node * copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptr;

		//pass 1: insert clone nodes
		Node *now = head;
		Node *clone_now;
		while (now != nullptr)
		{
			clone_now = new Node(now->val, now->next, NULL);
			now->next = clone_now;
			now = clone_now->next;
		}

		//pass 2: fill random ptr
		now = head;
		clone_now = now->next;
		while (now != nullptr)
		{
			if (now->random == nullptr)
				clone_now->random = nullptr;
			else
				clone_now->random = now->random->next;

			now = clone_now->next;
			if (now == nullptr)
				break;
			else
				clone_now = now->next;
		}

		//pass 3: form the answer list
		Node *ret;
		ret = clone_now = head->next;
		now = head;
		while (clone_now->next != nullptr)
		{
			now->next = clone_now->next;
			clone_now->next = clone_now->next->next;

			now = now->next;
			if (clone_now->next == nullptr)
				break;
			else
				clone_now = clone_now->next;
		}
		now->next = nullptr; //make the ori->next equal to clone->next
		return ret;
	}
};

#pragma endregion


#pragma region fastest_solution_on_leetcode
//#include <unordered_map>
//class Solution {
//public:
//	typedef Node*ptr;
//	unordered_map<ptr, ptr>mm;
//
//	ptr bhejo(ptr t)
//	{
//		if (t == NULL)
//			return NULL;
//		else
//		{
//			if (mm.find(t) == mm.end())
//			{
//				mm[t] = new Node(t->val, NULL, NULL);
//			}
//			return mm[t];
//
//		}
//	}
//
//	Node* copyRandomList(Node* head) {
//		ptr h = head;
//		while (h != NULL)
//		{
//			ptr n = bhejo(h);
//			n->next = bhejo(h->next);
//			n->random = bhejo(h->random);
//			h = h->next;
//		}
//		return mm[head];
//	}
//};
#pragma endregion

void q0138_tester()
{
	Solution s;
	Node* ans;
	Node* head;
	Node* node1;
	Node* node2;

	node1 = new Node(1);
	node2 = new Node(2);
	node1->next = node2;
	node1->random = node2;
	node2->random = node2;
	head = node1;

	ans = s.copyRandomList(head);
}
