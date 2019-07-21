#pragma once

#include "DebugUtils.h"

class Solution {
private:
	vector<int> array_;
	vector<int> orig_;

public:
	Solution(vector<int>& nums) {
		orig_ = array_ = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		array_ = orig_;
		return array_;
	}

	/** Returns a random shuffling of the array. */
#pragma region imitate_Fisher-Yates Algorithm
	//vector<int> shuffle() {		
	//	for (int i = 0; i < array_.size(); i++)
	//	{
	//		int ridx = rand() % (array_.size() - i) + i;
	//		std::swap(array_[i], array_[ridx]);
	//	}
	//	return array_;
	//}
#pragma endregion

#pragma region Fisher-Yates Algorithm with better efficiency
	vector<int> shuffle() {
		for (int i = array_.size() - 1; i > 0; i--)
		{
			std::swap(array_[i], array_[rand() % (i + 1)]);
		}
		return array_;
	}
#pragma endregion

};


/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* vector<int> param_1 = obj->reset();
* vector<int> param_2 = obj->shuffle();
*/

void q0384_tester()
{
	vector<int> n{ 1, 2, 3 };
	Solution s(n);

	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());

	cout << "perform the reset" << endl;
	print(s.reset());
	print(s.shuffle());
	print(s.shuffle());
	print(s.shuffle());

}

