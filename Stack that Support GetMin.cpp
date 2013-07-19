#include <iostream>
#include <stack>
using namespace std;


class CMinStack{
public:
	void push(const int& item);
	int pop();
	int getTop() const {return curStack.empty() ? -1 : curStack.top();}
	int getMin() const {return minStack.empty() ? INT_MAX : minStack.top();}
private:
	stack<int> minStack;
	stack<int> curStack;

};

void CMinStack::push(const int& item)
{
	int min = getMin();
	if(item <= min)
		minStack.push(item);
	curStack.push(item);

}

int CMinStack::pop()
{
	int top = getTop();
	if(top == -1)
		return -1;
	if(top == getMin())
		minStack.pop();
	curStack.pop();
	return top;
}

class CMinStackBetter{
public:
	CMinStackBetter() : minVal(INT_MAX) {}
	int getMin() const {return minVal;}
	void push(const int& item);
	int pop();
private:
	stack<int> sta;
	int minVal;
};


void CMinStackBetter::push(const int& item)
{
	if(sta.empty())
	{
		sta.push(item);
		minVal = item;
		return;
	}
	if(item >= minVal)
	{
		sta.push(item);
		return;
	}
	int val = 2*item - minVal;
	sta.push(val);
	minVal = item;

}

int CMinStackBetter::pop()
{
	if(sta.empty())
		return -1;
	int top = sta.top();
	if(top >= minVal)
	{
		sta.pop();
		return top;
	}
	int preMin = 2*minVal - top;
	sta.pop();
	top = minVal;
	minVal = preMin;
	return top;
}