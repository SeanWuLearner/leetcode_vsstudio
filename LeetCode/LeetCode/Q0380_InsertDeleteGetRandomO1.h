#pragma once

#include "DebugUtils.h"

#include <unordered_map>
class RandomizedSet {
private:
	unordered_map<int, int> stor_m; //val, idx to stor_v
	vector<int> stor_v;

public:
	/** Initialize your data structure here. */
	RandomizedSet() {
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (stor_m.count(val) != 0)
			return false;
		else
		{
			stor_m.emplace(val, stor_v.size());
			stor_v.push_back(val);
			return true;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (stor_m.count(val) == 0)
			return false;

		//swap the target idx to the last bucket in vector
		int idx = stor_m[val];
		if (idx != stor_v.size() - 1)
		{
			stor_v[idx] = stor_v.back();
			stor_m[stor_v.back()] = idx;
		}
		stor_v.pop_back();
		stor_m.erase(val);

		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return stor_v[rand() % stor_v.size()];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet* obj = new RandomizedSet();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/

void q0380_tester()
{

	RandomizedSet* obj = new RandomizedSet();
	cout << obj->insert(1) << endl;  //true, [1]
	cout << obj->remove(2) << endl;  //false, not 2
	cout << obj->insert(2) << endl;  //true, [1,2]
	cout << obj->getRandom() << endl; //return 1 or 2
	cout << obj->remove(1) << endl; //true, [2]
	cout << obj->insert(2) << endl; //false; alread in set.

	cout << "random test" << endl;
	cout << obj->insert(1) << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	delete obj;
}
