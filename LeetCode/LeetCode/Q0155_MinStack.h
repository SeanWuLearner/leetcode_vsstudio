#pragma once

#include "DebugUtils.h"
#include <stack>

class MinStack {
private:
	stack<int> stk;
	stack<int> min;

public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		stk.push(x);
		if (min.empty() == true || min.top() > x)
			min.push(x);
		else
			min.push(min.top());
	}

	void pop() {
		stk.pop();
		min.pop();
	}

	int top() {
		if (stk.empty() == true)
			return 0;
		return stk.top();
	}

	int getMin() {
		if (min.empty() == true)
			return 0;
		return min.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/


void q0155_tester()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;   //--> Returns - 3.
	minStack.pop();
	cout << minStack.top() << endl;      //--> Returns 0.
	cout << minStack.getMin() << endl;   //--> Returns - 2.
}
