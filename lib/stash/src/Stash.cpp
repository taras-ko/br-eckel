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

int Stash::add(const void *element)
{
	if (next >= quantity)
		inflate(increment);

	int startBytes = next * size;

	memcpy((void *) (storage->pointer() + startBytes), element, size);

	next++;
	return (next - 1);
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
