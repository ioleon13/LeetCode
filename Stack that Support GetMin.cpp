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

