#pragma once

#include "DebugUtils.h"

#pragma region pointer_array
//sean: actually this manner cost more mem.
class Trie {
private:
	class Node {
	public:
		Node * next_[26];
		bool end_of_word_;

		Node()
		{
			end_of_word_ = false;
			memset(next_, 0, sizeof(next_));
		}
	} *root;

public:
	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}

	Node* locateMostMatchNode(string word, int& end_idx)
	{
		Node* cur = root;
		int i;
		for (i = 0; i < word.size(); i++)
		{
			int c_idx = word[i] - 'a';
			if (cur->next_[c_idx] == NULL)
				break;
			cur = cur->next_[c_idx];
		}
		end_idx = i;
		return cur;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		int i;
		Node* cur = locateMostMatchNode(word, i);

		for (; i < word.size(); i++)
		{
			Node* next = new Node();
			int c_idx = word[i] - 'a';
			cur->next_[c_idx] = next;
			cur = next;
		}

		cur->end_of_word_ = true;
		return;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		int i;
		Node* cur = locateMostMatchNode(word, i);

		if (i == word.size() && cur->end_of_word_ == true)
			return true;
		else
			return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int i;
		Node* cur = locateMostMatchNode(prefix, i);

		if (i == prefix.size())
			return true;
		else
			return false;
	}
};
#pragma endregion

#pragma region hash_map_manner
//#include <unordered_map>
//class Trie {
//private:
//	class Node{	
//	public:
//		char c_;
//		unordered_map<char, Node*> next_;
//		bool end_of_word_;
//		
//		Node(char c = '*') :c_(c){ end_of_word_ = false; }
//	} *root;
//	
//public:
//	/** Initialize your data structure here. */
//	Trie() {
//		root = new Node();		
//	}
//
//	Node* locateMostMatchNode(string word, int& end_idx)
//	{
//		Node* cur = root;
//		int i;
//		for (i = 0; i < word.size(); i++)
//		{
//			auto it = cur->next_.find(word[i]);
//			if (it == cur->next_.end())
//				break;
//			cur = it->second;
//		}
//		end_idx = i;
//		return cur;
//	}
//
//	/** Inserts a word into the trie. */
//	void insert(string word) {
//		int i;
//		Node* cur = locateMostMatchNode(word, i);
//
//		for (; i < word.size(); i++)
//		{
//			Node* next = new Node(word[i]);
//			cur->next_.insert({ word[i], next });
//			cur = next;
//		}
//		
//		cur->end_of_word_ = true;
//		return;
//	}
//
//	/** Returns if the word is in the trie. */
//	bool search(string word) {
//		int i;
//		Node* cur = locateMostMatchNode(word, i);
//
//		if (i == word.size() && cur->end_of_word_ == true)
//			return true;
//		else
//			return false;
//	}
//
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix) {
//		int i;
//		Node* cur = locateMostMatchNode(prefix, i);
//
//		if (i == prefix.size())
//			return true;
//		else
//			return false;
//	}
//};
#pragma endregion

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/


void q0208_tester()
{
	Trie* obj = new Trie();
	obj->insert("apple");
	cout << obj->search("apple") << endl; //true
	cout << obj->search("app") << endl; //fail

	cout << obj->startsWith("app") << endl; //true
	obj->insert("app");
	cout << obj->search("app") << endl; //true

}
