#include <Stack.h>
#include <require.h>

using namespace std;

Stack::Link::Link(void* dat, Link* nxt) {
	data = dat;
	next = nxt;
}

Stack::Link::~Link() { }

Stack::Stack() { head = 0; }

Stack::~Stack() {
	require(head == 0, "Stack not empty");
}

void Stack::push(void* dat) {
	Link* newLink = new Link(dat, head);
	head = newLink;
}

void* Stack::peek() {
	require(head != 0, "Stack empty");
	return head->data;
}

void* Stack::pop() {
	if(head == 0) return 0;
		void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

void Stack::reverse() {
	Link *prev, *current, *next;

	prev = 0;
	current = head;
	next = current->next;

	while (next != 0) {
		current->next = prev;
		prev = current;
		current = next;
		next = current->next;
	}

	head = current;
	head->next = prev;
}

