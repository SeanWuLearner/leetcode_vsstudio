#pragma once

#include "DebugUtils.h"
#include <iomanip>
#include <stack>

#pragma region TailRecursionToIteration
static int tailRecursion(int m, int n)
{
	if (m == 0 || n == 0)
		return 1;
	else
		return 2 * tailRecursion(m - 1, n + 1);
}

static int tailRecursion_2iterative(int m, int n)
{
	int ret_val = 1;
	while (m != 0 && n != 0)
	{
		ret_val *= 2;
		m--;
		n++;
	}
	return ret_val;
}

void test_tail_recursion()
{
	for (int i = 0; i <= 5; i++)
		for (int j = -5; j <= 0; j++)
			cout << "give(i=" << i << ", j=" << j << "), get=" << tailRecursion(i, j) << ", iter=" << tailRecursion_2iterative(i, j) << endl;
}
#pragma endregion

#pragma region RecursionToIteration_BinomialCoefficients

static int comb_recur(int n, int m, int level)
{
	//cout << "comb_recur(" << n << "," << m << "), level ="<<level << endl;
	int ret_val;
	if (n == 1 || m == 0 || n == m)
		ret_val = 1;
	else
		ret_val = comb_recur(n - 1, m, level+1) + comb_recur(n - 1, m - 1, level+1);
	/* *** seperate recusive sentence into more detail.
		val1 = comb_recur(n-1, m);
		val2 = comb_recur(n-1, m-1);
		ret_val = val1 + val2;
	*/
	return ret_val;
}

#pragma region StackManner
class CombStk_IF {
public:
	virtual void CmdHandler(stack<shared_ptr<CombStk_IF>> &stk) = 0;
};

class CombStk_Resume : public CombStk_IF {
private:
	shared_ptr<int> l_;
	shared_ptr<int> r_;
	shared_ptr<int> ret_;

public:
	CombStk_Resume(shared_ptr<int> ret) :
		ret_(ret)
	{
		l_ = make_shared<int>();
		r_ = make_shared<int>();
	}
	virtual void CmdHandler(stack<shared_ptr<CombStk_IF>> &stk) override
	{
		if (ret_ && l_ && r_)
		{
			*ret_ = *l_ + *r_;
			//cout << "resume: ret=" << *ret_ << endl;
		}
		else
			cout << "Warning: nullptr in CmdHandler of resume_obj" << endl;
	}

	shared_ptr<int> &get_l() { return l_; }
	shared_ptr<int> &get_r() { return r_; }
};

class CombStk_Call : public CombStk_IF {
private:
	int n_;
	int m_;	
	shared_ptr<int> ret_;

public:
	CombStk_Call(int n, int m, shared_ptr<int> ret) :m_(m), n_(n), ret_(ret) {}

	virtual void CmdHandler(stack<shared_ptr<CombStk_IF>> &stk) override
	{

		if (n_ == 1 || m_ == 0 || n_ == m_)
			*ret_ = 1;
		else
		{
			//cout << "call: (n,m)=(" << n_ << "," << m_ << endl;
			shared_ptr<CombStk_Resume> resume = make_shared<CombStk_Resume>(ret_);
			stk.push(resume);
			stk.push(make_shared<CombStk_Call>(n_ - 1, m_, resume->get_l()));
			stk.push(make_shared<CombStk_Call>(n_ - 1, m_ - 1, resume->get_r()));
		}
	}
};

static int comb_iter_stack(int n, int m)
{
	shared_ptr<int> ret{ new int{0} };
	stack<shared_ptr<CombStk_IF>> stk;
	shared_ptr<CombStk_IF> node;
	stk.push(make_shared<CombStk_Call>(n, m, ret));
	
	while (stk.empty() == false) 
	{
		node = stk.top();
		stk.pop();
		node->CmdHandler(stk);
	}
	return *ret;
}
#pragma endregion

#pragma region DynamicProgramming_BottomUpManner

int comb_iter_dp(int n, int m)
{
	return 0;//TODO
}

#pragma endregion

void test_comb_pascal_triangle()
{	
	cout << "Pascal's triangle by recursion:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << setw(4) << comb_recur(i, j, 0);
		cout << endl;
	}

	cout << "Pascal's triangle by iteration:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << setw(4) << comb_iter_stack(i, j);
		cout << endl;
	}
}

#pragma endregion
