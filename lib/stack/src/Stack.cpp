#include <Stack.h>
#include <require.h>
#include <iostream>

using namespace std;

Stack::Stack(void **ptrs, int size) : head(NULL)
{
	for (int i = 0; i < size / sizeof(*ptrs); i++)
		push(ptrs[i]);
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

