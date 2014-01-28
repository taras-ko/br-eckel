#include <iostream>

#include "StackOfInt.h"
#include "StackImp2.h"

using namespace std;

StackOfInt::StackOfInt()
{
	pStack = new StackImp;
}

StackOfInt::~StackOfInt()
{
	delete pStack;
}

void StackOfInt::push(int i)
{
	pStack->push(i);
}

int StackOfInt::pop()
{
	pStack->pop();
}

int main()
{
	StackOfInt stack;

	for (int i = 0; i < 30; i++)
		stack.push(i);

	for (int i = 0; i < 30; i++)
		cout << stack.pop() << endl;
}
