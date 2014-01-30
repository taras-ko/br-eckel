#ifndef STACK_H
#define STACK_H
class Stack {
	struct Link {
		void* data;
		Link* next;
		Link(void* dat, Link* nxt);
		~Link();
	}* head;
public:
	Stack();
	Stack(void **, int size);
	~Stack();
	void push(void* dat);
	void* peek();
	void* pop();
	void reverse();
};
#endif // STACK_H ///:~
