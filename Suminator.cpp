#include "Suminator.h"
#include <stack>

class CItem
{
public:
	CItem(long long n, bool bVariableAdd = false) {this->n = n; this->bVariableAdd = bVariableAdd;}
	
	CItem& operator + (CItem& item) 
	{
		n += item.n;
		bVariableAdd = (bVariableAdd || item.bVariableAdd);
		return *this;
	}

	bool IsZero() {return (n == 0) && !bVariableAdd;}

	long long n;
	bool bVariableAdd;
};

class CStack
{
public:
	void Push(CItem v) 
	{ 
		if(v.IsZero())
		{
			S.push(Pop() + Pop());
		}
		else
		{
			S.push(v); 
		}
	};

	CItem Top() 
	{
		if(S.empty()) {return NULL;}
		
		return S.top();
	};

private:
	CItem Pop()
	{
		if(S.empty()) 
		{
			return CItem(0);
		}

		CItem n = S.top();
		S.pop();
		return n;
	}

private:
	stack<CItem> S;
};


Suminator::Suminator(void)
{
}


Suminator::~Suminator(void)
{
}

int Suminator::findMissing(vector<int> program, int wantedResult)
{
	CStack stack;
	int pos = 0; // pos of -1

	for(int i = 0; i < program.size(); ++i)
	{
		if(program[i] == -1)
		{
			pos = i;
			stack.Push(CItem(0));
		}
		else
		{
			stack.Push(CItem(program[i]));
		}
	}

	if(stack.Top().n == wantedResult) {return 0;}

	CStack stack2;
	for(int i = 0; i < pos; ++i)
	{
		stack2.Push(CItem(program[i]));
	}

	stack2.Push(CItem(0, true));
	for(int i = pos + 1; i < program.size(); ++i)
	{
		stack2.Push(CItem(program[i]));
	}

	CItem item = stack2.Top();

	if(item.bVariableAdd)
	{
		return (item.n >= wantedResult) ? -1 : wantedResult - item.n;
	}
	else
	{
		return (item.n == wantedResult) ? 1 : -1;
	}
}