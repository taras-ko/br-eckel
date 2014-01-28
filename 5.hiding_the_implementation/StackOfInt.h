#ifndef STACKOFINT_H
#define STACKOFINT_H
class StackOfInt {
	class StackImp;
	StackImp *pStack;
public:
	StackOfInt();
	~StackOfInt();
	void cleanup();
	void push(int);
	int pop();
};
#endif // STACKOFINT_H
