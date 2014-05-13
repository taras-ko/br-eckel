#include <iostream>
#include <cassert>

#include <Stash.h>

using namespace std;

// Quantity of elements to add
// when increasing storage:
const int increment = 100;

Stash::Stash(int sz)
{
	size = sz;
	quantity = 0;
	storage = new vector<unsigned char>(0);
	next = 0;
}

int Stash::add(const void* element)
{
	unsigned char *e = (unsigned char *) element;
	for (int i = 0; i < size; i++)
		storage->push_back(e[i]);

	next++;
	return next - 1; // Index number
}

void* Stash::fetch(int index)
{
	// Check index boundaries:
	assert(0 <= index);
	if (index >= next)
		return 0; // To indicate the end

	// Produce pointer to desired element:
	return &(storage->at(index * size));
}

int Stash::count()
{
	return next; // Elements in Stash
}

Stash::~Stash()
{
	if (storage->size() != 0) {
		cout << "freeing storage" << endl;
		delete storage;
	}
} ///:~

