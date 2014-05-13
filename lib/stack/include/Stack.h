#include <require.h>

#ifndef STACK_H
#define STACK_H
class Stack {
	struct Link {
		void* data;
		Link* next;
		Link(void* dat, Link* nxt) : data(dat), next(nxt) {}
	}* head;
public:
	Stack() : head(NULL) {}
	Stack(void **, int size);
	~Stack() {
		require(head == 0, "Stack not empty");
	}
	void push(void* dat) {
		head = new Link(dat, head);
	}
	void* peek() const {
		return head ? head->data : 0;
	}
	void* pop() {
		if (head == 0) return 0;
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
	void reverse();
};
#endif // STACK_H ///:~
