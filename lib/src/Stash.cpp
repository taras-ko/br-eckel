#include <iostream>
#include <cassert>
#include <cstring>

#include <Mem.h>
#include <Stash.h>
#include <require.h>

using namespace std;

// Quantity of elements to add
// when increasing storage:
const int increment = 100;

Stash::Stash(int sz, int initQuantity)
	: size(sz), quantity(initQuantity)
{
	next = 0;
	storage = new Mem(size * initQuantity);
}

int Stash::add(const void *element)
{
	if (next >= quantity)
		inflate(increment);

	int startBytes = next * size;

	memcpy((void *) (storage->pointer() + startBytes), element, size);

	next++;
	return (next - 1);
}

void *Stash::fetch(int index)
{
	require(0 <= index, "Stash::fetch (-)index");
	if (index >= next)
		return 0;
	return storage->pointer() + index * size;
}

int Stash::count()
{
	return next; // Elements in Stash
}

void Stash::inflate(int increase)
{
	assert(increase > 0);

	if (increase == 0)
		return;

	int newQuantity = quantity + increase;
	storage->pointer(size * newQuantity);

	quantity = newQuantity;
}

Stash::~Stash()
{
	if (size != 0) {
		cout << "freeing storage" << endl;
		delete storage;
	}
} ///:~

